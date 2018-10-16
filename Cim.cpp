#include "Cim.h"
Cim::Cim()
{
	_nom = "";
	_long = 0.0;
	_lat = 0.0;
	_alcada = 0;
}

Cim::Cim(std::string nom, unsigned alcada, float longi, float lat)
{
	_nom = nom;
	_long = longi;
	_lat = lat;
	_alcada = alcada;
}

void Cim::mostrar() const
{
	cout << _nom << ": (" << _alcada << "m)" << "  (" << _long << " " << _lat << ")" << endl;
}

void Cim::llegir()
{
	std::cin.ignore(100, '\n');
	getline(cin, _nom);
	cin >> _alcada;
	cin >> _long;
	cin >> _lat;
}

float Cim::getLong() const
{
	return _long;
}

float Cim::getLat() const
{
	return _lat;
}

string Cim::getNom() const
{
	return _nom;
}


Cim::~Cim()
{
}
