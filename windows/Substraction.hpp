#ifndef SUBSTRACTION_HPP
#define SUBSTRACTION_HPP

#include "BinaryOperator.hpp"

//Substraction hérite de BinaryOperator
class Substraction : public BinaryOperator
{
public:

  Substraction(istream&); // Constructeur de la class Substraction
  ~Substraction(); // Destructeur de la class Substraction
  double evaluate(double) const override; //fonction polymorphe qui permet de calculer la valeur passé en paramètre
  void write(ostream&) const override; // fonction polymorphe qui permet d'écrire l'operateur

};

#endif
