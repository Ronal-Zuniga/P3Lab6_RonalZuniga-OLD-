#include "Album.hpp"

Album::Album() {
}

Album::Album(string _nombre) {
	this->nombre = _nombre;
}

void Album::setArtistaA(){
	bool flag;
	string _artista;
	for (int i = 0; i < this->canciones.size() - 1; i++){
		Cancion* c1 = canciones[i];
		Cancion* c2 = canciones[i + 1];
		if(c1->getArtista() != c2->getArtista()){
			flag = true;
			i = this->canciones.size();
		} else{
			flag = false;
			_artista = c1->getArtista();
		}
		delete c1;
		delete c2;
	}
	if(flag){
		this->artista = "Various Artist";
	} else{
		this->artista = _artista;
	}
}

string Album::getArtista(){
	setArtistaA();
	return this->artista;
}

string Album::getNombre(){
	return this->nombre;
}

vector<Cancion*> Album::getCanciones(){
	return this->canciones;
}