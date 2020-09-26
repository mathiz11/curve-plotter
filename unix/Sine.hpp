#ifndef SINE_HPP
#define SINE_HPP

#include "UnaryOperator.hpp"

//Sine hérite d'UnaryOperator
class Sine : public UnaryOperator
{
public:

  Sine(istream&); // Constructeur de la class Sine
  ~Sine(); // Destructeur de la class Sine
  double evaluate(double) const override; //fonction polymorphe qui permet de calculer la valeur passé en paramètre
  void write(ostream&) const override; // fonction polymorphe qui permet d'écrire l'operateur

};

#endif
