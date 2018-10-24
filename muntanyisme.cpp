// muntanyisme.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//Nom:Ibrahima Sory Diallo
//Usuari:u1939649
//Practica Nº:S1
#define _USE_MATH_DEFINES
#include<cmath>
#include <iostream>
#include "Refugi.h"
#include"Cim.h"
#include <string>
#include <list>
#include<algorithm>
#include<iterator>
#include<vector>
#include"Comarca.h"
#include<map>
#include<set>

using namespace std;
//pre:cert
//post:ha llegit un refugi o un cim
template<typename T >
void llegir(T &type) {
	type.llegir();
}

//pre:--
//post:mostra info de un cim o un refugi
template <typename T,typename G,typename H,typename C>
void mostrar(T &list, G &it,H type,C comarques) {
	for (it = list.begin(); it != list.end(); it++) {
		type = *it;
		type.mostrar(comarques);
		
	}
}
//pre:--
//post:mostra info de totes les comarques
template <typename T, typename G, typename H>
void mostrar_c(T &list, G &it, H type) {
	for (it = list.begin(); it != list.end(); it++) {
		type = it->second;
		if(type.getCodi()!=0)
	    type.mostrarComarca();
	}
}

//pre:cert
//post:retorna la distancia entre dues coordenades
double distancia(float lon1,float lat1,float lon2 ,float lat2) {
	double distance=sqrt(pow(lat1 - lat2, 2) + pow(lon1*cos(lat1 / 180 * M_PI) - lon2 * cos(lat2 / 180 * M_PI), 2))*111319.9;
	return distance;
}
//pre:cert
//post:retorna refugi   si nom existeix en la llista de refugis
Refugi cerca(string nom, bool &trobat, set<Refugi> refugis) {
	cout << "Cercan Refugi ..." << endl;
	set<Refugi>::iterator it = refugis.begin();
	Refugi refugi;
	while (it!=refugis.end() && !trobat)
	{
		refugi = *it;
		if (refugi.getNom() == nom)trobat = true;
		else it++;
	}
	return refugi;
}

//pre:--
//post:mostra distància en línia recta a tots els cims que hi hagi a la llista de cims
void distanciaCims(set<Cim>list, Refugi refugi) {
	for (auto l : list) {
		cout <<"                                 "<< l.getNom() << " a " <<refugi.getCoordenada()-l.getCoordenada()<< " metres" << endl;
	}
}

unsigned LlegeixCodi(map<unsigned,Comarca> comarques,unsigned &codi) {
	//pre:--
	//post:retorna un codi existen dintre del vector comarques
	cout << "Entra el codi" << endl;
	map<unsigned, Comarca>::iterator vIt;
	cin >> codi;
	Comarca comarca;
	comarca.afegeixCodi(codi);
	bool trobat = false;
	while (!trobat)
	{
		//vIt = find(comarques.begin(), comarques.end(),pair<unsigned, );
	    auto t = comarques.find(codi);
		if (t != comarques.end())trobat = true;
		else if (codi == 0)return 0;//termina bucle cim
		else
		{
			cout << "Codi inexisten" << endl;
			cin >> codi;
			comarca.afegeixCodi(codi);
		}
	}
	return codi;
}

void llegeixComarques(map<unsigned, Comarca> &vComarques){
	unsigned codi;
	string nom, capital;
	do
	{
		cin >> codi;
		if (codi == 0)break;
		cin.ignore(100, '\n');
		getline(cin, nom);
		getline(cin, capital);
		Comarca comarca(codi, nom, capital);
		vComarques.insert(pair<unsigned, Comarca>(codi, comarca));
	} while (true);
	}

Cim llegeixCim() {
	string nom;
	unsigned alcada;
	Coordenada coordenada;
		std::cin.ignore(100, '\n');
		getline(cin, nom);
		cin >> alcada;
		coordenada.llegirCoordenada();
		Cim cim(nom, alcada, coordenada);
		return cim;
}

Refugi llegeixRefugi() {
	string nom;
	unsigned alcada;
	string tlf;
	Coordenada coordenada;
	std::cin.ignore(100, '\n');
	getline(cin, nom);
	cin >> alcada;
	coordenada.llegirCoordenada();
	std::cin.ignore(100, '\n');
	getline(cin, tlf);
	Refugi refugi(nom, alcada, coordenada,tlf);
	return refugi;
}

//MAIN
int main()
{
	//vector<Comarca>vComarques;
	//vector<Comarca>::iterator vIt;
	map<unsigned, Comarca> vComarques1;
	map<unsigned, Comarca>::iterator it;
	llegeixComarques(vComarques1);
	for ( it = vComarques1.begin(); it != vComarques1.end(); it++)
	{
		it->second.mostrarComarca();
	}
//////////////////////////////////////////////////////////////
	
	set<Refugi> listRefugis;//llista de refugis
	set<Refugi> ::iterator itRef;//iterador per la llista de refugis
	set<Cim> listCims;//llista cims
	set<Cim>:: iterator itCim;
	string opcio;
	std::cin >> opcio;
	unsigned codi;
	while (opcio!="*")
	{
		if (opcio=="cim")
		{
			
			Cim cim=llegeixCim();
			
			while (LlegeixCodi(vComarques1,codi) != 0)
			{
				cim.afegeixCodi(codi);
			}
			listCims.insert(cim);
		}else{
			Refugi refugi = llegeixRefugi();
			LlegeixCodi(vComarques1,codi);
			refugi.afegeixCodi(codi);
			listRefugis.insert(refugi);
		}
		std::cin >> opcio;
	}
	    cout << "COMARQUES" << endl;
		cout << "============\n";
		Comarca cmrca;
		mostrar_c(vComarques1, it, cmrca);//mostra él vector de comarques
		Cim cim;
		Refugi refugi;
		cout << "CIMS" << endl;
		cout << "============\n";
		mostrar(listCims, itCim, cim,vComarques1);
		cout << endl;
		cout << "REFUGIS" << endl;
		cout << "============\n";
		mostrar(listRefugis, itRef, refugi,vComarques1);

		itRef = listRefugis.begin();
		string nom;
		std::cin.ignore(100, '\n');
		getline(std::cin, nom);
		while (nom!="*")
		{
			bool trobat = false;
			Refugi refugiCentral=cerca(nom, trobat, listRefugis);
			if (trobat) {
				cout << "Nom Refugi:" << endl;
				refugiCentral.mostrar(vComarques1);
				set<Refugi>::reverse_iterator rit = listRefugis.rbegin();
				Refugi refugiMaxDistancia = *rit;
				itRef = listRefugis.begin();
				Refugi refugiMinDistancia = *itRef;
				cout<< "                     "
					<< refugiCentral.getAlcada()-refugiMinDistancia.getAlcada()
					 <<" metres més que el més baix"<< endl;
				cout <<"                     "
					<< refugiMaxDistancia.getAlcada()-refugiCentral.getAlcada()<<"  metres menys que el més alt"<<endl;
				cout <<"distancies als cims" << endl;
				cout << "---------------------------" << endl;
				distanciaCims(listCims, refugiCentral);
			}
			else
			{
				cout << "Nom refugi: [ " << nom << " ] no trobat" << endl;
			}
			getline(std::cin, nom);
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

