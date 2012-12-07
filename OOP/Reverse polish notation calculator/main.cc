#include "Context.hh"
#include "Operation.hh"
#include "Calc.hh"
#include "BinOperations.hh"


#include<iostream>
using namespace std;

int main() {
  Context context;
  context.add_op(new Plus());

  Calc calc(context, cin);
  calc.run();
}
