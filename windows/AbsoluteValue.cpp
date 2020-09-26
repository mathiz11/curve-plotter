#include <iostream>
#include <cmath>

using namespace std;

#include "AbsoluteValue.hpp"

AbsoluteValue::AbsoluteValue(istream& is)
: UnaryOperator('A', is)
{ cerr << "AbsoluteValue::AbsoluteValue(istream& is)" << endl; }

AbsoluteValue::~AbsoluteValue()
{ cerr << "AbsoluteValue::~AbsoluteValue()" << endl; }

double AbsoluteValue::evaluate(double x) const
{ return fabs( UnaryOperator::getOperand()->evaluate(x) ); }

void AbsoluteValue::write(ostream& os) const
{
  Operator::write(os); os << " ";
  UnaryOperator::getOperand()->write(os);
  os << ")";
}
