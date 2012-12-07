File.open("Vehicle.java", "w") do |f|
  0.upto(200) do |i| 
    f.write("class Vehicle#{i} extends Vehicle#{i+1}{}\n")
  end
  f.write("public class Vehicle extends Vehicle10 {}")
end
