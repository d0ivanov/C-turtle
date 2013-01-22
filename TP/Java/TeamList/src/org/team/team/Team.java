package org.team.team;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Team {

	private List<Member> team_m = new ArrayList<Member>();
	private List<Member> team_f = new ArrayList<Member>();

	public List<Member> getTeam_m() {
		return team_m;
	}

	public List<Member> getTeam_f() {
		return team_f;
	}

	public void add(Member m) {
		if (m.getGender().equals("m")) {
			if (!containsName(m.getName(), team_m)) {
				team_m.add(m);
			}
		} else {
			if (!containsName(m.getName(), team_f)) {
				team_f.add(m);
			}
		}
	}

	public void remove(Member m) {
		if (m.getGender().equals("m")) {
			team_m.remove(m);
		} else {
			team_f.remove(m);
		}
	}

	public int getAvarageAge() {
		if (team_m.size() == 0 && team_f.size() == 0) {
			return 0;
		}
		return ( avarageAgeInList(team_m) + avarageAgeInList(team_f) )
				/ ( team_m.size() + team_f.size() );
	}

	public boolean containsMemWithName(String name) {
		if (containsName(name, team_m) || containsName(name, team_f)) {
			return true;
		}
		return false;
	}

	public List<Member> sortedByGenderAndAge() {
		sort();
		List<Member> result = new ArrayList<Member>();
		
		for (Member m : team_f) {
			result.add(m);
		}
		for (Member m : team_m) {
			result.add(m);
		}
		return result;
	}

	private int avarageAgeInList(List<Member> memList) {
		int result = 0;
		for (Member m : memList) {
			result += m.getAge();
		}
		return result;
	}
	
	private boolean containsName(String name, List<Member> memList) {
		for (Member m : memList) {
			if (m.getName().equals(name)) {
				return true;
			}
		}
		return false;
	}

	private void sort() {
		Collections.sort(team_m);
		Collections.sort(team_f);
	}
}
