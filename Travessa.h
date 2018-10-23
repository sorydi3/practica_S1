#pragma once
#include <iostream>
#include<string>
#include<list>
class Travessa
{
public:
	Travessa();
	Travessa(std::string nom, std::string tel, bool circular);
	void afegeixRefugi(std::string const &nom);
	~Travessa();
private:
	std::string _nom;
	std::string _tel;
	bool _circular;
	std::list<std::string> _refugis;

};

