#!/usr/bin/env ruby
#execute with either ruby filename.rb
#or chmod +x filename.rb and ./filename.rb
result =  0
bool = true
File.new("test.csv", 'r').each_line("\n") do |row|
	if(bool)#so that we do not parse first (header) row
		bool = false
	else
		columns = row.split(",")
		puts columns[5]
		result += columns[5].to_i
	end
end
puts result
