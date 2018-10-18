#include "Refugi.h"
//Nom:Ibrahima Sory Diallo
//Usuari:u1939649
//Practica Nº:S1
Refugi::Refugi()
{
	_nom = "";
	_alcada = 0;
	_tlf = "";
	_codi = 0;
}

Refugi::Refugi(std::string nom, unsigned alcada, float longi,float lat, string telef,unsigned codi)
{
	_nom = nom;
	_alcada =alcada;
	_tlf = telef;
	_codi = codi;
}

void Refugi::mostrar(const vector<Comarca> comarques) const
{
	//) Tel: 619 239 860 Comarca: 14(Berguedà)

	std::cout << _nom << ": (" << _alcada << "m)";
	_coordenades.mostrarCordenada();
		cout<< " Tel: " <<_tlf <<"  Comarca: "<<_codi<<"( "<<comarques[_codi].getNom()<<")"<< endl;
}

void Refugi::llegir()
{
	std::cin.ignore(100, '\n');
	getline(cin,_nom);
	cin >> _alcada;
	_coordenades.llegirCoordenada();
	std::cin.ignore(100, '\n');
	getline(cin,_tlf);
	//cin >> _codi;
}

bool Refugi::operator<(const Refugi & o) const
{
	return _alcada<o._alcada;
}


unsigned Refugi::getAlcada() const
{
	return _alcada;
}

Coordenada Refugi::getCoordenada() const
{
	return _coordenades;
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
