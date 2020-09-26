#ifndef ADDITION_HPP
#define ADDITION_HPP

#include "BinaryOperator.hpp"

// Addition hérite de BinaryOperator
class Addition : public BinaryOperator
{
public:

  Addition(istream&); // Constructeur de la classe Addition
  ~Addition(); // Destructeur de la classe  Addition
  double evaluate(double) const override; // fonction polymorphe qui permet de calculer la valeur passé en paramètre
  void write(ostream&) const override; // fonction polymorphe qui permet d'écrire l'operateur

};

#endif
