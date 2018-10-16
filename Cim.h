#pragma once
#include<string>
#include<iostream>
using namespace std;
class Cim
{
public:
	Cim();
	Cim(std::string nom, unsigned alcada, float longi, float lat);
	void mostrar()const;
	void llegir();
	float getLong()const;
	float getLat()const;
	string getNom()const;
	~Cim();
private:
	std::string _nom;
	unsigned _alcada;
	float _long;
	float _lat;
};

