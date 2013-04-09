operands = ["+", "-"]
context = []
while 1
  STDIN.flush
  input = gets.chomp.split.map {|in_| in_ if operands.include? in_ or /^[0-9]*\Z/.match(in_)}
  input.keep_if { |item| item != nil }
  input.each do |in_|
    if /^[0-9]*\Z/.match(in_)
	  context.push(in_)
    end
    if in_ == "+"
	  v2 = context.shift
	  v1 = context.shift
	  context.push((v1.to_i) + (v2.to_i))
    elsif in_ == "-"
      v2 = context.shift
	  v1 = context.shift
	  context.push((v2.to_i) - (v1.to_i))
    end
  end
  p context[0]
end
