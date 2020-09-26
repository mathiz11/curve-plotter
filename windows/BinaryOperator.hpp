#ifndef BINARYOPERATOR_HPP
#define BINARYOPERATOR_HPP

#include "Operator.hpp"

//BinaryOperator hérite d'Operator
class BinaryOperator : public Operator
{
private:

  Operator * operand1; // pointeurs sur les 2 opérandes
  Operator * operand2;

public:

  BinaryOperator(char, istream&); // Constructeur de la class BinaryOperator
  ~BinaryOperator(); // Destructeur de la class BinaryOperator;
  inline Operator * getOperand1() const { return operand1; } // getters sur les 2 opérandes
  inline Operator * getOperand2() const { return operand2; }

};

#endif
