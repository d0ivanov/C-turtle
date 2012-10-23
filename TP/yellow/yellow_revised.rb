#!/usr/bin/env ruby
require "csv"
def parseFile(file)
	newFile = CSV.open("results.csv", "w")
	CSV.foreach(file) do |row|
		y = rand(row[1].to_i/2) + 100
		newFile << [row[0], row[1], y.to_s]
	end
end
ARGV.each do|a|
  parseFile(a)
end
