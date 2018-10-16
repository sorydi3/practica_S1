// muntanyisme.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "Refugi.h"
#include"Cim.h"
#include <string>
#include <list>
#include<iterator>
#include<cmath>

using namespace std;
template<typename T >
void llegir(T &type) {
	type.llegir();
}

template <typename T,typename G,typename H>
void mostrar(T &list, G &it,H type) {
	for (it = list.begin(); it != list.end(); it++) {
		type = *it;
		type.mostrar();
	}
}
double distancia(double lon1,double lat1,double lon2 ,double lat2) {
	double distance=sqrt(pow(lat1 - lat2, 2) + pow(lon1*cos(lat1 / 180 * 3.14159265358979323846) - lon2 * cos(lat2 / 180 * 3.14159265358979323846), 2))*111319.9;
	return distance;
}

Refugi cerca(string nom, bool &trobat, list<Refugi> refugis) {
	cout << "Cercan Refugi ..." << endl;
	list<Refugi>::iterator it = refugis.begin();
	Refugi refugi;
	while (it!=refugis.end() && !trobat)
	{
		refugi = *it;
		if (refugi.getNom() == nom)trobat = true;
		it++;
	}
	//cout << "Refugi trobat" << endl;
	return refugi;
}

void distanciaCims(list<Cim>list, Refugi refugi) {
	for (auto l : list) {
		//Comabona a 14230.6 metres
		//l.mostrar();
		cout <<"                                 "<< l.getNom() << " a " << distancia(l.getLong(), l.getLat(),
			refugi.getLong(), refugi.getLat()) << " metres" << endl;
	}
}
int main()
{
	list<Refugi> listRefugis;
	list<Refugi> ::iterator itRef;
	list<Cim> listCims;
	list<Cim>:: iterator itCim;
	string opcio;
	std::cin >> opcio;
	while (opcio!="*")
	{
		if (opcio=="cim")
		{
			Cim cim;
			llegir(cim);
			listCims.push_front(cim);
			//cim.mostrar();
		}else{
			Refugi refugi;
			llegir(refugi);
			listRefugis.push_front(refugi);
			//refugi.mostrar();
		}
		std::cin >> opcio;
	}
		Cim cim;
		Refugi refugi;
		cout << "CIMS" << endl;
		cout << endl;
		cout << "============\n";
		cout << endl;
		mostrar(listCims, itCim, cim);
		cout << endl;
		cout << "REFUGIS" << endl;
		cout << endl;
		cout << "============\n";
		mostrar(listRefugis, itRef, refugi);
		listRefugis.sort();

		itRef = listRefugis.begin();
		//cout << "Entra nom refugi " << endl;
		string nom;
		//cin >> nom;
		std::cin.ignore(100, '\n');
		getline(std::cin, nom);
		//cout << "nom es ------------->" << nom << endl;
		while (nom!="*")
		{
			bool trobat = false;
			Refugi refugiCentral=cerca(nom, trobat, listRefugis);
			if (trobat) {
				cout << "Nom Refugi:" << endl;
				refugiCentral.mostrar();
				list<Refugi>::reverse_iterator rit = listRefugis.rbegin();
				Refugi refugiMaxDistancia = *rit;
				itRef = listRefugis.begin();
				Refugi refugiMinDistancia = *itRef;
				cout<< "                     "
					<< distancia(refugiCentral.getLong(), refugiCentral.getLat(),
						refugiMinDistancia.getLong(), refugiMinDistancia.getLat()) <<" metres m�s que el m�s baix"<< endl;
				cout <<"                     "
					<< distancia(refugiCentral.getLong(), refugiCentral.getLat(),
						refugiMaxDistancia.getLong(), refugiMaxDistancia.getLat())<<"  metres menys que el m�s alt"<<endl;
				cout <<"distancies als cims" << endl;
				cout << "---------------------------" << endl;
				distanciaCims(listCims, refugiCentral);
			}
			else
			{
				//Nom refugi: [Restanca] no trobat
				cout << "Nom refugi: [ " << nom << " ] no trobat" << endl;
			}
			//cout << "Entra nom refugi " << endl;
			//std::cin.ignore(100, '\n');
			getline(std::cin, nom);
		   // cout << "nom es ------------->" << nom << endl;
		}
			
    std::cout << "Done!\n"; 
	return EXIT_SUCCESS;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

