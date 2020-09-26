#include <iostream>

using namespace std;

#include "Substraction.hpp"

Substraction::Substraction(istream& is)
: BinaryOperator('-', is)
{ cerr << "Substraction::Substraction(istream& is)" << endl; }

Substraction::~Substraction()
{ cerr << "Substraction::~Substraction()" << endl; }

double Substraction::evaluate(double x) const
{ return BinaryOperator::getOperand1()->evaluate(x) -
         BinaryOperator::getOperand2()->evaluate(x); }

void Substraction::write(ostream& os) const
{
  Operator::write(os); os << " ";
  BinaryOperator::getOperand1()->write(os);
  os << " ";
  BinaryOperator::getOperand2()->write(os);
  os << ")";
}
