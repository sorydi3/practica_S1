#pragma once
#include<string>
#include<iostream>
using namespace std;
class Comarca
{
public:
	Comarca();//constructor
	bool llegirComarca();//pre:--,post:llegeix una comarca en teclat 
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

