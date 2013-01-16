module GreyWatcher

	class ConfigEditor
		# add stuff to config file
	end

	class ConfigParser
	
		def self.parse_show
			file = File.open("config.xml", "r")
			config = Nokogiri::XML.parse(file)
			configs = config.xpath('//watched-shows/show').map do |i| 
 				{
 					'show' => i.xpath('name'),
 				 	'season' => i.xpath('season'),
 				 	'episode' => i.xpath('episode'),
 				 	'format' => i.xpath('format'),
 				}
 			end
 			file.close
 			return configs
		end
		
		def self.parse_credentials
			file = File.open("config.xml", "r")
			config = Nokogiri::XML.parse(file)
			configs = config.xpath('//site-credentials/credential').map do |i| 
 				{
 					'username' => i.xpath('username'),
 				 	'password' => i.xpath('password'),
 				}
 			end
 			file.close
 			return configs
		end
		
		def self.parse_num(num)
			if num.to_i < 10
				return "0" + num
			end
			return num
		end
		
		def self.get_shows
			data = []
			shows = parse_show
			shows.each do |show|
				show_info = {
					'show' => show['show'].children.text,
					'season' => parse_num(show['season'].children.text),
					'episode' => parse_num(show['episode'].children.text),
					'format' => show['format'].children.text
				}
				data.push show_info
			end
			return data
		end
		
		def self.get_credentials
			data = []
			credentials = parse_credentials
			credentials.each do |credential|
				credential_info = { 'username' => credential['username'].children.text, 'password' => credential['password'].children.text }
				data.push credential_info
			end
			return data
		end
	end

end
