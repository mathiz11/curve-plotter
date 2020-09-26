#include <iostream>

using namespace std;

#include "UnaryOperator.hpp"

UnaryOperator::UnaryOperator(char _symbol, istream& is)
: Operator(_symbol, is), operand( Operator::load(is) )
{ cerr << "UnaryOperator(char _symbol, istream& is)" << endl; }

UnaryOperator::~UnaryOperator()
{
  delete operand;
  cerr << "UnaryOperator::~UnaryOperator()" << endl;
}
