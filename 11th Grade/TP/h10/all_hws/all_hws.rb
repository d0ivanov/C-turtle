require 'csv'
require 'date'
require 'time'

#Клас, номер, име, поща, колан
#“номер на домашно”, “заглавие на домашното”, “краен срок”, “дата на предаване”, “предадено ли е на време”, “връзки към решените задачи”
#номер на домашното, заглавие на домашното, краен срок, дата на предаване, предадено ли е на време, връзка1, връзка2, връзкаN
#-

#Клас, номер, име, поща, колан
#“номер на домашно”, “заглавие на домашното”, “краен срок”, “дата на предаване”, “предадено ли е на време”, “връзки към решените задачи”
#номер на домашното, заглавие на домашното, краен срок, дата на предаване, предадено ли е на време, връзка1, връзка2, връзкаN

class Student
	@clas = ""
	@number = 0
	@name = ""
	@email = ""
	@belt = "white"
	@repo = ""
	
	def getClas
		return @clas
	end
	
	def getNumber
		return @number
	end
	
	def getName
		return @name
	end
	
	def getEmail
		return @email
	end
	
	def getBelt
		return @belt
	end
	
	def setClas(val)
		@clas = val
	end
	
	def setNumber(val)
		@number = val
	end
	
	def setName(val)
		@name = val
	end
	
	def setEmail(val)
		@email = val
	end
	
	def setBelt(val)
		@belt = val
	end
	
	def setRepo(val)	
		@repo = val
	end
	
	def getRepo()
		return @repo
	end
	
	def dump
		print @clas, " ", @number, " ", @name, " ", @email, "\n"
	end
	
	def dump!
		puts
		print @clas, " ", @number, " ", @name, " ", @email, " ", @belt, "\n"
	end
	
	def simplifyClas
		@clas = @clas.delete "1"
		@clas = @clas.delete "0"
		@clas = @clas.delete "-"
		@clas = @clas.delete " "
		@clas = @clas.delete "X"
		@clas = @clas.delete "I"
		if @clas[0] == 97 # if small english 'a'
			@clas = "А"
		end
		
		if @clas[0] == 98 # if small english 'b'
			@clas = "Б"
		end
		
		if @clas[0] == 65 # if capital english 'A'
			@clas = "А"
		end
		
		if @clas[0] == 66 # if capital english 'B'
			@clas = "Б"
		end
		
		if @clas[1] == 176 # if small bulgarian "a"
			@clas = "А"
		end
		
		if @clas[1] == 177 #if small bulgarian "б"
			@clas = "Б"
		end
	end
end

def checkStudentsByName(students, name)
	index = 0
	students.each do |student|
		if student.getName ==  name
			return index
		end
		index += 1
	end
	return 0
end

def checkStudentsByClasAndNumber(students, clas, number)
	index = 0
	students.each do |student|
		if student.getClas == clas && student.getNumber == number
			return index
		end
		index += 1
	end
	return 0
end

def getStudentsNum(students)
	for num in 0...students.count
		if students[num].getClas == nil and students[num].getName == nil
			return num
		end
	end
	return 0
end

def stripRepoLink(link) 
	splitedLink = link.split("/")
	return splitedLink[3], "\n"
end

def homeworks(student)
	student.dump!
	CSV.foreach("task_names.csv") do |line|
		print line[0], " ", line[1], " "
		check = 0
		bool = false
		CSV.foreach(line[0] + ".csv") do |row|
			coincedence = 0
			if check == 1 and !bool
				timeArr = row[0].split(" ")[0].split("/")
				deadLine = Date.new(timeArr[2].to_i, timeArr[0].to_i, timeArr[1].to_i)
				print "Краен срок: ", deadLine.to_s, " 20:00:00", "\n"
				bool = true
			end
			check += 1
			if student.getClas == row[1]
				coincedence += 1
			end
			if student.getNumber == row[2]
				coincedence += 1
			end
			if student.getName == row[3]
				coincedence += 1
			end
			if student.getEmail == row[4]
				coincedence += 2
			end
			if row[5] != nil
				if student.getRepo == stripRepoLink(row[5])
					coincedence += 1
				end
			end
			if coincedence >= 3
				time = row[0].split(" ")[0].split("/")
				time2 = row[0].split(" ")[1].split(":")
				realTime = Time.utc(time[2].to_i,time[0].to_i,time[1].to_i,time2[0].to_i,time2[1].to_i,time2[2].to_i)
				realDeadLine = Time.utc(time[2].to_i,time[0].to_i,time[1].to_i, 20, 0, 0)
				if realDeadLine-realTime > 0 
					puts "Навреме!"
					puts row[5]
					if line[0].to_i == 7
						puts row[8]
					end
				else
					puts "It's too late to apologise..."
				end
			end
		end
	end
end

students = Array.new(500) {Student.new()}
studentsNum = 0

for i in 1..9
	CSV.foreach(i.to_s + ".csv") do |row|
		if row[1] == "Клас"
			next
		end
		if checkStudentsByName(students, row[3]) != 0 # if this name is written
			# ...
		else # if it is not written
			if checkStudentsByClasAndNumber(students, row[1], row[2]) != 0 # if it is existing but with other name
				# ...
			else # not existing at all...
				students[studentsNum].setClas(row[1])
				students[studentsNum].setNumber(row[2])
				students[studentsNum].setName(row[3])
				students[studentsNum].setEmail(row[4])
				if i != 1 # in the first homework we did't had repos
					students[studentsNum].setRepo(stripRepoLink(row[5]))
				end
				studentsNum += 1
			end
		end
	end
end

for i in 0...studentsNum
	students[i].simplifyClas
end

for i in 0...studentsNum - 1
	for j in 1...studentsNum
		coincedence = 0
		if students[i].getClas == students[j].getClas
			coincedence += 1
		end
		if students[i].getNumber == students[j].getNumber
			coincedence += 1
		end
		if students[i].getName == students[j].getName
			coincedence += 1
		end
		if students[i].getEmail == students[j].getEmail
			coincedence += 2
		end
		if students[i].getRepo == students[j].getRepo
			coincedence += 1
		end
		if coincedence >= 3 and i != j
			students[i].setRepo(students[j].getRepo)
			students.delete_at(j)
			studentsNum -= 1
		end
	end
end

temp = Student.new()
for i in 0...studentsNum - 1
	for j in 1...studentsNum
		if students[i].getNumber.to_i < students[j].getNumber.to_i
			temp = students[i]
			students[i] = students[j]
			students[j] = temp
		end
	end
end

emails = Array.new()
emailsNum = 0
for i in 0...studentsNum
	if emails.include? students[i].getEmail
		students.delete_at(i)
		studentsNum -= 1
	else
		emails[emailsNum] = students[i].getEmail
		emailsNum += 1
	end
end

studentsNum = getStudentsNum(students)

for i in 0...studentsNum
	CSV.foreach("exam.csv")	do |row|
		if row[9] == "Да"
			students[i].setBelt("Yellow")
		else
			students[i].setBelt("White")
		end
	end
end

temp = Student.new
for i in 0...studentsNum # sort by class
	for j in 0...studentsNum
		if students[i].getClas < students[j].getClas
			temp = students[i]
			students[i] = students[j]
			students[j] = temp
		end
	end
end

for i in 0...studentsNum # sort by number
	for j in 0...studentsNum
		if students[i].getClas.eql?(students[j].getClas)
			if students[i].getNumber.to_i < students[j].getNumber.to_i
				temp = students[i]
				students[i] = students[j]
				students[j] = temp
			end
		end
	end
end

for i in 0...studentsNum
	print i, ": "
	students[i].dump
end
print "Number of students: " ,studentsNum, "\n"

while true
	puts "Въведи пореден номер: (или -1 за изход)"
	input = gets.to_i
	if input == -1
		break
	end
	homeworks(students[input])
	puts
end
