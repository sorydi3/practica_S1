#pragma once
//Nom:Ibrahima Sory Diallo
//Usuari:u1939649
//Practica Nº:S1
#include<string>
#include<iostream>
using namespace std;
class Cim
{
public:
	//contructor
	Cim();//pre:-- ;post:cim buid
	Cim(std::string nom, unsigned alcada, float longi, float lat);
	void mostrar()const;//pre:--,post:mostra info de *this
	bool operator<(const Cim & o)const;//pre:--;post:retorna cert si this es menor que o
	void llegir();//pre:--;//post:llegeix info per *this
	float getLong()const;//pre:--;post:retorna la longitud
	float getLat()const;//pre:--;post:retorna la latitud
	string getNom()const;//pre:--;post:retorna el nom
	~Cim();//destructor
private:
	std::string _nom;
	unsigned _alcada;
	float _long;
	float _lat;
};

