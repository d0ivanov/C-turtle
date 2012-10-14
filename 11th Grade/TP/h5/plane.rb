/*
#school - ТУЕС
#class - 11Б
#num - 22
#name - Михаил Михайлов Здравков
#task - Програма за "пъхане" на хора в самолет.
*/
#!/usr/bin/envy ruby

class Plane
	$seats = Array.new(6) {|i| Array.new(27){|i| 0}}
	
	def seatsToTake(group, j, i) # printing which seats does a group of people takes
		print "Group of #{group} people."
		if group == 1
			print "Your place is: ", (i + 1), "|", (j + 1) # +1 so that there is no row/col 0
		else
			if group == 2
				print "Your place is: ", (i + 1), "|", (j + 1), " & ", (i + 1), "|", (j + 2)
			else
				print "Your place is: ", i + 1, "|", j + 1, " & ", i + 1, "|", j + 2, " & ",	i + 1, "|", j + 3
			end
		end
		puts ""
	end
	
	def freeSeats #  returns the count of free seats
		res = 0
		
		for i in 0...6
			for j in 0...27
				if $seats[i][j] == 0
					res += 1
				end
			end
		end
		
		return res
	end
	
	def push(group) # pushes people in the 2d array :D
		for i in 0...27
			for j in 0...6
				if pushCheck(group, j, i)
					fill(group, j, i)
					seatsToTake(group, j, i)
					return
				end
			end
		end
	end
	
	def fill(group, j, i) # fills the seat that are taken with 1
		for j1 in j...(j+group)
			$seats[j1][i] = 1
		end
	end
	
	def neighbourSeats(group, j) # checks if the seats are neighbours (dividing them by the path)
		if j < 3
			if j + group <= 3 
				return true
			end
		else
			if j + group <= 6 
				return true
			end
		end
		
		return false
	end
	
	def pushCheck(group, j, i) # checks if the group given can sit at the place given and it's neighbours
		if j + group <= 6 # to prevent out of bound exception
			if group == 1 # if 1
				if $seats[j][i] == 0
					return true
				end
			else
				if group == 2 # if 2
					if $seats[j][i] == 0 && $seats[j+1][i] == 0 && neighbourSeats(group, j)
						return true
					end
				else # if 3
					if $seats[j][i] == 0 && $seats[j+1][i] == 0 && $seats[j+2][i] == 0 && neighbourSeats(group, j)
						return true
					end
				end
			end
		end
		
		return false
	end
	
	def printSeats # prints 2D array of 1/0 representing the seats
		for i in 0...27
			for k in 0...6
			 	print $seats[k][i]
			 	print " "
			 	if k == 2
			 		print "  "
			 	end
			end
			print "\n"
		end
	end
end

airPlane = Plane.new

people = 0
j = 0

while airPlane.freeSeats != 0 do
	rVal = 1 + rand(3)
	
	if people + rVal <= 162
		people += rVal
	end
	
	if airPlane.freeSeats != 0
		airPlane.push(rVal)
	else
		break
	end
	j += 1;
end

airPlane.printSeats
puts people
puts j
