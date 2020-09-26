#ifndef OPERATOR_HPP
#define OPERATOR_HPP

#include <iostream>

using namespace std;

class Operator
{
private:

  char symbol; // symbol correspondant à l'opération

public:

  Operator(char, istream&); // Constructeur de la classe Operator
  virtual ~Operator(); // Destructeur de la classe Operator
  virtual double evaluate(double) const = 0; // Permet de calculer une valeur pour un double virtual pur car impossible de l'utiliser ici
  static Operator * load(istream&); // Fonction qui appartient à la classe Operator et qui construit
  friend ostream& operator<<(ostream&, const Operator&); // Permet d'afficher la donnée membre 'symbol'
  virtual void write(ostream&) const; // Permet de rendre la fonction 'operator<< polymorphe'
  double operator()(double) const; // Foncteur de la classe Operator qui utilise evaluate

};

#endif
