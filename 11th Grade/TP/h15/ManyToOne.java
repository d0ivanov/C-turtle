package source;

import java.util.ArrayList;
import java.util.Collection;

public class ManyToOne<M, O> {
	
	class Pair{
		public M key;
		public O target;
		
		public Pair(M key, O target) {
			super();
			this.key = key;
			this.target = target;
		}
		
		public boolean equals(Pair other){
			if (this.key.equals(other.key) && this.target.equals(other.target))
				return true;
			return false;
		}
	}
	
	private ArrayList<Pair> hash = new ArrayList<Pair>();
	private int count = 0;
	
	public boolean connect(M source, O target) {
		Pair pair = new Pair(source, target);
		for (Pair old : hash){
			if (old.equals(pair)){
				hash.remove(old);
				hash.add(pair);
				return true; // for did something
			}
		}
		hash.add(pair);
		count++;
		return true; // did something
	}
	/**
	* @param source
	* @return <code>true</code> if the relation contains the given source
	*/
	public boolean containsSource(M source) {
		for (Pair pair : hash){
			if (pair.key.equals(source)){
				return true;
			}
		}
		return false;
	}
	/**
	* @param target
	* @return <code>true</code> if the relation contains the given target
	*/
	public boolean containsTarget(O target) {
		for (Pair pair : hash){
			if (pair.target.equals(target)){
				return true;
			}
		}
		return false;
	}
	/**
	* @param source
	* @return the target with which this source is connected
	*/
	public O getTarget(M source) {
		for (Pair pair : hash){
			if (pair.key.equals(source)){
				return pair.target;
			}
		}
		return null;
	}
	/**
	* @param target
	* @return all the targets that are connected with this source or empty
	*
	collection if there are no sources connected with this target.
	*/
	public Collection<M> getSources(O target) {
		Collection<M> collection = new ArrayList<M>();
		for (Pair pair : hash){
			if (pair.target.equals(target)){
				collection.add(pair.key);
			}
		}
		return collection;
	}
	/**
	* Removes the connection between this source and the corresponding target.
	* Other sources will still point to the same target.
	*
	* The target is removed if this was the only source pointing to it and
	* {@link #containsTarget(Object)} will return false.
	*
	* @param source
	*/
	public void disconnectSource(M source) {
		for (Pair pair : hash){
			if (pair.key.equals(source)){
				hash.remove(pair);
				count--;
				return; // optimization llama was here
			}
		}
	}
	/**
	* Removes the given target from the relation. All the sources that are
	* pointing to this target are also removed.
	*
	* If you take the "result" of {@link #getSources(target)} and after that
	* call this method then {@link #containsSource(Object)} will return
	* <code>false</code> for every object in "result".
	*
	* @param target
	*/
	public void disconnect(O target) {
		for (Pair pair : hash) {
			if (pair.target.equals(target)){
				hash.remove(pair);
				count--;
			}
		}
	}
	/**
	* @return a collection of the targets.
	*/
	public Collection<O> getTargets() {
		Collection<O> collection = new ArrayList<O>();
		for (Pair pair : hash){
			collection.add(pair.target);
		}
		return collection;
	}
	
	public ArrayList<Pair> getHash() {
		return hash;
	}
	
	public int getCount() {
		return count;
	}
	
	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + ((hash == null) ? 0 : hash.hashCode());
		return result;
	}

	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		ManyToOne other = (ManyToOne) obj;
		if (this.count != other.getCount())
			return false;
		if (this.hash.equals(other.getHash()))
			return true;
		return true;
	}
}
