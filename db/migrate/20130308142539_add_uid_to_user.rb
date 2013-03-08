class AddUidToUser < ActiveRecord::Migration
  def self.up
    add_column :users, :uid, :string
  end

  def self.down
    remove_column :users, :uid
  end
end
