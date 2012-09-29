#!/usr/bin/envy ruby

fName = 'form.csv'
file = File.new(fName, 'r')
result =  0

file.each_line("\n") do |row|
   columns = row.split(",")
   result += columns[5].to_i
   break if file.lineno >= 21
 end
 
 puts result
