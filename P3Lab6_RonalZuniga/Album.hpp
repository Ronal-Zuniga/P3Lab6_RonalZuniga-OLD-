#ifndef ALBUM_HPP
#define ALBUM_HPP
#include <iostream>
#include <string>
#include <vector>
#include "Cancion.hpp"
#include "Playlist.hpp"
using namespace std;

class Album{
	private:
		string nombre;
		vector<Cancion*> canciones;
		string artista;
	public:
		Album();
		Album(string);
		Album* operator+(Cancion* c);
		//Playlist* operator*(const int n);
		void setArtistaA();
		string getNombre();
		vector<Cancion*> getCanciones();
		string getArtista();
		void setCanciones(vector<Cancion*>);
		void setNombre(string);
		//~Album();
};
#endif