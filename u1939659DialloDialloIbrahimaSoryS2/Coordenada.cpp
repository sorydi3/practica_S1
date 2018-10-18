#include "Coordenada.h"
// Nom:Ibrahima Sory Diallo
//Usuari:u1939649
//Practica Nº:S1
Coordenada::Coordenada():_longi(0.0),_lat(0.0){}
void Coordenada::llegirCoordenada()
{
	cin >> _longi;
	cin >> _lat;
}

void Coordenada::mostrarCordenada()const
{
	std::cout<< "  ( " << _longi << " , " << _lat << " )";
}


Coordenada::~Coordenada()
{
}

double Coordenada::operator-(const Coordenada & o)
{
	return distance(o._longi,o._lat);
}

double Coordenada::distance(float lon1, float lat1)const {
	double distance = sqrt(pow(lat1 - _lat, 2) + pow(lon1*cos(lat1 / 180 * M_PI) - _longi * cos(_lat / 180 * M_PI), 2))*111319.9;
	return distance;
}
