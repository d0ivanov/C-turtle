#include "Context.hh"
#include "Operation.hh"

#include <string>
#include <list>
using namespace std;

void Context::push(double val) {
	stack_.push_front(val);
}

double Context::pop() {
	double res=stack_.front();
	stack_.pop_front();
	return res;
}

bool Context::empty() const {
	return stack_.empty();
}

double Context::top() const {
	return stack_.front();
}

int Context::size() const {
	return stack_.size();
}

void Context::add_op(Operation* op) {
	ops_.push_front(op);
}

Operation* Context::find_op(const string& name) const {
	for(list<Operation*>::const_iterator it=ops_.begin();
		it!=ops_.end();++it) {
		
		if(name==(*it)->get_name()) {
			return *it;
		}
	}

	return NULL;
}












