#include <iostream>
#include <cmath>

using namespace std;

#include "Power.hpp"

Power::Power(istream& is)
: BinaryOperator('P', is)
{ cerr << "Power::Power(istream& is)" << endl; }

Power::~Power()
{ cerr << "Power::~Power()" << endl; }

double Power::evaluate(double x) const
{ return pow(BinaryOperator::getOperand1()->evaluate(x),
             BinaryOperator::getOperand2()->evaluate(x)); }

void Power::write(ostream& os) const
{
  Operator::write(os); os << " ";
  BinaryOperator::getOperand1()->write(os);
  os << " ";
  BinaryOperator::getOperand2()->write(os);
  os << ")";
}
