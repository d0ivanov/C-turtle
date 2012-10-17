#!/usr/bin/env ruby

require "csv"

def parse(file, students)
	#students = Array.new(31, 0)
	CSV.foreach(file) do |row|
		index = row[0].to_i
		students[index] += 1
	end
	return students
end

def getPopularity(students)
	files = Dir.glob("*.csv")
	
	files.each{ |file|
		parse(file, students)
	}

	return students.sort! { |x,y| y<=>x }
end

students = Array.new(31, 0)

getPopularity(students)

puts students[0]
puts students[29]
