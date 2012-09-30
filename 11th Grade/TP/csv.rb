#!/usr/bin/envy ruby

file = File.new('form.csv', 'r')
result =  0
bool = true

file.each_line("\n") do |row|
	if bool # to skip the first line (because the first line is full with strings)
		bool = false
	else
		columns = row.split(",")
		result += columns[5].to_i
	end
end
 
puts result
