#ifndef CONTEXT_HH__
#define CONTEXT_HH__

#include<list>
#include<string>

class Operation;

class Context {
  private:
    std::list<double> stack_;
	std::list<Operation*> ops_;

  public:
    
	void push(double val);
	double pop(void);
	bool empty() const;
	int size() const;
	void add_op(Operation* op);
	Operation* find_op(const std::string& name) const;
};

#endif
