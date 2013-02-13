puts "Enter input eg: operand1 operand2 operator. (operator(-; +)"
input = gets.chomp.split(" ")
input = input.map {|i| (i >= "0" and i <= "9")? i.to_i : i}
input.each_index {|i| input[i] *= -1 if input[i+1] == "-"}
input.delete_if {|i| i == "-" or i == "+"}
puts input.inject {|sum, i| sum + i}
