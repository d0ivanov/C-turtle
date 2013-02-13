class Ball
	attr_accessor :size, :name, :color

	def initialize size, name, color
		@size = size
		@name = name
		@color = color
	end
end

class BallContainer
	attr_accessor :capacity, :balls, :filled

	def initialize capacity
		@capacity = capacity
		@balls = Array.new
		@filled = 0
	end
	
	def add ball 
		return if @filled + ball.size > @capacity
		@balls.push(ball)
		@filled += ball.size
	end
	
	def getFilled
		@filled
	end

	def remove ball
		@filled -= ball.size
		@balls.delete ball
	end

	def getCapacity
		return @capacity - @filled
	end

	def free
		@balls.clear
		@filled = 0
	end

	def contains? ball
		@balls.include? ball
	end

	def getFromSmallest
		@balls.sort {|x, y| x.size <=> y.size}
	end
end 
