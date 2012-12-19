package code;

import java.util.ArrayList;
import java.lang.Math;

public class AbsoluteEvaluator implements IEvaluator {
	ArrayList<Double> list = new ArrayList<Double>();
	String type = "";
	double pow = 2;
	
	AbsoluteEvaluator(String type){
		this.type = type;
	}
	
	AbsoluteEvaluator(double pow){
		this.type = "pow";
		this.pow = pow;
	}
	
	@Override
	public void add(double d) {
		list.add(Math.abs(d));
	}

	@Override
	public Double evaluate() {
		double res = 0;
		if (type.equals("sum")){
			for (Double element : list){
				res += element;
			}
		} else if (type.equals("pow")){
			for (Double element : list){
				res += Math.pow(element, pow);
			}
		} else if (type.equals("fib")){
			double sum = 0;
			for (Double element : list){
				sum += element;
			}
			double fib1 = 0, fib2 = 1;
			do{
				double container = fib2;
				fib2 += fib1;
				fib1 = container;
			} while (fib2 < sum);
			if (fib2 - sum < sum - fib1){
				return fib2;
			} else {
				return fib1;
			}
		}
		return res;
	}
}
