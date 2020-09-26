#ifndef ABSOLUTEVALUE_HPP
#define ABSOLUTEVALUE_HPP

#include "UnaryOperator.hpp"

// AbsoluteValue hérite de UnaryOperator
class AbsoluteValue : public UnaryOperator
{
public:

  AbsoluteValue(istream&); // Constructeur de la classe  AbsoluteValue
  ~AbsoluteValue(); // Destructeur de la classe AbsoluteValue
  double evaluate(double) const override; // fonction polymorphe qui permet de calculer la valeur passé en paramètre
  void write(ostream&) const override; // fonction polymorphe qui permet d'écrire l'operateur

};

#endif
