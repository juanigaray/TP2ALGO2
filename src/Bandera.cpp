#include "Bandera.h"
	//POST Crea Bandera POR DEFECTO VA A ESTAR EN FALSE EL bienColocada
	Bandera::Bandera(int coordenadaX, int coordenadaY, Jugador* jugador){
	this->coordenadas[0] = coordenadaX;
	this->coordenadas[1] = coordenadaY;
	this->jugador = jugador;
	this->bienColocada = false;
}

Bandera::Bandera(){
	this->bienColocada = false;
	this->coordenadas[0] = 0;
	this->coordenadas[1] = 0;
	this->jugador = 0;

}

void Bandera::cambiarCoordenadaX(int coordX){
	this->coordenadas[0] = coordX;
}

//POST CAMBIA COORDENADA Y
void Bandera::cambiarCoordenadaY(int coordY){
	this->coordenadas[1] = coordY;
}

//POST DEVUELVE COORDENADA X
int Bandera::obtenerCoordenadaX(){
	return this->coordenadas[0];
}

//POST DEVUELVE COORDENADA Y
int Bandera::obtenerCoordenadaY(){
return this->coordenadas[1];
}

//POST DEVUELVE SI ESTA bienColocada
bool Bandera::banderaBienColocada(){
	return this->bienColocada;
}

//POST VALIDA Y CAMBIA bienColocada
void Bandera::validarColocacion(Lista<Bomba>* bombas){
	bool encontrado = false;
	bombas->iniciarCursor();
	while (bombas->avanzarCursor() && !encontrado ){
		Bomba* bomba = bombas->obtenerCursor();
		if(bomba->obtenerCoordenadaX() == this->coordenadas[0] &&
				bomba->obtenerCoordenadaY() == this->coordenadas[1]){
			this->bienColocada = true;
			encontrado = true;
		}
	}
}
//POST DEVUELVE EL JUGADOR QUE COLOCO LA BANDERA
Jugador* Bandera::obtenerJugador(){
	return this->jugador;
}

