require 'csv'

#Клас, номер, име, поща, колан
#“номер на домашно”, “заглавие на домашното”, “краен срок”, “дата на предаване”, “предадено ли е на време”, “връзки към решените задачи”
#номер на домашното, заглавие на домашното, краен срок, дата на предаване, предадено ли е на време, връзка1, връзка2, връзкаN
#-

#Клас, номер, име, поща, колан
#“номер на домашно”, “заглавие на домашното”, “краен срок”, “дата на предаване”, “предадено ли е на време”, “връзки към решените задачи”
#номер на домашното, заглавие на домашното, краен срок, дата на предаване, предадено ли е на време, връзка1, връзка2, връзкаN

class Studen
	
	@clas = ""
	@number = 0
	@name = ""
	@email = ""
	@belt = "white"
	
	def get_clas
		return @clas
	end
	
	def get_number
		return @number
	end
	
	def get_name
		return @name
	end
	
	def get_email
		return @email
	end
	
	def get_belt
		return @belt
	end
	
end

def getAllNames
	namesNum = 0
	names = Array.new(80) {""}
	
	for i in 1..9
		CSV.each_line(i+".csv") do |row|
			
		end
	end
end

def initStudent(currentStudent)
	CSV.each_line("exam.csv") do |row|
		
	end
	
end

currFile = 1


