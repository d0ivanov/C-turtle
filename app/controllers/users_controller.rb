class UsersController < ApplicationController
  before_filter :load_current_user, :only => [:edit, :update]
  load_and_authorize_resource

  def show
  end

 # def create
 #   omniauth = request.env["omniauth.auth"]
 #   logger.info omniauth.inspect
 #   @user = User.find_by_github_uid(omniauth["uid"]) || User.create_from_omniauth(omniauth)
 #   cookies.permanent[:token] = @user.token
 #   redirect_to_target_or_default root_url, :notice => "Signed in successfully"
 # end

  def edit
  end

 # def update
 #   @user.attributes = params[:user]
 #   @user.save!
 #   redirect_to @user, :notice => "Successfully updated profile."
 # end

  def login
    session[:return_to] = params[:return_to] if params[:return_to]
    if Rails.env.development?
      cookies.permanent[:token] = User.first.token
      redirect_to_target_or_default root_url, :notice => "Signed in successfully"
    else
      redirect_to "/auth/facebook"
    end
		load_current_user
  end

  def logout
    cookies.delete(:token)
		$user = nil
    redirect_to root_url, :notice => "You have been logged out."
  end

 # def ban
 #   @user = User.find(params[:id])
 #   @user.update_attribute(:banned_at, Time.now)
 #   @comments = @user.comments
 #   @comments.each(&:destroy)
 #   respond_to do |format|
 #     format.html { redirect_to :back, :notice => "User #{@user.name} has been banned." }
 #     format.js
 #   end
 # end

 # def unsubscribe
 #   @user = User.find_by_unsubscribe_token!(params[:token])
 #   @user.update_attributes!(:email_on_reply => false)
 #   redirect_to root_url, :notice => "You have been unsubscribed from further email notifications."
 # end



 # Infision
	
	def new
	end

	def create 
		auth_hash = request.env['omniauth.auth']
		
		@authorization = Authorization.find_by_provider_and_uid(auth_hash["provider"], auth_hash["uid"])
		if !User.find(:all, :conditions => { :uid => auth_hash["uid"] }).empty?
			#redirect_to root_url, :notice => "You have been logged in."
			#$test = User.find(:first, :conditions => {:uid => auth_hash["uid"]}).name
			#login
		else
			user = User.new :name => auth_hash["info"]["name"], :email => auth_hash["info"]["email"]
			user.uid = auth_hash["uid"]
			user.authorizations.build :provider => auth_hash["provider"], :uid => auth_hash["uid"]
			user.save

			#redirect_to root_url, :notice => "You have been signed up."
			#$test = user.name
		end
		login
	end

	def failure
	end

  private

  def load_current_user
    $user = current_user
  end
end
