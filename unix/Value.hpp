#ifndef VALUE_HPP
#define VALUE_HPP

#include "Operator.hpp"

//Value hérite d'Operator
class Value : public Operator
{
public:

  double value; // donnée qui va être lu dans le constructeur qui correspond à la constante

  Value(istream&); //constructeur de la class Value
  ~Value(); // Destructeur de la class value
  double evaluate(double x) const override; //fonction polymorphe qui permet de calculer la valeur passé en paramètre
  void write(ostream&) const override; // fonction polymorphe qui permet d'écrire l'operateur

};

#endif
