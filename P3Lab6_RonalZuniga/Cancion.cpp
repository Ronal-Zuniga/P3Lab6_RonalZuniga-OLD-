#include "Cancion.hpp"

Cancion::Cancion(){
	
} 
Cancion::Cancion(string _nombre, string _artista, Genero* _genero, string _duracion){
	this->nombre = _nombre;
	this->artista = _artista;
	this->genero = _genero;
	this->duracion = _duracion;
}

string Cancion::getNombre(){
	return this->nombre;
}

void Cancion::setNombre(string _nombre){
	this->nombre = _nombre;
}

string Cancion::getArtista(){
	return this->artista;
}

void Cancion::setArtista(string _artista){
	this->artista = _artista;
}

Genero* Cancion::getGenero(){
	return this->genero;
}

void Cancion::setGenero(Genero* _genero){
	this->genero = _genero;
}

string Cancion::getDuracion(){
	return this->duracion;
}

void Cancion::setDuracion(string _duracion){
	this->duracion = _duracion;
}