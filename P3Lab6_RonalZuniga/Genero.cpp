#include "Genero.hpp"

Genero::Genero(){
	
}

Genero::Genero(string _nombre){
	this->nombre = _nombre;
}

string Genero::getNombreG(){
	return this->nombre;
}

void Genero::setNombreG(string _nombre){
	this->nombre = _nombre;
}