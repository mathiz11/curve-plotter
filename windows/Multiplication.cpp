#include <iostream>

using namespace std;

#include "Multiplication.hpp"

Multiplication::Multiplication(istream& is)
: BinaryOperator('*', is)
{ cerr << "Multiplication::Multiplication(istream&)" << endl; }

Multiplication::~Multiplication()
{ cerr << "Multiplication::~Multiplication()" << endl; }

double Multiplication::evaluate(double x) const
{ return BinaryOperator::getOperand1()->evaluate(x) *
         BinaryOperator::getOperand2()->evaluate(x); }


void Multiplication::write(ostream& os) const
{
  Operator::write(os); os << " ";
  BinaryOperator::getOperand1()->write(os);
  os << " ";
  BinaryOperator::getOperand2()->write(os);
  os << ")";
}
