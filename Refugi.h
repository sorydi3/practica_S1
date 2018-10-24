#pragma once
//Nom:Ibrahima Sory Diallo
//Usuari:u1939649
//Practica Nº:S1
#include <string>
#include<iostream>
#include<vector>
#include<map>
#include"Comarca.h"
#include"Coordenada.h"
using namespace std;
class Refugi
{
public:
	Refugi();//constructor--/pre:-- ;post:cim buid
	Refugi(std::string nom, unsigned alcada,Coordenada coordenada, string telef);
	void mostrar(map<unsigned,Comarca> comarques)const;//pre:--,post:mostra info de *this
	void llegir();//pre:--;//post:llegeix info per *this
	bool operator<(const Refugi & o)const; // pre:--; post:retorna cert si this es menor que o
	Coordenada getCoordenada()const;//pre:--;post:retorna la longitud
	unsigned getAlcada()const;//pre:--;post:retorna l´alcada
	unsigned getCodi()const;//pre:--,post:retorna el codi de la comarca
	void afegeixCodi(unsigned codi);
	string getNom()const;//pre:--;post:retorna el nom
	~Refugi();//destructor
private:
	std::string _nom;
	unsigned _alcada;
	Coordenada _coordenades;
	string _tlf;
	unsigned _codi;
};

