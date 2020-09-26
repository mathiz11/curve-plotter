#include <iostream>
#include <cmath>

using namespace std;

#include "Tangent.hpp"

Tangent::Tangent(istream& is)
: UnaryOperator('T', is)
{ cerr << "Tangent::Tangent(istream& is)" << endl; }

Tangent::~Tangent()
{ cerr << "Tangent::~Tangent()" << endl; }

double Tangent::evaluate(double x) const
{ return tan( UnaryOperator::getOperand()->evaluate(x) ); }

void Tangent::write(ostream& os) const
{
  Operator::write(os); os << " ";
  UnaryOperator::getOperand()->write(os);
  os << ")";
}
