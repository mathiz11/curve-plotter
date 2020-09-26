#include <iostream>

using namespace std;

#include "BinaryOperator.hpp"

BinaryOperator::BinaryOperator(char _symbol, istream& is)
: Operator(_symbol, is), operand1( Operator::load(is) ), operand2( Operator::load(is) )
{ cerr << "BinaryOperator::BinaryOperator(char _symbol, istream& is)" << endl; }

BinaryOperator::~BinaryOperator()
{
  delete operand1;
  delete operand2;
  cerr << "BinaryOperator::~BinaryOperator()" << endl;
}
