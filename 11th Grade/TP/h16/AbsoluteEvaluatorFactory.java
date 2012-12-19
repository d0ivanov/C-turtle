package code;

public class AbsoluteEvaluatorFactory implements IEvaluatorFactory{
	public IEvaluator createSumEvaluator() {
		return new AbsoluteEvaluator("sum");
	}
	public IEvaluator createPowerOnEvaluator() {
		return new AbsoluteEvaluator("pow");
	}
	public IEvaluator createPowerOnEvaluator(double power) {
		return new AbsoluteEvaluator(power);
	}
	public IEvaluator createFibonaciEvaluator() {
		return new AbsoluteEvaluator("fib");
	}
}
