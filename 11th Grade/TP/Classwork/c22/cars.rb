module Loadable
	def getLoad(vechicle); end
	def load_it(value); end
end

class Vechicle
	attr_accessor :number, :x, :y

	def initialize(number)
		@number = number
		@x, @y = 0
	end

	def printVechicle
		print "Number: ", @number, "\n"
		print "X:", @x, "\n"
		print "Y:", @y, "\n"
	end
end

class Car < Vechicle
	include Loadable

	def initialize(number)
		super(number)
		@load = 0
	end

	def printVechicle
		super()
		print "Load: ", @load, "\n"
	end

	def load_it(value)
		@load += value and return if @load + value < 1
		abort("tooo much load")
	end
end

class Truck < Vechicle
	include Loadable

	def initialize(number)
		super(number)
		@load = 0
	end

	def printVechicle
		super()
		print "Load: ", @load, "\n"
	end
	
	def load_it(value)
		@load += value and return if @load + value < 20
		abort("Too much load.")
	end
end

def printVechicles(arr)
	arr.each do |vechicle| 
		vechicle.printVechicle
	end
end

vechicles = Array.new
for i in 0...10 do
	vechicles.push Car.new(i) if i < 5
	vechicles.push Truck.new(i) if i >= 5
end

while true
	p "-1 to exit"
	abort("Bye bye") if gets.chomp.to_i == -1
	printVechicles(vechicles)
	p "1 to move other to load:" and option = gets.chomp.to_i
	if option == 1
		p "Enter car number:" and num = gets.chomp.to_i
		p "New X:" and x = gets.chomp.to_i
		p "New Y:" and y = gets.chomp.to_i
		vechicles.map {|vechicle| vechicle.x = x and vechicle.y = y if vechicle.number == num }
	else
		p "number: " and num = gets.chomp.to_i 
		p "Load: " and load = gets.chomp.to_i
		vechicles.map {|vechicle| vechicle.load_it(load) if vechicle.number == num }
	end
end
