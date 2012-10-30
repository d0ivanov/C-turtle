#11Б
#22
#Михаил Михайлов Здравков
#Сумата на първите 10 числа от csv file

require 'csv'

times = Array.new

count = 0
CSV.foreach("feature_scenarios_times.csv") do |row|
	times[count] = row[0].to_f
	count += 1
end

sum = 0
for i in 0...10
	puts times[i]
	sum += times[i]
end

CSV.open("res.csv", "w") do |csv|
	csv << [sum]
end
