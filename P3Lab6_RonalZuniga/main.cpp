#include <iostream>
#include <string>
#include <vector>
#include "Cancion.hpp"
#include "Genero.hpp"
#include "Album.hpp"
#include "Playlist.hpp"
using namespace std;
int menuGeneral();
int subMenu();
int menuGenero();
int menuCanciones();
int menuAP();
int subMenuOP();
int menuMult();
int menuSum();
int menuRest();
int menuAlbum();

int main(int argc, char** argv) {
	int menuG;
	vector<Genero*> generos;
	vector<Cancion*> canciones;
	vector<Album*> albums;
	vector<Playlist*> playlist;
	while((menuG = menuGeneral()) != 3) {
		switch(menuG) {
			case 1: {
				int sbm1;
				while((sbm1 = subMenu()) != 4) {
					switch(sbm1) {
						case 1: {
							int mGenero;
							while((mGenero = menuGenero()) != 5) {
								switch(mGenero) {
									case 1: {
										string nomg;
										cout << "Ingrese el nombre del genero: ";
										cin >> nomg;
										Genero* gen = new Genero(nomg);
										if(generos.empty()) {
											generos.push_back(gen);
											cout << "Genero agregado correctamente";
										} else {
											bool flag;
											for(int i = 0; i < generos.size(); i++) {
												Genero* g = generos[i];
												if(g->getNombreG() == nomg) {
													flag = true;
													i = generos.size();
												} else {
													flag = false;
												}
												delete g;
											}
											if(flag) {
												cout << "El genero no se ha agregado porque ya existe" << endl;
											} else {
												generos.push_back(gen);
												cout << "Genero agregado correctamente" << endl;
											}
										}
										cout << endl;
										cout << endl;
										delete gen;
										break;
									}
									case 2: {
										string ng, nuevog;
										cout << "Ingrese el nombre del genero a modificar: ";
										cin >> ng;
										cout << "Ingrese el nuevo nombre del genero: ";
										cin >> nuevog;
										bool flag;
										for(int i = 0; i < generos.size(); i++) {
											Genero* g = generos[i];
											if(g->getNombreG() == ng) {
												flag = true;
												g->setNombreG(nuevog);
												i = generos.size();
											} else {
												flag = false;
											}
											delete g;
										}
										if(flag) {
											cout << "El genero se ha modificado" << endl;
										} else {
											cout << "Genero no encontrado" << endl;
										}
										cout << endl;
										cout << endl;
										break;
									}
									case 3: {
										string nomg;
										cout << "Ingrese el nombre del genero a eliminar: ";
										cin >> nomg;
										bool flag;
										for(int i = 0; i < generos.size(); i++) {
											Genero* g = generos[i];
											if(g->getNombreG() == nomg) {
												flag = true;
												generos.erase(generos.begin() + i);
												i = generos.size();
											} else {
												flag = false;
											}
											delete g;
										}
										if(flag) {
											cout << "El genero no se ha eliminado" << endl;
										} else {
											cout << "Genero no encontrado" << endl;
										}
										cout << endl;
										cout << endl;
										break;
									}
									case 4: {
										cout << endl;
										cout << "Generos guardados" << endl;
										for(int i = 0; i < generos.size(); i++) {
											Genero* g = generos[i];
											cout << g->getNombreG() << endl;
											delete g;
										}
										cout << endl;
										cout << endl;
										break;
									}
								}//fs
							}//fw
							break;
						}

						case 2: {
							int mCancion;
							while((mCancion = menuCanciones()) != 5) {
								switch(mCancion) {
									case 1: {
										string name, art, d;
										Genero* g;
										cout << "Ingrese el nombre de la cancion: ";
										cin >> name;
										cout << "Ingrese el artista de la cancion: ";
										cin >> art;
										cout << "Ingrese la duracion de la cancion (formato mm:ss): ";
										cin >> d;
										cout << "Generos guardados" << endl;
										for(int i = 0; i < generos.size(); i++) {
											Genero* g = generos[i];
											cout << i << ". " << g->getNombreG() << endl;
											delete g;
										}
										cout << endl;
										int pos;
										cout << "Ingrese la posicion del genero de la cancion: ";
										cin>>pos;
										g = generos[pos];
										Cancion* c = new Cancion(name, art, g, d);
										if(canciones.empty()) {
											canciones.push_back(c);
										} else {
											bool flag;
											for(int i = 0; i<canciones.size(); i++) {
												Cancion* can = canciones[i];
												if(can->getNombre() == name) {
													flag = true;
													i = canciones.size();
												} else {
													flag = false;
												}
												delete can;
											}
											if(flag) {
												cout << "La cancion ya existe" << endl;
											} else {
												canciones.push_back(c);
												cout << "La cancion se agrego correctamente" << endl;
											}
										}
										delete c;
										delete g;
										cout << endl;
										cout << endl;
										break;
									}
									case 2: {
										string nc;
										cout << "Ingrese el nombre de la cancion a modificar: ";
										cin >> nc;
										string name, art, d;
										Genero* g;
										cout << "Ingrese el nuevo nombre de la cancion: ";
										cin >> name;
										cout << "Ingrese el nuevo artista de la cancion: ";
										cin >> art;
										cout << "Ingrese la nueva duracion de la cancion (formato mm:ss): ";
										cin >> d;
										cout << "Generos guardados" << endl;
										for(int i = 0; i < generos.size(); i++) {
											Genero* g = generos[i];
											cout << i << ". " << g->getNombreG() << endl;
											delete g;
										}
										cout << endl;
										int pos;
										cout << "Ingrese la posicion del nuevo genero de la cancion: ";
										cin >> pos;
										g = generos[pos];
										bool flag;
										for(int i = 0; i<canciones.size(); i++) {
											Cancion* can = canciones[i];
											if(can->getNombre() == nc) {
												flag = true;
												can->setNombre(name);
												can->setArtista(art);
												can->setGenero(g);
												can->setDuracion(d);
												i = canciones.size();
											} else {
												flag = false;
											}
											delete can;
										}
										if(flag) {
											cout << "La cancion se ha modificado" << endl;
										} else {
											cout << "La cancion no se encontro" << endl;
										}
										delete g;
										cout << endl;
										cout << endl;
										break;
									}
									case 3: {
										string nc;
										cout << "Ingrese el nombre de la cancion a eliminar: ";
										cin >> nc;
										bool flag;
										for(int i = 0; i<canciones.size(); i++) {
											Cancion* can = canciones[i];
											if(can->getNombre() == nc) {
												flag = true;
												canciones.erase(canciones.begin() + i);
												i = canciones.size();
											} else {
												flag = false;
											}
											delete can;
										}
										if(flag) {
											cout << "La cancion se ha eliminado" << endl;
										} else {
											cout << "La cancion no se encontro" << endl;
										}
										cout << endl;
										cout << endl;
										break;
									}
									case 4: {
										cout << endl;
										cout << "Canciones guardadas" << endl;
										for(int i = 0; i<canciones.size(); i++) {
											Cancion* can = canciones[i];
											cout << can->getNombre() << ",  " << can->getArtista() << ",  "
											     << (can->getGenero())->getNombreG() << ",  " << can->getDuracion() << endl;
											delete can;
										}
										cout << endl;
										cout << endl;
										break;
									}
								}//fs
							}//fw
							break;
						}

						case 3: {
							int mAP;
							while((mAP = menuAP()) != 3) {
								switch(mAP) {
									case 1: {
										cout << endl;
										cout << "Albums guardados" << endl;
										for(int i = 0; i < albums.size(); i++) {
											Album* a = albums[i];
											cout << "Nombre: " << a->getNombre() << endl;
											cout << "Canciones: ";
											for(int j = 0; j<a->getCanciones().size(); j++) {
												Cancion* can = a->getCanciones()[j];
												cout << can->getNombre() << ",  ";
												delete can;
											}
											cout << endl;
											delete a;
										}
										cout << endl;
										cout << endl;
										break;
									}
									case 2: {
										cout << endl;
										cout << "Playlist guardadas" << endl;
										for(int i = 0; i < playlist.size(); i++) {
											Playlist* p = playlist[i];
											cout << "Nombre: " << p->getNombre() << endl;
											cout << "Canciones: ";
											for(int j = 0; j<p->getCanciones().size(); j++) {
												Cancion* can = p->getCanciones()[j];
												cout << can->getNombre() << ",  ";
												delete can;
											}
											cout << endl;
											delete p;
										}
										cout << endl;
										cout << endl;
										break;
									}
								}//fs
							}//fw
							break;
						}
					}//fin switch
				}//fin while
				break;
			}

			case 2: {
				int mOP;
				while((mOP = subMenuOP()) != 4) {
					switch(mOP) {
						case 1: {
							int mm;
							while((mm = menuMult()) != 2) {
								if(mm == 1) {
									
								}
							}
							break;
						}
						case 2: {
							int ms;
							while((ms = menuSum()) != 5) {
								switch(ms) {
									case 1: {
										break;
									}
									case 2: {
										break;
									}
									case 3: {
										int oa;
										while((oa = menuAlbum()) != 3) {
											switch(oa) {
												case 1: {
													cout << endl;
													cout << "Albums guardados" << endl;
													for(int i = 0; i < albums.size(); i++) {
														Album* a = albums[i];
														cout << i << ". " << a->getNombre() << endl;
														delete a;
													}
													cout << endl;
													int posa;
													cout << "Ingrese la posicion del album: ";
													cin >> posa;
													cout << endl;
													Album* aux = albums[posa];
													/*Album a (aux->getNombre());
													a.setCanciones(aux->getCanciones());*/
													cout << "Canciones guardadas" << endl;
													for(int i = 0; i<canciones.size(); i++) {
														Cancion* can = canciones[i];
														cout << i << ". " << can->getNombre() << endl;
														delete can;
													}
													cout << endl;
													int posc;
													cout  << "Ingrese la posicion de la cancion: ";
													cin >> posc;
													cout << endl;
													Cancion* song = canciones[posc];
													//Cancion song2 (song->getNombre(), song->getArtista(), song->getGenero(), song->getDuracion()); 
													Album* ab = aux + song;
													albums[posa] = ab;
													delete aux;
													delete song;
													delete ab;
													cout << endl;
													cout << endl;
													break;
												}
												case 2: {
													string posa;
													cout << "Ingrese el nombre del album: ";
													cin >> posa;
													Album* a = new Album(posa);
													cout << "Canciones guardadas" << endl;
													for(int i = 0; i<canciones.size(); i++) {
														Cancion* can = canciones[i];
														cout << i << ". " << can->getNombre() << endl;
														delete can;
													}
													cout << endl;
													int posc;
													cout  << "Ingrese la posicion de la cancion: ";
													cin >> posc;
													cout << endl;
													Cancion* song = canciones[posc];
													Album* ab = a + song;
													albums[posa] = ab;
													delete song;
													delete a;
													delete ab;
													cout << endl;
													cout << endl;
													break;
												}
											}
										}//fw
										break;
									}
									case 4: {
										
										break;
									}
								}//fs
							}//fw
							break;
						}
						case 3: {
							int mr;
							while((mr = menuRest()) != 3) {
								switch(mr) {
									case 1: {
										break;
									}
									case 2: {
										break;
									}
								}//fs
							}//fw
							break;
						}
					}//fin switch
				}//fin while
				break;
			}
		}//fin switch general
	}//fin qhile general
	return 0;
}

int menuGeneral() {
	int opcion;
	cout << "----MENU----" << endl;
	cout << "1. Mantenimiento" << endl;
	cout << "2. Sobrecarga de operadores" << endl;
	cout << "3. Salir" << endl;
	cout << endl;
	cout << "Ingrese la opcion: ";
	cin >> opcion;
	return opcion;
}//fin metodo Menu

int subMenu() {
	int opcion;
	cout << "1. Mantenimiento de Generos" << endl;
	cout << "2. Mantenimiento de Canciones" << endl;
	cout << "3. Mantenimiento de Album y Playlist" << endl;
	cout << "4. Salir" << endl;
	cout << endl;
	cout << "Ingrese la opcion: ";
	cin >> opcion;
	return opcion;
}

int menuGenero() {
	int opcion;
	cout << "1. Agregar Generos" << endl;
	cout << "2. Modificar Generos" << endl;
	cout << "3. Eliminar Generos" << endl;
	cout << "4. Listar Generos" << endl;
	cout << "5. Salir" << endl;
	cout << endl;
	cout << "Ingrese la opcion: ";
	cin >> opcion;
	return opcion;
}

int menuCanciones() {
	int opcion;
	cout << "1. Agregar Canciones" << endl;
	cout << "2. Modificar Canciones" << endl;
	cout << "3. Eliminar Canciones" << endl;
	cout << "4. Listar Canciones" << endl;
	cout << "5. Salir" << endl;
	cout << endl;
	cout << "Ingrese la opcion: ";
	cin >> opcion;
	return opcion;
}

int menuAP() {
	int opcion;
	cout << "1. Listar Albums" << endl;
	cout << "2. Listar Playlist" << endl;
	cout << "3. Salir" << endl;
	cout << endl;
	cout << "Ingrese la opcion: ";
	cin >> opcion;
	return opcion;
}

int subMenuOP() {
	int opcion;
	cout << "1. Operador *" << endl;
	cout << "2. Operador +" << endl;
	cout << "3. Operador -" << endl;
	cout << "4. Salir" << endl;
	cout << endl;
	cout << "Ingrese la opcion: ";
	cin >> opcion;
	return opcion;
}

int menuMult() {
	int opcion;
	cout << "1. Agregar Canciones de album a playlist" << endl;
	cout << "2. Salir" << endl;
	cout << endl;
	cout << "Ingrese la opcion: ";
	cin >> opcion;
	return opcion;
}

int menuSum() {
	int opcion;
	cout << "1. Agregar cancion a Playlist" << endl;
	cout << "2. Agregar canciones de un album a una playlist" << endl;
	cout << "3. Agregar cancion a album" << endl;
	cout << "4. Unificar dos playlist" << endl;
	cout << "5. Salir" << endl;
	cout << endl;
	cout << "Ingrese la opcion: ";
	cin >> opcion;
	return opcion;
}

int menuRest() {
	int opcion;
	cout << "1. Eliminar cancion de Playlist" << endl;
	cout << "2. Eliminar canciones por genero de Playlist" << endl;
	cout << "3. Salir" << endl;
	cout << endl;
	cout << "Ingrese la opcion: ";
	cin >> opcion;
	return opcion;
}

int menuAlbum() {
	int opcion;
	cout << "1. Agregar cancion a album existente" << endl;
	cout << "2. Crear album y agregar cancion" << endl;
	cout << "3. Salir" << endl;
	cout << "Ingrese la opcion: ";
	cin >> opcion;
	return opcion;
}


