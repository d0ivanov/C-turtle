#!/usr/bin/env ruby
require 'rubygems'
require 'nokogiri'
require 'open-uri'

@@BASE_URL = 'http://www.telerik.com'

def get_page(url)
	if uri_valid?(url)
		return Nokogiri::HTML(open(url))
	else
		return nil
	end
end

def uri_valid? url
	if url =~ URI::regexp(["http", "https"])
		return true
	else
		return false
	end	
end

def link_external? link
	if uri_valid?(link) && link.include?(@@BASE_URL)
		return false
	else
		return true
	end
end

def parse_link link
	if uri_valid? link
		return link
	end
	if uri_valid? @@BASE_URL + link
		return @@BASE_URL + link
	elsif uri_valid? @@BASE_URL + "/" + link
		return @@BASE_URL + "/" + link
	end
	nil
end

def get_all_links url
	page = get_page url
	h = []
	page.xpath('//a[@href]').each do |link|
 		h.push(link['href']) 
	end
	h
end

def crawl url, depth
	links = []
	links.push get_all_links url
	links.flatten!
	links.uniq!
	links.each do |link|
		link = parse_link link
		if link == nil || link == @@BASE_URL || link_external?(link)
			next
		end
		if depth < 3
			crawl link, depth+1
		end
	end
	return links
end

p crawl @@BASE_URL, 1
