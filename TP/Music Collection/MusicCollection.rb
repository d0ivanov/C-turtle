class Song
  attr_reader :name, :artist, :genre, :subgenre, :tags

  def initialize(name, artist, genre, tags)
    self.name = name
    self.artist = artist
    self.genre = genre
    self.tags = tags
  end

  def matches? criterion = {}
    match = true
    criterion.keys.each do |crit|
      if crit != :filter
        data, cond, excl = set_params criterion, crit
        match &= ((data & cond).size == cond.size - excl.size)
        match &= ((data & excl).size == 0)
      end
      match &= filter(&criterion[crit]) if crit == :filter
    end
    match
  end

  def filter &block
    yield self
  end

  private

    def name= name
      @name = name.strip.chomp
    end

    def artist= artist
      @artist =artist.strip.chomp
    end

    def genre= genre
      genres = genre.split(',').map {|x| x.strip.chomp}
      @genre = genres[0]
      @subgenre = genres[1]
    end

    def tags= tags
      @tags = []
      @tags = tags.split(',').map {|x| x.strip.chomp} unless tags == nil
      @tags.push @genre.downcase
      @tags.push @subgenre.downcase unless @subgenre == nil
      @tags.delete("")
    end

    def to_a item
      return [].push(item).flatten
    end

    def exclude criteria
      excluded = []
      to_a(criteria).each do |crit|
        excluded.push crit[0, crit.length - 1] if crit[-1, 1] == '!'
      end
      excluded
    end

    def set_params criterion, crit
      return to_a(send(crit)), to_a(criterion[crit]), exclude(criterion[crit])
    end
end

class Collection
  attr_reader :songs

  def self::parse text, a_tags
    songs = text.lines.to_a.map do |line|
      line.split('.').each_slice(4).map do |name, artist, genre, tags|
        tags += ',' + a_tags[artist].join(',') if a_tags[artist] != nil
        Song.new name, artist, genre, tags
      end
    end
    Collection.new songs.flatten
  end

  def initialize songs
    @songs = songs
  end

  def find criteria
    Collection.new @songs.select {|song| song.matches? criteria}
  end
end
