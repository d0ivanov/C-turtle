=begin
#school - ТУЕС
#class - 11Б
#num - 22
#name - Михаил Михайлов Здравков
#task - Проверка на предадени домашни.
=end

require 'csv'
require 'date'
require 'time'

class Student
	@clas, @email, @repo, @name = ""
	@number = 0
	@belt = "white"
	
	def getClas; return @clas; end
	def getNumber; return @number; end
	def getName; return @name; end
	def getEmail; return @email; end
	def getBelt; return @belt; end
	def getRepo; return @repo; end
	def setClas(val); @clas = val; end
	def setNumber(val); @number = val; end
	def setName(val); @name = val; end
	def setEmail(val); @email = val; end
	def setBelt(val); @belt = val; end
	def setRepo(val); @repo = val; end
	
	def dump
		print @clas, " ", @number, " ", @name, " ", @email, "\n"
	end
	
	def dump!
		puts; print @clas, " ", @number, " ", @name, " ", @email, " ", @belt, "\n"
	end
	
	def simplifyClas
		@clas = @clas.delete("0-9 XI-")
		@clas = "А" if @clas.index('a') != nil
		@clas = "Б" if @clas.index('b') != nil
		@clas = "А" if @clas.index('A') != nil
		@clas = "Б" if @clas.index('B') != nil
		@clas = "А" if @clas.index('а') != nil
		@clas = "Б" if @clas.index('б') != nil
	end
end

def checkStudentsByName(students, name)
	index = 0
	students.each do |student|
		return index if student.getName ==  name
		index += 1
	end
	return 0
end

def checkStudentsByClasAndNumber(students, clas, number)
	index = 0
	students.each do |student|
		return index if student.getClas == clas && student.getNumber == number
		index += 1
	end
	return 0
end

def getStudentsNum(students)
	for num in 0...students.count
		return num if students[num].getClas == nil and students[num].getName == nil
	end
	return 0
end

def stripRepoLink(link) 
	splitedLink = link.split("/")
	return splitedLink[3], "\n"
end

def homeworks(students, studentsNum)
	CSV.open("results.csv", "w") do |file|
#		students.each do |student|
		for i in 0...studentsNum
			file << [students[i].getClas, students[i].getNumber, students[i].getName, students[i].getEmail, students[i].getBelt]
			CSV.foreach("task_names.csv") do |line|
				#puts "3"
				file << [line[0], line[1]]
				check, bool = 0, false
				CSV.foreach(line[0] + ".csv") do |row|
					#puts "4"
					coincedence = 0
					if check == 1 and !bool
						timeArr = row[0].split(" ")[0].split("/")
						deadLine = Date.new(timeArr[2].to_i, timeArr[0].to_i, timeArr[1].to_i)
						#print "Краен срок: ", deadLine.to_s, " 20:00:00", "\n"
						file << ["Краен срок: ", deadLine.to_s, "20:00:00"]
						bool = true
					end
					check += 1
					coincedence += 1 if students[i].getClas == row[1]
					coincedence += 1 if students[i].getNumber == row[2]
					coincedence += 1 if students[i].getName == row[3]
					coincedence += 2 if students[i].getEmail == row[4]
					if row[5] != nil
						coincedence += 1 if students[i].getRepo == stripRepoLink(row[5])
					end
					if coincedence >= 3
						time = row[0].split(" ")[0].split("/")
						time2 = row[0].split(" ")[1].split(":")
						realTime = Time.utc(time[2].to_i,time[0].to_i,time[1].to_i,time2[0].to_i,time2[1].to_i,time2[2].to_i)
						realDeadLine = Time.utc(time[2].to_i,time[0].to_i,time[1].to_i, 20, 0, 0)
						if realDeadLine-realTime > 0 
							#puts "Навреме!", row[5]
							file << ["Навреме!", row[5]]
		#					puts row[8] if line[0].to_i == 7
							file << [row[8]] if line[0].to_i == 7
						else
		#					puts "It's too late to apologise..."
							file << ["It's too late to apologise...", row[5]]
						end
					end
				end
			end
		end
		file.close
	end
end

students = Array.new(500) {Student.new()}
studentsNum = 0

for i in 1..9
	CSV.foreach(i.to_s + ".csv") do |row|
		next if row[1] == "Клас"
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
				students[studentsNum].setRepo(stripRepoLink(row[5])) if i != 1 # we didn't had repos then
				studentsNum += 1
			end
		end
	end
end

def translate(string)
	h = Hash['a', 'а', 'b', 'б', 'c', 'ц', 'd', 'д', 'e', 'е', 'f', 'ф', 'g', 'г', 
	'h', 'х', 'i', 'и', 'j', 'й', 'k', 'к', 'l', 'л', 'm', 'м', 'n', 'н', 'o', 'о', 
	'p', 'п', 'q', 'я', 'r', 'р', 's', 'с', 't', 'т', 'u', 'у', 'v', 'в', 'w', 'в',
	'x', 'кс', 'y', 'й', 'z', 'з', 'ya', 'я', 'yu', 'ю', 'ja', 'я' ]
	string = string.downcase
	h.each_pair do |i, v|
		for j in 0...string.length
			index = string.index(i)
			string = string.sub(i, '')
			string = string.insert(index, v) if index != nil
		end
	end
	
	return string
end

for i in 0...studentsNum
	students[i].simplifyClas
end

for i in 0...studentsNum - 1
	for j in 1...studentsNum
		coincedence = 0
		
		coincedence += 1 if students[i].getClas == students[j].getClas
		coincedence += 1 if students[i].getNumber == students[j].getNumber
		coincedence += 1 if students[i].getName == students[j].getName
		coincedence += 2 if students[i].getEmail == students[j].getEmail
		coincedence += 1 if students[i].getRepo == students[j].getRepo
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
		students[i],students[j] = students[j],students[i] if students[i].getNumber.to_i < students[j].getNumber.to_i
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
	for j in 1..2
		CSV.foreach("exam" + j.to_s + ".csv") do |row|
			coincedence = 0
			coincedence += 1 if students[i].getClas == row[1]
			coincedence += 1 if students[i].getNumber == row[2]
			coincedence += 2 if students[i].getName == row[3]
			coincedence += 2 if students[i].getRepo == stripRepoLink(row[5]) unless row[5] == nil
			if coincedence >= 3
				students[i].setBelt("Yellow") if row[9] == "Да"
				students[i].setBelt("White") if row[9] != "Да"
				puts row[9]
			end
		end
	end
end

temp = Student.new
for i in 0...studentsNum # sort by class
	for j in 0...studentsNum
		if students[i].getClas < students[j].getClas
			students[i], students[j] = students[j], students[i]
		end
	end
end

for i in 0...studentsNum # sort by number
	for j in 0...studentsNum
		if students[i].getClas.eql?(students[j].getClas)
			if students[i].getNumber.to_i < students[j].getNumber.to_i
				students[i], students[j] = students[j], students[i]
			end
		end
	end
end

for i in 0...studentsNum
	students[i].setName(translate(students[i].getName))
	#print i, ": "
	students[i].dump!
end
print "Number of students: " ,studentsNum, "\n"

homeworks(students, studentsNum)

