#include "Refugi.h"
//Nom:Ibrahima Sory Diallo
//Usuari:u1939649
//Practica N�:S1
Refugi::Refugi()
{
	_nom = "";
	_long = 0.0;
	_lat = 0.0;
	_alcada = 0;
	_tlf = "";
	_codi = 0;
}

Refugi::Refugi(std::string nom, unsigned alcada, float longi,float lat, string telef,unsigned codi)
{
	_nom = nom;
	_long = longi;
	_lat = lat;
	_alcada =alcada;
	_tlf = telef;
	_codi = codi;
}

void Refugi::mostrar(const vector<Comarca> comarques) const
{
	//) Tel: 619 239 860 Comarca: 14(Bergued�)

	std::cout << _nom << ": (" << _alcada << "m)" << "  ( " << _long << " , " << _lat << " ) Tel: " <<
		_tlf <<"  Comarca: "<<_codi<<"( "<<comarques[_codi].getNom()<<")"<< endl;
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
	cin >> _codi;
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

unsigned Refugi::getCodi() const
{
	return _codi;
}

string Refugi::getNom() const
{
	return _nom;
}
void Refugi::afegeixCodi(unsigned codi)
{
	_codi = codi;
	cout << "codi Afegit Correctament" << endl;
}



Refugi::~Refugi()
{

}
