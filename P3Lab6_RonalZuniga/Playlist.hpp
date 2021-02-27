#ifndef PLAYLIST_HPP
#define PLAYLIST_HPP
#include <iostream>
#include <string>
#include "Cancion.hpp"
#include "Album.hpp"
#include "Genero.hpp"
using namespace std;

class Playlist{
	private:
		string nombre;
		vector<Cancion*> canciones;
	public:
		Playlist();
		Playlist(string);
		//~Playlist();
		void operator+(const Cancion& c);
		void operator+(const Album&);
		Playlist operator+(const Playlist& p);
		void operator-(const Cancion& c);
		void operator-(const Genero& g);
		string getNombre();
		vector<Cancion*> getCanciones();
};
#endif