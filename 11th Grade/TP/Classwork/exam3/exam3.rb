class Widget
	attr_accessor :text, :x, :y

	def initialize(text, x, y)
		@text = text
		@x, @y = x, y
	end

	def printWidget
		print @text, " ", @x, " ", @y, "\n"
	end
end

module IClickable
	def click; end
end

class Button < Widget
	include IClickable

	def initialize(text, x, y)
		super(text, x, y)
	end

	def click
		puts @text.upcase!
	end
end

class Label < Widget
	
	def initialize(text, x, y)
		super(text, x, y)
	end
end

def list_print(arr)
	arr.each do |widget|
		widget.printWidget
	end
end

widgets = Array.new
for i in 0...2 do
	puts "Text, x, y:"
	input = gets.chomp.split(",")
	text = input[0].strip
	x, y = input[1].strip, input[2].strip
	widgets.push Button.new(text, x, y) if i < 1
	widgets.push Label.new(text, x, y) if i >= 1
end

list_print(widgets)
while true
	print "Input: "
	input = gets.chomp.split(",")
	widgets.map {|w| w.click if input[0] == "C" and input[1].strip == w.text and w.is_a? Button}
	list_print(widgets) if input[0] == "print"
end
