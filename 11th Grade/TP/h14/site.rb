#school - ТУЕС www.elsys-bg.org
#class - 11Б
#num - 22
#name - Михаил Михайлов Здравков
#task - Създаване на класовете Link, Page, Site. Взимане на всички линкове от дадена страница.

require 'uri'
require 'open-uri'

class Link
	attr_accessor :url

	def initialize(url)
		if url.is_a? String
			@url = URI.parse(url)
		else
			raise ArgumentError, "Not a Valid type. (String expected)"
		end
	end
end

class Page
	attr_accessor :url, :content, :links

	def initialize(link)
		if link.is_a? Link
			@url = link.url
		elsif link.is_a? String
			@url = URI.parse(link)
		else
			raise ArgumentError, "Not a Valid type. (Link or String expected)"
		end
		@content = @url.read
		@links = getLinks
	end

	def getLinks
		@links = @content.scan(/a *?href *?= *?\"(.*?)"/)
		return @links.map! {|x| x unless x.empty?}.flatten!
	end
end

class Site
	attr_accessor :url, :protocol, :pages
	
	def initialize(link)
		if link.is_a? Link
			@url = link
		elsif link.is_a? String
			@url = URI.parse(link)
		else
			raise ArgumentError, "Not a Valid type. (Link or String expected)"
		end
		@protocol = getProtocol
		@pages = Array.new(1) {Page.new(@url)}
	end
		
	def getProtocol
		@url.url.scheme
	end

	def addPage(page)
		if page.is_a? Page
			@pages.push(page)
		else		
			raise ArgumentError, "Not a Valid type. (Page expected)"
		end
	end
	
	def pagesCount
		return @pages.count unless @pages.nil?
		raise NoMethodError, "Site::pages is nil::nilClass by some reasong. You can't get its count."
	end		
end

begin
	link = Link.new("http://google.bg") #bg.wikipedia.org") #http://m.zdravkov.free.bg/bg_index.html")
	page = Page.new(link)
	puts page.links
	site = Site.new(link)
	puts site.getProtocol
	site.addPage(page)
	puts site.pagesCount
rescue ArgumentError => exception
	puts exception
end
