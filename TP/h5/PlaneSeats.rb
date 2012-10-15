#!/usr/bin/env ruby

class Plane
	
	@seats = Array.new(6) {|i| Array.new(27){|i| 0}}
	 
	 def add(passengers)
	 	r = Array.[](0, 0) 
	 	r = findSeat(passengers)
		seat = r[0]
		row = r[1]
		puts "Group of "+passengers.to_s + " arrives."
		if r[1] >= 0
			for i in 0..passengers
				puts "	Seat " + seatToReadable(seat, row) + " taken."
				@seats[seat][row] = 1
				seat+= 1
			end
		else
			puts "	Sorry, no seats for you..."
		end
	 end
	 
	 def printSeats()
	 	for i in 0..27
			for j in 0..6
				puts @seats[j][i]
				if j == 2 
					puts "|  |"
				end
			end
			puts ""
		end
	 end
	 
	 def planeFull()
	 	for i in 0...27
			for j in 0...6
				if @seats[j][i] == 0
					return true
				end
			end
		end
		return false
	 end
	 
	 def toTrail(seat)
	 	if seat == 2
			return true
		end
		return false 
	 end
	 
	 def findSeat(passengers)
	 	seat = Array.[](-1, -1)
	 	 
		for i in 0..27 
			for j in 0..6
				case passengers
					when 1
						if @seats[j][i] == 0
							seat[0] = j 
							seat[1] = i
							return seat
						end
					when 2
						if j + passengers <= 6 && !toTrail(j)
							if seats[j][i] == 0 && seats[j+1][i] == 0
								seat[0] = j
								seat[1] = i
								return seat
							end
						end
					when 3
						if j + passengers <= 6 && !toTrail(j)
							if seats[j][i] == 0 && seats[j+1][i] == 0 && seats[j+2][i] == 0
								seat[0] = j
								seat[1] = i
								return seat
							end
						end
				end
			end	
		end
		return seat
	 end
	 
	 def seatToReadable(seat, row)
	 	seatLetter = "";
		
		case seat
			when 0 then seatLetter = "A"
			
			when 1 then seatLetter = "B"
			
			when 2 then seatLetter = "C"
		
			when 3 then seatLetter = "D"
		
			when 4 then seatLetter = "E"
			
			when 5 then seatLetter = "F"
		end
		
		return row.to_s+seatLetter;
	 end

end

plane = Plane.new
people = 0
while plane.planeFull()
	rVal = 1 + rand(3)
	if people + rVal <= 162
		people += rVal
	end
	plane.add(rVal)
end
puts people.to_s+" people boarded the plane!"
