module GreyWatcher

	require 'optparse'
	require 'optparse/time'
	require 'ostruct'
	require 'pp'

	class OptParser

		def self.parse(args)
			# The options specified on the command line will be collected in *options*.
    	# We set default values here.
			options = OpenStruct.new
			options.show = ''
			options.season = ''
			options.episode = ''
			options.username = 'bobivild'
			options.password = '214336'
			
			opts = OptionParser.new do |opts|
				opts.banner = "Usage: GreyWatcher.rb options"
			
				opts.separator ""
      	opts.separator "Options:"
				
				# Mandatory argument. show
				opts.on("-s", "--show SHOW NAME",
              "Show name to search for") do |show|
        	options.show = show
				end
				
				# Mandatory argument. season
				opts.on("-a", "--season SEASON",
              "Show season to search for") do |season|
        	options.season = season
				end
				
				# Mandatory argument. episode
				opts.on("-e", "--ep EPISODE",
              "Show episode to search for") do |ep|
        	options.episode = ep
				end

				# Optional arguemnt. username
				opts.on("-u", "--user USERNAME",
              "Username - site credentials") do |user|
        	options.suseranme << user
				end
				
				# Optional argument. password
				opts.on("[-p", "--password PASSWORD",
              "Password - site credentials") do |pass|
        	options.password << pass
				end
				
				# No argument, shows at tail.  This will print an options summary.
      	opts.on_tail("-h", "--help", "Show this message") do
        	puts opts
        	exit
      	end

      	# Print the version.
      	opts.on_tail("--version", "Show version") do
        	puts GreyWatcher::VERSION
        	exit
      	end
      end

    	opts.parse!(args)
    	options
		end
	end
end
