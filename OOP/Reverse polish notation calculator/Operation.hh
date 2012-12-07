#ifndef OPERATION_HH__
#define OPERATION_HH__

#include<string>

class Context;

class Operation {
  std::string name_;
  public:
	Operation(const std::string& name)
	: name_(name)
	{}

    std::string getName() const {
      return name_;
	}

    virtual void calc(Context& context) const = 0;
};

#endif
