package classwork.evaluatorExample.test;

import static org.junit.Assert.assertEquals;

import org.junit.Before;
import org.junit.Test;

import classwork.evaluatorExample.evaluators.PowerOnEvaluator;

public class PowerOnEvaluatorTest {

	private PowerOnEvaluator p;
	
	@Before
	public void setUp() {
		p = new PowerOnEvaluator(2);
	}
	
	@Test
	public void testPower() {
		p.add(2.0);
		p.add(4.0);
		assertEquals(20.0, p.evaluate(), 0.001);
	}
	
	@Test
	public void testEval() {
		p.add(2);
		p.add(3);
		assertEquals(13.0, p.evaluate(), 0.001);
	}

}
