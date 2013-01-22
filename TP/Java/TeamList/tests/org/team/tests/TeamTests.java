package org.team.tests;

import static org.junit.Assert.*;

import org.junit.Before;
import org.junit.Test;
import org.team.team.Member;
import org.team.team.Team;

public class TeamTests {

	private Team t;
	
	@Before
	public void setup() {
		t = new Team();
	}
	
	@Test
	public void testAdd() {
		Member m = new Member("f", "pesho", 1);
		Member m2 = new Member("m", "gosho", 2);
		Member m3 = new Member("f", "pesho", 1);
		Member m4 = new Member("m", "gosho", 2);
		
		t.add(m);
		t.add(m2);
		t.add(m3);
		t.add(m4);
		
		assertEquals(1, t.getTeam_f().size());
		assertEquals(1, t.getTeam_m().size());
	}
	
	@Test
	public void testRemove() {
		Member m = new Member("f", "pesho", 1);
		Member m2 = new Member("m", "gosho", 2);
		
		t.add(m);
		t.add(m2);
		
		t.remove(m);
		t.remove(m2);
		
		assertEquals(0, t.getTeam_f().size());
		assertEquals(0, t.getTeam_m().size());
	}
	
	@Test
	public void testGetAvarageAge() {
		Member m = new Member("f", "pesho", 1);
		Member m2 = new Member("m", "gosho", 2);
		Member m3 = new Member("f", "ivan", 3);
		Member m4 = new Member("m", "balkan", 2);
		
		assertEquals(0, t.getAvarageAge());
		
		t.add(m);
		t.add(m2);
		t.add(m3);
		t.add(m4);
		
		assertEquals(2, t.getAvarageAge());
	}
	
	@Test
	public void testcontainsMemWithName() {
		Member m = new Member("f", "pesho", 1);
		t.add(m);
		
		assertEquals(true, t.containsMemWithName("pesho"));
		assertEquals(false, t.containsMemWithName("ganka"));
	}

	@Test
	public void testSortByGenderAndAge() {
		Member m = new Member("f", "pesho", 1);
		Member m2 = new Member("m", "gosho", 2);
		Member m3 = new Member("f", "ivan", 3);
		Member m4 = new Member("m", "balkan", 2);
		
		t.add(m);
		t.add(m2);
		t.add(m3);
		t.add(m4);
		
		assertEquals("pesho", t.sortedByGenderAndAge().get(0).getName());
		assertEquals("gosho", t.sortedByGenderAndAge().get(2).getName());
	}
}
