package classwork.evaluatorExample.evaluators;


public final class FibonaciEvaluator extends Evaluator {

	public Double eval() {
		double superResult = super.evaluate();
		
		return findClosest(superResult);
	}
	
	@Override
	protected Double doEval(Double d) {
		return null;
	}
	
	private double findClosest(double value) {
		return 0.00;
	}
}
