require Dir.pwd + '/src/core'
require 'minitest/autorun'

class TemplateTest < MiniTest::Unit::TestCase

	def test_add
		bc = BallContainer.new 3
		bc.add Ball.new(1, 1, "green")

		assert_equal 1, bc.getFilled
	end

	def test_capacity
		bc = BallContainer.new 3
		bc.add Ball.new 2, 1, "green"
		bc.add Ball.new 2, 2, "red"

		assert_equal 2, bc.getFilled
	end

	def test_remove
		bc = BallContainer.new 3
		bc.add Ball.new 1, 1, "green"
		b2 = Ball.new 2, 2, "red"
		bc.add b2
		bc.remove b2

		assert_equal 1, bc.getFilled
	end

	def test_getCapacity
		bc = BallContainer.new 3
		bc.add Ball.new 1, 1, "green"

		assert_equal 2, bc.getCapacity
	end

	def test_clear
		bc = BallContainer.new 3
		bc.add Ball.new 2, 1, "green"
		bc.add Ball.new 2, 2, "red"
		bc.free

		assert_equal 0, bc.getFilled
	end

	def test_contains?
		bc = BallContainer.new 3
		b1 = Ball.new 2, 1, "green"
		bc.add b1
		
		assert bc.contains? b1
 	end

	def test_getFromSmallest
		bc = BallContainer.new 9
		b1 = Ball.new 4, 1, "green"
		b2 = Ball.new 2, 2, "red"
		b3 = Ball.new 3, 3, "yellow"
		bc.add b1 and	bc.add b2 and	bc.add b3

		assert_equal [b2, b3, b1], bc.getFromSmallest
	end
end
