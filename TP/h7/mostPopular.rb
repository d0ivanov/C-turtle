#!/usr/bin/env ruby

require "csv"

def parse(file, students)
	CSV.foreach(file) do |row|
		index = row[0].to_i
		students[index] += 1
	end
	return students
end

def getPopularity(students)
	files = Dir.glob("*.csv")
	
	files.each{ |file| parse(file, students) } 

	return students.sort
end

students = Array.new(31, 0)

getPopularity(students)

print "first place: ", students.index(max = students.max), "\n"
print "last place: ", students.index(min = students.min), "\n"
