#include "Bomba.h"

Bomba::Bomba(int coordenadaX, int coordenadaY){
	this-> coordenadas[0] = coordenadaX;
	this-> coordenadas[1] = coordenadaY;
}

Bomba::Bomba(){
	this-> coordenadas[0] = 0;
	this-> coordenadas[1] = 0;
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
