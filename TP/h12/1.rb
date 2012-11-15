require 'net/http'

class Site

  attr_accessor :url, :protocol, :pages

  def initializer
    @pages = []
  end

  def get_pages
    
  end

end

class Page

  attr_accessor :content, :url, :links

  def get_links
    @links = /<a href="[a-zA-z:.\/]*">/.match(@content)
	p @links
  end

end

class Link

  attr_accessor :value

  def download
    response = Net::HTTP.get_response(URI(@value))
	page = Page.new
	page.content = response.body
	page.url = @value
	page.get_links
  end
end

link = Link.new
link.value = "http://en.wikipedia.org/wiki/Tuesday"
link.download
