#include <iostream>

using namespace std;

#include "Unknown.hpp"

Unknown::Unknown(istream& is)
: Operator('X', is)
{ cerr << "Unknown::Unknown(istream& is)" << endl; }

Unknown::~Unknown()
{ cerr << "Unknown::~Unknown()" << endl; }

double Unknown::evaluate(double x) const
{ return x; }

void Unknown::write(ostream& os) const
{ Operator::write(os); os << ")"; }
