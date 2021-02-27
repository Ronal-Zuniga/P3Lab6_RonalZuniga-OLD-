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

void Playlist::operator+(const Cancion& c){
	this->canciones.push_back(*c);
}

Playlist Playlist::operator+(const Playlist& p){
	Playlist pl;
	
	return pl;
}

void Playlist::operator-(const Cancion& c){
	this->canciones.erase(*c);
}
