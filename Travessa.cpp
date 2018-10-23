#include "Travessa.h"



Travessa::Travessa():_nom(""),_tel(""),_circular(false){}

Travessa::Travessa(std::string nom, std::string tel, bool circular):_nom(nom),_tel(tel),_circular(circular)
{
	_refugis.clear();
}

void Travessa::afegeixRefugi(std::string const & nom)
{
	//TO DO :FALTA COMPROBAR SI EXISTEIX NO FER RES
	_refugis.push_back(nom);
}


Travessa::~Travessa()
{
}
