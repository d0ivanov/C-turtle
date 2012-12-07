#ifndef BIN_OPERATION_HH__
#define BIN_OPERATION_HH__

#include "Operation.hh"

class Plus : public Operation {

  public:
    Plus();
	void calc(Context& context ) const;
};

#endif
