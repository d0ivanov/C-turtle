#!/usr/bin/env ruby

require "csv"

$x = Array.new(50, 0)
$y = Array.new(50, 0)

def parseFile(file)
	i = 0

	CSV.foreach(file) do |row|
		$x[i] = row[1]
		$y[i] = rand(row[1].to_i/2) + 100
		i += 1
	end

end

def writeToFile()
		file = CSV.open("some.csv", "w")
		for i in 0...50
  				file << [i.to_s, $x[i].to_s, $y[i].to_s]
		end
end

ARGV.each do|a|
  parseFile(a)
end
writeToFile()
