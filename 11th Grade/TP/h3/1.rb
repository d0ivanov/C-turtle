require 'csv'

pythonRes = 0
pearlRes = 0
rubyRes = 0

csv_read
CSV.foreach("example.csv") do |row|
	if row[7] == "Python"
		pythonRes += row[5].to_i
	end
	if row[7] == "Pearl"
		pearlRes += row[5].to_i
	end
	if row[7] == "Ruby"
		rubyRes += row[5].to_i
	end
end

puts "Python: ", pythonRes, " Pearl: ", pearlRes, " Ruby: ", rubyRes
