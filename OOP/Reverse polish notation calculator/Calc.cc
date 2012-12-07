#include "Calc.hh"
#include "Context.hh"
#include "Operation.hh"

#include<iostream>
#include<sstream>
#include<string>
using namespace std;

Calc::Calc(Context& context, istream& in)
: context_(context),
  in_(in)
{}

void Calc::run() {
  string token;

  in_>>token;
  while(in_) {
    Operation* op = context_.find_op(token);
	if(op != NULL) {
	  op->calc(context_);
	  if(!context_.empty()) {
	    cout << context_.top() << endl;
	  }
    } else {
      istringstream istr(token);
	  double val = 0;
	  istr>>val;
	  if(istr) {
	    context_.push(val);
	  } else {
        cerr << "UNKNOWN TOKEN <" << token << ">" << endl;
	  }
	}

	in_ >> token;
  } 
}
