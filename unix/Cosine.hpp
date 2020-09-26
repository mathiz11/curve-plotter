#ifndef COSINE_HPP
#define COSINE_HPP

#include "UnaryOperator.hpp"

//Cosine hérite d'UnaryOperator
class Cosine : public UnaryOperator
{
public:

  Cosine(istream&); // Constructeur de la Classe Cosine
  ~Cosine(); // Destructeur de la class Cosine
  double evaluate(double) const override; // fonction polymorphe qui permet de calculer la valeur passé en paramètre
  void write(ostream&) const override; // fonction polymorphe qui permet d'écrire l'operateur

};

#endif
