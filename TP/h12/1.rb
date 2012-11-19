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
   @url = url.slice ""
   @links = []
  end

  def download
    @content = @url.visit
	@content
  end

  def get_links
    links = @content.scan(/\/wiki\/[^File][a-zA-Z0-9:_\-\(\).%#]*"/)
	links.each do |link|
	  @links.push(Link.new(link))
	end
	@links
  end

end

class Site

  attr_accessor :protocol, :url, :pages

end

page = Page.new(Link.new("http://en.wikipedia.org/wiki/Tuesday"))
page.download
puts page.get_links

