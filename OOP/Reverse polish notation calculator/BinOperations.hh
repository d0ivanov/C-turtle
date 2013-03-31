#ifndef BIN_OPERATIONS_HH__
#define BIN_OPERATIONS_HH__

#include "Operation.hh"

class Context;

class Plus : public Operation {

public:
	Plus();
	void calc(Context& context) const;
};


#endif

