#include "Refugi.h"
//Nom:Ibrahima Sory Diallo
//Usuari:u1939649
//Practica Nº:S1
Refugi::Refugi()
{
	_nom = "";
	_long = 0.0;
	_lat = 0.0;
	_alcada = 0;
	_tlf = "";
}

Refugi::Refugi(std::string nom, unsigned alcada, float longi,float lat, string telef)
{
	_nom = nom;
	_long = longi;
	_lat = lat;
	_alcada =alcada;
	_tlf = telef;
}

void Refugi::mostrar() const
{
	
	std::cout << _nom << ": (" << _alcada << "m)" << "  ( " << _long << " , " << _lat << " ) Tel: " << _tlf << endl;
}

void Refugi::llegir()
{
	std::cin.ignore(100, '\n');
	getline(cin,_nom);
	cin >> _alcada;
	cin >> _long;
	cin >> _lat;
	std::cin.ignore(100, '\n');
	getline(cin,_tlf);
}

bool Refugi::operator<(const Refugi & o) const
{
	return _alcada<o._alcada;
}

float Refugi::getLong() const
{
	return _long;
}

unsigned Refugi::getAlcada() const
{
	return _alcada;
}

float Refugi::getLat() const
{
	return _lat;
}

string Refugi::getNom() const
{
	return _nom;
}




Refugi::~Refugi()
{

}
