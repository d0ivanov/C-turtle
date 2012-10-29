#!/usr/bin/env ruby

#school - ТУЕС
#class - 11Б
#num - 15
#name - Добромир Иванов
#task -Да се създаде доклад в изходен CSV файл, който да съдържа следната информация:
#Клас, номер, име, поща, колан
#“номер на домашно”, “заглавие на домашното”, “краен срок”, “дата на предаване”, “предадено ли е на време”, “връзки към решените задачи”

require "csv"
require "date"
require "time"

class Student

  attr_accessor :clas, :num, :name, :mail, :belt, :tasks
  
  def initialize
    @tasks = Array.new(10){Task.new}
  end
  
  def Student.parse_clas(clas)
    clas = clas.delete("0-9 XI-")
	clas = "А" if clas.index('a') != nil ||	clas.index('A') != nil || clas.index('а') != nil
	clas = "Б" if clas.index('b') != nil || clas.index('B') != nil || clas.index('б') != nil
	return clas
  end
  
  def parse_names
  	names_raw = get_names
  	names_parsed = []
  	names_raw.each do |name|
  		name = name.delete("0-9A-Za-z")
        names_parsed.push name if name.count(" ") == 2 && name.delete(" ").length > 0
  	end
  	names_parsed = names_parsed.uniq
  	return names_parsed
  end
    
  def Student.parse_num(num)
    return num if /^[0-9]+$/.match(num)
    return nil
  end
  
  def get_names
  	names = []
    Task.get_files.each do |file|
    	CSV.foreach(file) do |row|
      		name = row[3].to_s
      		names.push name
      	end
    end
    return names
  end
  
  def Student.find_key(students, value)
	i = 0
	students.each do |student|
		return i if student.name == value
		i+=1
	end
	return nil
  end
  
end

class Task
	
  attr_accessor :num, :name, :deadline, :handed_in, :links, :in_time

  def Task.in_time?(time_handed, deadline)
	handed = Date.parse(time_handed)
 	term = Date.parse(deadline)
 	return true if term > handed
 	return false 
  end
  
  def Task.get_tasks
  	tasks = []
    CSV.foreach("tasks.csv") do |row|
      task = Task.new
      task.num = row[0]
      task.name = row[1]
      task.deadline = row[2]
      tasks.push(task)
    end
    return tasks
  end
  
  def Task.get_files
  	files = Dir.glob("*.csv");
  	files.delete_if{|file| file == "tasks.csv" || file == "results.csv"}
  	return files
  end
  
  def Task.get_num(name)
  	return name.delete("a-z.").to_i if name.delete("a-z.").length > 0
  	return nil
  end
  
end


students = []
parsed_names = Student.new.parse_names
tasks = Task.get_tasks
for i in 0...parsed_names.count
	student = Student.new
	student.name = parsed_names[i]
	students.push(student)
end
Task.get_files.each do |file|
	CSV.foreach(file) do |row|
		i = Student.find_key(students, row[3])
		if i != nil
			students[i].clas = Student.parse_clas(row[1])
			students[i].num = Student.parse_num(row[2])
			students[i].mail = row[4].to_s
			students[i].belt = "Жълт" if file =="exam.csv" && (row[9].downcase == "да")
			students[i].belt = "Бял" if file == "exam.csv" && (row[9].downcase != "да")
			if (task = Task.get_num(file)) != nil
				students[i].tasks[task-1].num = tasks[task-1].num
				students[i].tasks[task-1].name = tasks[task-1].name
				students[i].tasks[task-1].deadline = tasks[task-1].deadline
				students[i].tasks[task-1].handed_in = row[0]
				#students[i].tasks[task-1].in_time = "Да" if Task.in_time?(row[0].to_s, tasks[task-1].deadline.to_s)
				#students[i].tasks[task-1].in_time = "Не" if !Task.in_time?(row[0].to_s, tasks[task-1].deadline.to_s)
				students[i].tasks[task-1].links = row[5] if task != 1 && task != 7
				students[i].tasks[task-1].links = row[5].to_s+" "+row[8].to_s if task == 7
				
			end
		end
	end
end

csv = CSV.open("Tasks.csv", "w")

csv << ["Клас", "номер", "име", "поща", "колан", "номер на домашно", "заглавие на домашното", "краен срок, дата на предаване", "предадено ли е на време", "връзки към решените задачи"]
students.each do |student|
  csv << [student.clas, student.num, student.name, student.mail, student.belt]
  student.tasks.each do |task|
  	csv << [task.num, task.name, task.deadline, task.in_time, task.links]	
  end
end
