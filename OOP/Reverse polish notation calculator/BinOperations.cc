#include "BinOperations.hh"
#include "Context.hh"

Plus::Plus()
: Operaion("+")
{}

void Plus::calc(Context& context) const {

  if(context.size() < 2) {
    cerr << "need more arguments..." << endl;
  } else {

    double v1 = context.pop();
    double v2 = context.pop();
    res = v1 + v2;
    context.push(res);
  }
}
