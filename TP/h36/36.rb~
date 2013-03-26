Array.class_eval do
  def to_hash
    hash = {};
    each do |arr|
      hash[arr[0]] = arr[1]
    end
    hash
  end

  def index_by
    hash = {}
    each do |arr|
      hash[yield arr] = arr
    end
    hash
  end

	def subarray_count arg
    arr = []
    res = 0
    each do |elem|
    	arr[0] = elem
    	arr[1] = elem.next
    	if arr == arg
    		res += 1
    	end
    end
    res
  end

  def occurences_count
		hash = Hash.new(0)
		each do |v|
  		hash[v] += 1
		end
		hash
  end

  def densities
		res = []
		occurences = occurences_count
		occurences.each do |k, v|
			res[index k] = v
		end
		res.reject! {|e| e == nil}
  end
end
