#pragma once
#include<string>
#include<iostream>
using namespace std;
// Nom:Ibrahima Sory Diallo
//Usuari:u1939649
//Practica Nº:S1
class Comarca
{
public:
	Comarca();//constructor
	Comarca(unsigned codi, string nom, string capital);
	void mostrarComarca()const;//pre:--,post:mostra *this comarca
	bool operator ==(const Comarca &c);
	unsigned getCodi()const;//pre:--,post:retorna el codi
	string getNom()const;//pre:--,post:retorna el codi
	string getComarca()const;//pre:cert:retorna el nom de la comarca
	void afegeixCodi(unsigned codi);
	~Comarca(); //destructor
private:
	//atributs
	unsigned _codi;
	string _nom;
	string _capital;
};

