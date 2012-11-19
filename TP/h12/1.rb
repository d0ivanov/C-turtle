require 'net/http'
require 'uri'

class Link

  attr_accessor :value, :url
  
  def initialize(value)
    @url = URI(value)
	@value = @url.to_s
  end

  def visit
    Net::HTTP.get_response(@url).body
  end

end

class Page

  attr_accessor :url, :content, :links

  def initialize(url)
    @url = url
	@content = url.visit
  end

  def find_links
    raw_links = @content.scan(/\/wiki\/[^File][a-zA-Z0-9:_\-\(\).%#]*"/)
	raw_links.each do |link|
      @links.push(Link.new(@url.url.scheme+"://www."+@url.url.host+link.delete!("\"")))
	end
  end

end

class Site

  attr_accessor :protocol, :url, :pages

  def initialize(url)
    @url = url
	@protocol = @url.url.scheme
  end

  def find_pages
  end
end
