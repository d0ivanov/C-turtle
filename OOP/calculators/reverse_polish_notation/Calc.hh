#ifndef CALC_HH__
#define CALC_HH__
#include <iostream>

class Context;

class Calc {

	Context& context_;
	std::istream& in_;
	
public:

	Calc(Context& context,std::istream& in);

	void run();
};



#endif

