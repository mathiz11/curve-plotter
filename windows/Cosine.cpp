#include <iostream>
#include <cmath>

using namespace std;

#include "Cosine.hpp"

Cosine::Cosine(istream& is)
: UnaryOperator('C', is)
{ cerr << "Cosine::Cosine(istream& is)" << endl; }

Cosine::~Cosine()
{ cerr << "Cosine::~Cosine()" << endl; }

double Cosine::evaluate(double x) const
{ return cos( UnaryOperator::getOperand()->evaluate(x) ); }

void Cosine::write(ostream& os) const
{
  Operator::write(os); os << " ";
  UnaryOperator::getOperand()->write(os);
  os << ")";
}
