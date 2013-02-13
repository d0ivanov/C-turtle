#!/usr/bin/envy ruby

file = File.new('example.csv', 'r')
result =  0

file.each_line("\n") do |row|
	columns = row.split(",")
	result += columns[5].to_i
end
 
puts result
