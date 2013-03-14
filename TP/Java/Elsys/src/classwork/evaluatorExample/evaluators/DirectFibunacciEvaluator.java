package classwork.evaluatorExample.evaluators;

import classwork.evaluatorExample.Evaluator;

public final class DirectFibunacciEvaluator extends Evaluator {

	@Override
	public Double evaluate() {
		AbsoluteSumEvaluator evaluator = new AbsoluteSumEvaluator();
		double res = evaluator.evaluate(evaluated);
		Double prev1 = 0.0, prev2 = 1.0;

		for (; prev2 < res;) {
			Double savePrev1 = prev1;
			prev1 = prev2;
			prev2 = savePrev1 + prev2;
		}
		evaluated.removeAll(evaluated);
		evaluated.add(prev2);
		return prev2;
	}
}