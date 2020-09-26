#include <iostream>
#include <stdexcept>

using namespace std;

#include "Operator.hpp"
#include "Unknown.hpp"
#include "Value.hpp"
#include "AbsoluteValue.hpp"
#include "Cosine.hpp"
#include "Sine.hpp"
#include "Tangent.hpp"
#include "Addition.hpp"
#include "Division.hpp"
#include "Multiplication.hpp"
#include "Power.hpp"
#include "Substraction.hpp"

Operator::Operator(char _symbol, istream& is)
: symbol(_symbol) // affectation du symbole dans la donnée membre
{ cerr << "Operator::Operator(char _symbol, istream& is)" << endl; }

Operator::~Operator()
{ cerr << "Operator::~Operator()" << endl; }

Operator * Operator::load(istream& is)
{
	char cOperator; // Création d'un caractere qui sera lu
	do
	{
		is.get(cOperator); //récupère le caractère du flux du fichier
		if (cOperator == '(') //Si c'est le caractere suivant est un operateur
		{
			is.get(cOperator); // On lit et la fonction créer en conséquence une instance d'un operateur lu
			if (cOperator == 'X')
				return new Unknown(is);
			if (cOperator == '#')
				return new Value(is);
			if (cOperator == 'A')
				return new AbsoluteValue(is);
			if (cOperator == 'C')
				return new Cosine(is);
			if (cOperator == 'S')
				return new Sine(is);
			if (cOperator == 'T')
				return new Tangent(is);
			if (cOperator == '+')
				return new Addition(is);
			if (cOperator == '/')
				return new Division(is);
			if (cOperator == '*')
				return new Multiplication(is);
			if (cOperator == 'P')
				return new Power(is);
			if (cOperator == '-')
				return new Substraction(is);
			else
				throw runtime_error("Le caractere lu ne permet de creer une nouvelle "
				                    "instance 'Operator'."); // erreur si le caractère lu après la parenthèse n'est pas un caractere connu
		}
	} while(cOperator != '\0'); // On lit jusqu'à la fin du fichier

	return nullptr; //Si on échoue on renvoie nullptr;
}

void Operator::write(ostream& os) const
{ os << "(" << symbol; } // écrit le symbole grâce à 'operator<<'

ostream& operator<<(ostream& os, const Operator& op)
{
	op.write(os); //Appel de la fonction write
	return os;
}

double Operator::operator()(double x) const
{ return evaluate(x); } // foncteur qui utilise evaluate pour une question de facilité l'écriture
