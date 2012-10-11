#school - ТУЕС
#class - 11Б
#num - 15
#name - Добромир Иванов
#task - Да се създаде програма, която обработва CSV файл и изписва на стандартния изход броя решени задачи.

#!/usr/bin/env ruby
#execute with either ruby filename.rb
#or chmod +x filename.rb and ./filename.rb
require "csv"

def parse_csv
	res = 0
	CSV.foreach("2.csv") do |row|
		res += row[5].to_i
	end
	puts res
end

def parse_file
	result = 0
	File.new("test.csv", 'r').each_line("\n") do |row|
		columns = row.split(",")
		result += columns[5].to_i
	end
	puts result
end

parse_csv
