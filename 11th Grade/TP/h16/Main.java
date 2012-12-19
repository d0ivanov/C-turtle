package code;

public class Main {

	public static void main(String[] argv) {
		DirectEvaluatorFactory llama = new DirectEvaluatorFactory();
		IEvaluator eval = llama.createFibonaciEvaluator();
		eval.add(2);
		eval.add(3);
		eval.add(8);
		System.out.println(eval.evaluate());
	}

}
