#include <iostream>
#include <stdexcept>

using namespace std;

#include "Division.hpp"

Division::Division(istream& is)
: BinaryOperator('/', is)
{ cerr << "Division::Division(istream& is)" << endl; }

Division::~Division()
{ cerr << "Division::~Division()" << endl; }

double Division::evaluate(double x) const
{
  double denominator = BinaryOperator::getOperand2()->evaluate(x);
  if (denominator == 0)
    throw domain_error("Impossible de faire une division par 0.");
  else
    return BinaryOperator::getOperand1()->evaluate(x) / denominator;
}

void Division::write(ostream& os) const
{
  Operator::write(os); os << " ";
  BinaryOperator::getOperand1()->write(os);
  os << " ";
  BinaryOperator::getOperand2()->write(os);
  os << ")";
}
