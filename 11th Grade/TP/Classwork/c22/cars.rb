class Loadable
	attr_accessor :load

	def getLoad(vechicle)
		vechicle.load
	end

	def load_it(value)
		@load += value
	end
end

class Car < Loadable
	attr_accessor :number, :x, :y

	def initialize(number)
		@number = number
		@x = 0 and @y = 0
		@load = 0
	end

	def printCar
		print "Number: ", @number, "\n"
		print "X:", @x, "\n"
		print "Y:", @y, "\n"
		print "Load: ", @load, "\n"
	end

	def load_it(value)
		@load += value and return if @load + value < 1
		abort("tooo much load")
	end
end

class Truck < Car
	def load_it(value)
		@load += value and return if @load + value < 20
		abort("Too much load.")
	end
end

def printCars(arr)
	for i in 0...10 do 
		arr[i].printCar
	end
end

cars = Array.new
for i in 0...10 do
	cars.push Car.new(i) if i < 5
	cars.push Truck.new(i) if i >= 5
end

while true
	p "-1 to exit"
	abort("Bye bye") if gets.chomp.to_i == -1
	printCars(cars)
	p "1 to move other to load:" and option = gets.chomp.to_i
	if option == 1
		p "Enter car number:" and num = gets.chomp.to_i
		p "New X:" and x = gets.chomp.to_i
		p "New Y:" and y = gets.chomp.to_i
		cars.map {|car| car.x = x and car.y = y if car.number == num }
	else
		p "number: " and num = gets.chomp.to_i 
		p "Load: " and load = gets.chomp.to_i
		cars.map {|car| car.load_it(load) if car.number == num }
	end
end
