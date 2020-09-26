#ifndef TANGENT_HPP
#define TANGENT_HPP

#include "UnaryOperator.hpp"

//Tangent hérite d'UnaryOperator
class Tangent : public UnaryOperator
{
public:

  Tangent(istream&); //Constructeur de la class Tangent
  ~Tangent(); // Destructeur de la class Tangent
  double evaluate(double) const override; //fonction polymorphe qui permet de calculer la valeur passé en paramètre
  void write(ostream&) const override; // fonction polymorphe qui permet d'écrire l'operateur

};

#endif
