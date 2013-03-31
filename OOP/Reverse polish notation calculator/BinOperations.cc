#include "BinOperations.hh"
#include "Context.hh"

#include <iostream>
using namespace std;

Plus::Plus()
: Operation("+")
{}

void Plus::calc(Context& context) const {
	
	if(context.size()<2) {
		cerr << "need more arguments..." << endl;
	} else {

		double v1=context.pop();
		double v2=context.pop();
	
		double res=v1+v2;
	
		context.push(res);
	}
}
