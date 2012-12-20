package classwork.evaluatorExample.evaluators;


public final class PowerOnEvaluator extends Evaluator {

	private double pow;
	
	public PowerOnEvaluator(double pow) {
		this.pow = pow;
	}
	
	@Override
	protected Double doEval(Double d) {
		return Math.pow(d, pow);
	}

}
