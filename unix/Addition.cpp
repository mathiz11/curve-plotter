#include <iostream>

using namespace std;

#include "Addition.hpp"

Addition::Addition(istream& is)
: BinaryOperator('+', is)
{ cerr << "Addition::Addition(istream& is)" << endl; }

Addition::~Addition()
{ cerr << "Addition::~Addition()" << endl; }

double Addition::evaluate(double x) const
{ return BinaryOperator::getOperand1()->evaluate(x) +
         BinaryOperator::getOperand2()->evaluate(x); }

void Addition::write(ostream& os) const
{
  Operator::write(os); os << " ";
  BinaryOperator::getOperand1()->write(os);
  os << " ";
  BinaryOperator::getOperand2()->write(os);
  os << ")";
}
