#include "Cim.h"
//Nom:Ibrahima Sory Diallo
//Usuari:u1939649
//Practica Nº:S1
Cim::Cim()
{
	_nom = "";
	_alcada = 0;
}

Cim::Cim(std::string nom, unsigned alcada,Coordenada coordenada)
{
	_nom = nom;
	_coordenada = coordenada;
	_alcada = alcada;
}

void Cim::mostrar() const
{
	//) comarca: 14 15 (Berguedà,Cerdanya)

	cout << _nom << ": (" << _alcada << "m)";
	_coordenada.mostrarCordenada();
	cout << endl;
}

void Cim::mostrar(map<unsigned ,Comarca> comarques) const
{
	cout << _nom << ": (" << _alcada << "m)";
	_coordenada.mostrarCordenada();
	for (auto l : _comarques) {
		cout << l << " ";
	}
	cout << " ( ";
	for (auto c : _comarques) {
		cout << comarques.find(c)->second.getNom() << ", ";
	}
	cout << " ) " << endl;
	
}

bool Cim::operator<(const Cim & o) const
{
	return _nom < o._nom;
}


void Cim::afegeixCodi(unsigned codi)
{
	_comarques.push_front(codi);
	cout << "afegit correctament a la llista" << endl;
}

Coordenada Cim::getCoordenada() const
{
	return _coordenada;
}

string Cim::getNom() const
{
	return _nom;
}


Cim::~Cim()
{
}
