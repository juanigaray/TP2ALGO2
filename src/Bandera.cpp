#include "Bandera.h"

Bandera::Bandera(uint colocadaPor){
	this->jugador = colocadaPor;
	this->existe = true;
}

Bandera::Bandera(){
	this->jugador = 0;
	this->existe = false;
}

uint Bandera::obtenerJugador(){
	return this->jugador;
}

bool Bandera::hayBandera(){
	return this->existe;
}

void Bandera::eliminarBandera(){
	this->jugador = 0;
	this->existe = false;
}

void Bandera::colocarBandera(uint colocadaPor){
	this->jugador = colocadaPor;
	this->existe = true;
}
