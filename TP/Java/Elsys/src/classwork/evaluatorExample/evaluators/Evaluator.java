package classwork.evaluatorExample.evaluators;

import java.util.ArrayList;
import java.util.List;

import classwork.evaluatorExample.IEvaluator;

public abstract class Evaluator implements IEvaluator{

	protected List<Double> evaluated = new ArrayList<Double>();
	

	protected abstract Double doEval(Double d);
	
	@Override
	public void add(double d) {
		evaluated.add(d);
	}
	
	@Override
	public Double evaluate() {
		double res = 0;
		for(Double value : evaluated) {
			res += doEval(value);
		}
		return res;
	}
}
