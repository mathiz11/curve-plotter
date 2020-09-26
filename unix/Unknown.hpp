#ifndef UNKNOWN_HPP
#define UNKNOWN_HPP

#include "Operator.hpp"

//Unknown hérite de la class Operator
class Unknown : public Operator
{
public:

  Unknown(istream&); // Constructeur de la classe Unknown
  ~Unknown(); // Destructeur de la classe Unknown
  double evaluate(double) const override; //fonction polymorphe qui permet de calculer la valeur passé en paramètre
  void write(ostream&) const override; // fonction polymorphe qui permet d'écrire l'operateur

};

#endif
