#ifndef DIVISION_HPP
#define DIVISION_HPP

#include "BinaryOperator.hpp"

//Division hérite de la classe BinaryOperator
class Division : public BinaryOperator
{
public:

  Division(istream&); // Constructeur de la class Division
  ~Division(); // Destructeur de la class Division
  double evaluate(double) const override; // fonction polymorphe qui permet de calculer la valeur passé en paramètre
  void write(ostream&) const override; // fonction polymorphe qui permet d'écrire l'operateur

};

#endif
