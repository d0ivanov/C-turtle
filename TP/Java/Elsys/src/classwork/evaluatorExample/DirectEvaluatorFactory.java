package classwork.evaluatorExample;

import classwork.evaluatorExample.evaluators.FibonaciEvaluator;
import classwork.evaluatorExample.evaluators.PowerOnEvaluator;

public class DirectEvaluatorFactory implements IEvaluatorFactory {

	@Override
	public IEvaluator createSumEvaluator() {
		return new PowerOnEvaluator(1);
	}

	@Override
	public IEvaluator createPowerOnEvaluator() {
		return new PowerOnEvaluator(2);
	}

	@Override
	public IEvaluator createPowerOnEvaluator(double power) {
		return new PowerOnEvaluator(power);
	}

	@Override
	public IEvaluator createFibonaciEvaluator() {
		return new FibonaciEvaluator();
	}
}