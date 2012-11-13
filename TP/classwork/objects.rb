class Objects
  attr_accessor :value

  def mind_fuck
    return 10, 5
  end

end

o = Objects.new
o.value = 5

i, j = o.mind_fuck
puts i.to_s + " "+j.to_s
