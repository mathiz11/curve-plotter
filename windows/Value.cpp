#include <iostream>

using namespace std;

#include "Value.hpp"

Value::Value(istream& is)
: Operator('#', is)
{
  is >> value;
  cerr << "Value::Value(istream& is)" << endl;
}

Value::~Value()
{ cerr << "Value::~Value()" << endl; }

double Value::evaluate(double x) const
{ return value; }

void Value::write(ostream& os) const
{ Operator::write(os); os << " " << value << ")"; }
