#pragma once
//Nom:Ibrahima Sory Diallo
//Usuari:u1939649
//Practica Nº:S1
#include<string>
#include<iostream>
#include"Coordenada.h"
#include"Comarca.h"
#include<vector>
#include<map>
#include<list>
using namespace std;
class Cim
{
public:
	//contructor
	Cim();//pre:-- ;post:cim buid
	Cim(std::string nom, unsigned alcada, Coordenada coordenada);
	void mostrar()const;//pre:--,post:mostra info de *this
	void mostrar( map<unsigned,Comarca> comarques)const;
	bool operator<(const Cim & o)const;//pre:--;post:retorna cert si this es menor que o
	void llegir();//pre:--;//post:llegeix info per *this
	void afegeixCodi(unsigned codi);//pre:--,post:ha afegit un codi a la llista de codis
	Coordenada getCoordenada()const;//pre:--;post:retorna la longitud
	float getLat()const;//pre:--;post:retorna la latitud
	string getNom()const;//pre:--;post:retorna el nom
	~Cim();//destructor
private:
	std::string _nom;
	unsigned _alcada;
	Coordenada _coordenada;
	list<int> _comarques;
};

