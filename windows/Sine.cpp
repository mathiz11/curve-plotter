#include <iostream>
#include <cmath>

using namespace std;

#include "Sine.hpp"

Sine::Sine(istream& is)
: UnaryOperator('S', is)
{ cerr << "Sine::Sine(istream& is)" << endl; }

Sine::~Sine()
{ cerr << "Sine::~Sine()" << endl; }

double Sine::evaluate(double x) const
{ return sin( UnaryOperator::getOperand()->evaluate(x) ); }

void Sine::write(ostream& os) const
{
  Operator::write(os); os << " ";
  UnaryOperator::getOperand()->write(os);
  os << ")";
}
