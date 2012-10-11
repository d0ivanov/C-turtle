#school - ТУЕС
#class - 11Б
#num - 15
#name - Добромир Иванов
#task - Да се създаде програма, която обработва CSV файл и изкарва на стандартния изход общия брой решени задачи на
#определените езици. 

#!/usr/bin/env ruby
#execute with either ruby filename.rb
#or chmod +x filename.rb and ./filename.rb
require "csv"

def parse_csv
	py = 0
	rb = 0
	sh = 0
	sum = 0
	CSV.foreach("2.csv") do |row|
		case row[5].downcase
			when "ruby" then rb += 1
			when "python" then py += 1
			when "shell" then sh += 1
		end
		sum += row[4].to_i
	end
	puts "ruby used " + rb.to_s + " times"
	puts "python used " + py.to_s + " times"
	puts "shell used " + sh.to_s + " times"
	puts "student class numbers sum: " + sum.to_s
end

parse_csv
