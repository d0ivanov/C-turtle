$:.unshift File.dirname('/var/lib/gems/1.8/gems/nokogiri-1.5.5/lib')
puts $:
require 'rubygems'
require 'nokogiri.rb'
#require 'net/http'
#require 'uri'

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
	@links = []
  end

  def find_links
    raw_links = @content.scan(/<a href=\".*?\"/)
	raw_links.each do |link|
      l = link[9..-2]
	  @links.push(Link.new(l))
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

page = Page.new(Link.new("http://www.abv.bg"))
page.find_links
page.links.each do |link|
  p link
end
