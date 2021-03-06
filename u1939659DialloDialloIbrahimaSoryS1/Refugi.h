#pragma once
//Nom:Ibrahima Sory Diallo
//Usuari:u1939649
//Practica N�:S1
#include <string>
#include<iostream>
using namespace std;
class Refugi
{
public:
	Refugi();//constructor--/pre:-- ;post:cim buid
	Refugi(std::string nom, unsigned alcada, float longi, float lat, string telef);
	void mostrar()const;//pre:--,post:mostra info de *this
	void llegir();//pre:--;//post:llegeix info per *this
	bool operator<(const Refugi & o)const; // pre:--; post:retorna cert si this es menor que o
	float getLong()const;//pre:--;post:retorna la longitud
	unsigned getAlcada()const;//pre:--;post:retorna l�alcada
	float getLat()const;//pre:--;post:retorna la latitud
	string getNom()const;//pre:--;post:retorna el nom
	~Refugi();//destructor
private:
	std::string _nom;
	unsigned _alcada;
	float _long;
	float _lat;
	string _tlf;
};

