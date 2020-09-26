#ifndef UNARYOPERATOR_HPP
#define UNARYOPERATOR_HPP

#include "Operator.hpp"

//UnaryOperator hérite d'Operator
class UnaryOperator : public Operator
{
private:

  Operator * operand; // pointeur sur la seule opérande

public:

  UnaryOperator(char, istream&); // Constructeur de la class UnaryOperator
  ~UnaryOperator(); // Constructeur de la class UnaryOperator
  inline Operator * getOperand() const { return operand; } //getter de l'adresse du pointeur operand

};

#endif
