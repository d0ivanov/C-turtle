require 'csv'

name = gets

y = Array.new(50) {0}
x = Array.new(50) {0}
i = 0

CSV.foreach("rand.csv") do |row| 
	if row[1].to_i != 0 
		y[i] = rand() % row[1].to_i/2
	end
	x[i] = row[1].to_i
	puts y[i]
	i += 1
end

i = 0
CSV.open("yellow.csv", "w") do |csv|
  csv << [i.to_s, x[i].to_s, y[i].to_s]
  i += 1
end
