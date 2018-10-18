#include "Comarca.h"
// Nom:Ibrahima Sory Diallo
//Usuari:u1939649
//Practica Nº:S1
Comarca::Comarca():_nom(""),_codi(0),_capital("") {}

bool Comarca::llegirComarca()
{
	cout << "llegin Comarca" << endl;
	cin >> _codi;
	if (_codi == 0)return false;
	cin.ignore(100, '\n');
	getline(cin, _nom);
	getline(cin, _capital);
	return true;
}

void Comarca::mostrarComarca() const
{
	//30: Ribera d'Ebre, Móra d'Ebre
	cout << _codi << ": " << _nom << ", " << _capital << endl;
}

bool Comarca::operator==(const Comarca &o)
{
	return o._codi==_codi;
}

unsigned Comarca::getCodi() const
{
	return _codi;
}

string Comarca::getNom() const
{
	return string(_nom);
}

string Comarca::getComarca() const
{
	return string(_capital);
}

void Comarca::afegeixCodi(unsigned codi)
{
	_codi=codi;
}


Comarca::~Comarca(){}
