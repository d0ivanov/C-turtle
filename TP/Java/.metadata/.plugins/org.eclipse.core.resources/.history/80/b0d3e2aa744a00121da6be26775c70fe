package classwork.evaluatorExample;

public interface IEvaluatorFactory {

	/**
	* @return a new evaluator that sums the given doubles.
	*
	<p>
	*
	Example:
	*
	</p>
	*
	<code>
	* IEvaluator eval = createSumEvaluator();
	* eval.add(3);
	* eval.add(4);
	* eval.add(5);
	* eval.evaluate() must result in 3 + 4 + 5
	*
	</code>
	*/
	public IEvaluator createSumEvaluator();
	
	/**
	* @return a new evaluator that brings the given doubles to the power of 2
	*
	and adds the result to the current evaluated value.
	*
	<p>
	*
	Example:
	*
	</p>
	*
	<code>
	* IEvaluator eval = createPowerOnEvaluator();
	* eval.add(3);
	* eval.add(4);
	* eval.add(5);
	* eval.evaluate() must result in 3^2 + 4^2 + 5^2 = 50
	* </code>
	*/
	public IEvaluator createPowerOnEvaluator();
	
	/**
	* @param power
	* @return a new evaluator that brings the given doubles to the power of
	*
	"power" and adds the result to the current evaluated value.
	*
	<p>
	*
	Example:
	*
	</p>
	*
	<code>
	* IEvaluator eval = createPowerOnEvaluator(3);
	* eval.add(3);
	* eval.add(4);
	* eval.add(5);
	* eval.evalute() must result in 3^3 + 4^3 + 5^3 = 216
	* </code>
	*/
	public IEvaluator createPowerOnEvaluator(double power);
	
	/**
	* @return a new evaluator that gives the fibonacci number that is most
	*
	closely to the sum of the added values.
	*
	<p>
	*
	Example:
	*
	</p>
	*
	<code>
	* IEvaluator eval = createFibanociEvaluator();
	* eval.add(10);
	* eval.evaluate() must result in 8
	* </code>
	*
	*
	<code>
	* IEvaluator eval = createFibanociEvaluator();
	* eval.add(100);
	* eval.add(30);
	* eval.add(1);
	* eval.evaluate() must result in 144 since the added sum is 131
	* </code>
	*/
	public IEvaluator createFibonaciEvaluator();

}
