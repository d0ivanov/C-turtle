require 'net/http'

class Link

  attr_accessor :value

  def initialize(url)
    @value = URI(url)
  end

  def visit
    Net::HTTP.get_response(@value).body
  end

end

class Page

  attr_accessor :url, :content, :links

  def initialize(url)
   raise "URL must be of type Link!" unless url.is_a? Link
   @links = []
  end

  def download
    @content = @url.visit
	@content
  end

  def get_links
    links = @content.scan(/\/wiki\/[^File][a-zA-Z0-9:_\-\(\).%#]*"/)
	links.each do |link|
	  @links.push(link)
	end
	@links
  end

  def visit
    
  end

end

class Site

  attr_accessor :protocol, :url, :pages

  def initialize(url)
    raise "URL must be of type Link!" unless url.is_a? Link
	@url = url
	@protocol = url.gsub(/(https|http)/)
  end

  def visit_page(link)
    url = @url+link
	page = Page.new(link)
  end
  
end

site = Site.new(Link.new("http://en.wikipedia.org"))
page.download
puts page.get_links

