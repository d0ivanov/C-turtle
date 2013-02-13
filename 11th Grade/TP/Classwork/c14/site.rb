require 'net/http'
require 'uri'
require 'open-uri'

class Page
	attr_accessor :url, :content, :links

	def initialize(page_url)
		@url = URI.parse(page_url)
		@content = @url.read
	end

	def get_links
		@content.scan("/a href/") {|url| puts url}
	end
end

class Site
	attr_accessor :url, :protocol, :pages
		
end

p = Page.new("http://m.zdravkov.free.bg/bg_index.html")
puts p.content
p.get_links
