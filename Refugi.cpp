#include "pch.h"
#include "Refugi.h"
Refugi::Refugi()
{
	_nom = "";
	_long = 0.0;
	_lat = 0.0;
	_alcada = 0;
	_tlf = 0;
}

Refugi::Refugi(std::string nom, unsigned alcada, double longi, double lat, unsigned telef)
{
	_nom = nom;
	_long = longi;
	_lat = lat;
	_alcada =alcada;
	_tlf = telef;
}

void Refugi::mostrar() const
{
	std::cout << _nom << ": (" << _alcada << ")" << "  (" << _long << " " << _lat << ") Tel: " << _tlf << endl;
}

void Refugi::llegir()
{
	std::cin.ignore(100, '\n');
	getline(cin,_nom);
	cin >> _alcada;
	cin >> _long;
	cin >> _lat;
	cin >> _tlf;
}




Refugi::~Refugi()
{

}
