require 'rbconfig'
watch('src\/core\.rb') do
	system 'clear'
	success = system 'ruby test/test_core.rb'
	if success
		system 'notify-send Tests "OK"'
		puts 'OK'
	else
		system 'notify-send Tests "Tests failed ;("'
		puts "Tests failed ;("
	end
end
