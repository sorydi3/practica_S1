#pragma once
#define _USE_MATH_DEFINES
#include<cmath>
#include<iostream>
using namespace std;
class Coordenada
{
public:
	Coordenada();//constructor
	void llegirCoordenada();//pre:-- ,post:llegeix una coordenda
	void mostrarCordenada();//pre:cert, post:mostra la coordenada concatenat en un string 
	double operator -(Coordenada & o);//pre:coordenada ,post:fa la diferencia entre dues coordenades
	double distance(float lat, float longi)const; //pre:cert,post:retorna la distancia
	~Coordenada();//destructor
private:
	float _longi;
	float _lat;
};

