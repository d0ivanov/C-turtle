package code;

public class DirectEvaluatorFactory implements IEvaluatorFactory {
	public IEvaluator createSumEvaluator() {
		return new DirectEvaluator("sum");
	}
	public IEvaluator createPowerOnEvaluator() {
		return new DirectEvaluator("pow");
	}
	public IEvaluator createPowerOnEvaluator(double power) {
		return new DirectEvaluator(power);
	}
	public IEvaluator createFibonaciEvaluator() {
		return new DirectEvaluator("fib");
	}
}
