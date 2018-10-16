#pragma once
#include <string>
#include<iostream>
using namespace std;
class Refugi
{
public:
	Refugi();
	Refugi(std::string nom, unsigned alcada, float longi, float lat, string telef);
	void mostrar()const;
	void llegir();
	bool operator<(const Refugi & o)const;
	float getLong()const;
	float getLat()const;
	string getNom()const;
	~Refugi();
private:
	std::string _nom;
	unsigned _alcada;
	float _long;
	float _lat;
	string _tlf;
};

