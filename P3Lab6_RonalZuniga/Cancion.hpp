#ifndef CANCION_HPP
#define CANCION_HPP
#include <iostream>
#include <String>
#include "Genero.hpp"
using namespace std;

class Cancion{
	private:
		string nombre;
		string artista;
		Genero* genero;
		string duracion;
	public:
		Cancion();
		Cancion(string, string, Genero*, string);
		string getNombre();
		void setNombre(string);
		string getArtista();
		void setArtista(string);
		Genero* getGenero();
		void setGenero(Genero*);
		string getDuracion();
		void setDuracion(string);
};
#endif