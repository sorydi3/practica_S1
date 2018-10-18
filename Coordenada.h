#pragma once
//Nom:Ibrahima Sory Diallo
//Usuari:u1939649
//Practica N�:S1
#define _USE_MATH_DEFINES
#include<cmath>
#include<iostream>
using namespace std;
class Coordenada
{
public:
	Coordenada();//constructor
	void llegirCoordenada();//pre:-- ,post:llegeix una coordenda
	void mostrarCordenada()const;//pre:cert, post:mostra la coordenada concatenat en un string 
	double operator -(const Coordenada & o);//pre:coordenada ,post:fa la diferencia entre dues coordenades
	double distance(float lat, float longi)const; //pre:cert,post:retorna la distancia
	~Coordenada();//destructor
private:
	float _longi;
	float _lat;
};

