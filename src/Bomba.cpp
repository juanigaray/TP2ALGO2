#include "Bomba.h"

Bomba::Bomba(int coordenadaX, int coordenadaY){
	this-> coordenadas[0] = coordenadaX;
	this-> coordenadas[1] = coordenadaY;
}

void Bomba::cambiarCoordenadaX(int nuevaX){
	this->coordenadas[0] = nuevaX;
}


void Bomba::cambiarCoordenadaY(int nuevaY){
	this->coordenadas[1] = nuevaY;
}


int Bomba::obtenerCoordenadaX(){
	return this->coordenadas[0];
}

int Bomba::obtenerCoordenadaY(){
	return this->coordenadas[1];
}

void Bomba::eliminarJugador(Jugador jugador){
	jugador.asignarEstado(true);
}
