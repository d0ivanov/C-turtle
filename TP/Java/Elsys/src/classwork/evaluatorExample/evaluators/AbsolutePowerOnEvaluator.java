package classwork.evaluatorExample.evaluators;

import classwork.evaluatorExample.Evaluator;
import java.lang.Math;

public final class AbsolutePowerOnEvaluator extends Evaluator {

	private double power;
	
	public AbsolutePowerOnEvaluator() {
		this.power = 0;
	}
	
	public AbsolutePowerOnEvaluator(double power) {
		this.power = power;
	}
	
	@Override
	public Double evaluate() {
		double res = 0;
		for (Double val : evaluated) {
			if (power != 0) {
				res = res + (val * power);
			} else {
				res = res + (val * 2);
			}
		}
		evaluated.removeAll(evaluated);
		evaluated.add(Math.abs(res));
		return Math.abs(res);
	}

}