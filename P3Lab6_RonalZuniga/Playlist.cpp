#include "Playlist.hpp"

Playlist::Playlist(){
}

Playlist::Playlist(string _nombre){
	this->nombre = _nombre;
}

string Playlist::getNombre(){
	return this->nombre;
}

vector<Cancion*> Playlist::getCanciones(){
	return this->canciones;
}

