#!/usr/bin/env ruby

require 'rubygems'
require 'mechanize'
require './ConfigParser.rb'

module GreyWatcher

	VERSION = '1.0.0B'
	TORRENT_TRACKER = 'http://www.zamunda.net'
	LOGIN_PAGE = '/browse.php'
	
	class Loginer
	
		def self.login(username, password)
			agent = Mechanize.new
			page = agent.get(TORRENT_TRACKER + LOGIN_PAGE)
			form = page.form('login')
			form.username = username
			form.password = password
			page = agent.submit(form)
			return agent, page
		end
	end
	
	class Searcher
		
		attr_accessor :agent, :page, :shows
		
		def initialize(opts, agent, page)
			@agent, @page = agent, page
			@shows = opts
		end
		
		def search(show)
			search_form = @page.forms[1]
			search_form.search = show
			search_form.cat = 7
			@page = @agent.submit(search_form)
		end
		
		def find(show)
			search(show)
			if @page.link_with(:text => show) != nil
				@page = @page.link_with(:text => show).click
				return @page.link_with(:dom_class => "index").href
			end
			return nil
		end
		
		def download(show)
			link = find(show)
			if link != nil
				%x[ notify-send "GreyWatcher" "New episode found: #{show}"]
				@agent.get(TORRENT_TRACKER + "/"+ link).save("/home/smithie/Downloads/#{show}.torrent")
				@page = @agent.get(TORRENT_TRACKER + LOGIN_PAGE)
			end
		end
		
		def get_all_shows
			@shows.each do |show|
				show_search_string = show["show"] + " S" + show["season"] + "E" + show["episode"] + " [" + show["format"] + "]"
				download(show_search_string)
			end
		end
	end
end


opts = GreyWatcher::ConfigParser::get_credentials
opts.push GreyWatcher::ConfigParser::get_shows
agent, page = GreyWatcher::Loginer::login(opts[0]["username"], opts[0]["password"])
searcher = GreyWatcher::Searcher.new(opts[1], agent, page)
searcher.get_all_shows
