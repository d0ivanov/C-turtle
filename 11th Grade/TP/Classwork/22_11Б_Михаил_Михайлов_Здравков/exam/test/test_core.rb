require 'simplecov'
SimpleCov.start
require Dir.pwd + '/src/core'
require 'minitest/autorun'

class TemplateTest < MiniTest::Unit::TestCase
	def test_get_average_age
		t = Team.new
		t.add Member.new("m", "ivan", 21)
		
		assert_equal 21, t.get_average_age
	end

	def test_remove
		t = Team.new
		m1 = Member.new("m", "ivan", 21)
		m2 = Member.new("f", "ivana", 11)
		t.add m1
		t.add m2
		t.remove m1 

		assert_equal 11, t.get_average_age
	end

	def test_contains_with_name
		t = Team.new
		t.add Member.new("m", "ivan", 21)
		t.add Member.new("f", "ivana", 19)
		
		assert t.contains_with_name("ivan")
		assert t.contains_with_name("ivana")
		assert_equal false, t.contains_with_name("ivancho")
	end

	def test_get_sorted_by_gender_and_age
		t = Team.new
		m1 = Member.new("m", "ivan", 21)
		m2 = Member.new("f", "ivan", 31)
		m3 = Member.new("m", "ivan", 13)
		m4 = Member.new("f", "ivan", 21)
		t.add m1
		t.add m2
		t.add m3
		t.add m4

		males, females = t.get_sorted_by_gender_and_age

		assert_equal [m3, m1], males
		assert_equal [m4, m2], females
	end
end
