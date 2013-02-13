#member (g(m,f), name< agae 

class Member
	attr_accessor :gender, :name, :age

	def initialize gen, name, age
		@gender = gen
		@name = name
		@age = age
	end
end

class Team
	attr_accessor :males, :females

	def initialize
		@males = Array.new
		@females = Array.new
	end

	def add member
		@males.push member if member.gender == "m"
		@females.push member if member.gender == "f"
	end

	def get_average_age
		av = 0
		@males.each do |x|
			av += x.age
		end	
		@females.each do |x|
			av += x.age
		end	

		av = av / (@males.count + @females.count)

		return av
	end

	def remove member
		@males.delete member if member.gender == "m"
		@females.delete member if member.gender == "f"
	end

	def contains_with_name name
		@males.each do |x|
			return true if x.name == name
		end

		@females.each do |x|
			return true if x.name == name
		end
		return false
	end

	def get_sorted_by_gender_and_age
		males = @males.sort_by {|x| x.age}
		females = @females.sort_by {|x| x.age}
		return males, females
	end
end
