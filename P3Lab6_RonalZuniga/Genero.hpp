#ifndef GENERO_HPP
#define GENERO_HPP
#include <iostream>
#include <string>
using namespace std;

class Genero{
	private:
		string nombre;
	public:
		Genero();
		Genero(string);
		string getNombreG();
		void setNombreG(string);
};
#endif