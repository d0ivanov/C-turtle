#!/usr/bin/env ruby

require 'rubygems'
require 'mechanize'
require './OptParser.rb'

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
		
		attr_accessor :agent, :page, :show
		
		def initialize(opts)
			@agent, @page = Loginer::login(opts.username, opts.password)
			@show = opts.show + " " + "S" + opts.season + "E" + opts.episode + " " + "[XviD]"
		end
		
		def search
			search_form = @page.forms[1]
			search_form.search = @show
			search_form.cat = 7
			@page = @agent.submit(search_form)
		end
		
		def find
			search
			@page = @page.link_with(:text => @show).click
			return @page.link_with(:dom_class => "index").href
		end
		
		def download
			link = find
			@agent.get(TORRENT_TRACKER + "/"+ link).save("/home/smithie/Downloads/#@show.torrent")
		end
		
	end

end
opts = GreyWatcher::OptParser::parse(ARGV)
searcher = GreyWatcher::Searcher.new(opts)
searcher.download
