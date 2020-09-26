#ifndef POWER_HPP
#define POWER_HPP

#include "BinaryOperator.hpp"

//Power hérite de BinaryOperator
class Power : public BinaryOperator
{
public:

  Power(istream&); // Constructeur de la class Power
  ~Power(); // Cosntructeur de la class Power
  double evaluate(double) const override; //fonction polymorphe qui permet de calculer la valeur passé en paramètre
  void write(ostream&) const override; // fonction polymorphe qui permet d'écrire l'operateur

};

#endif
