#ifndef MULTIPLICATION_HPP
#define MULTIPLICATION_HPP

#include "BinaryOperator.hpp"

//Multiplication hérite de la class BinaryOperator
class Multiplication : public BinaryOperator
{
public:

  Multiplication(istream&); // Constructeur de la class Multiplication
  ~Multiplication(); // Destructeur de la class Multiplication
  double evaluate(double) const override; // fonction polymorphe qui permet de calculer la valeur passé en paramètre
  void write(ostream&) const override; // fonction polymorphe qui permet d'écrire l'operateur

};

#endif
