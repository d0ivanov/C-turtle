#Rails.application.config.middleware.use OmniAuth::Builder do
  # Sign up at https://github.com/account/applications
#  provider :github, APP_CONFIG["github_id"], APP_CONFIG["github_secret"]
#end

Rails.application.config.middleware.use OmniAuth::Builder do
  provider :facebook, "368429879937928", "bef2eefe108356bf9b8cf6811a33982a"
	configure do |config|
	   config.path_prefix = '/auth'
	end
end
