#include "Bandera.h"

Bandera::Bandera(uint colocadaPor){
	this->jugadorQueColoco = colocadaPor;
	this->existe = true;
}

Bandera::Bandera(){
	this->jugadorQueColoco = 0;
	this->existe = false;
}

uint Bandera::obtenerJugador(){
	return this->jugadorQueColoco;
}

bool Bandera::hayBandera(){
	return this->existe;
}

void Bandera::eliminarBandera(){
	this->jugadorQueColoco = 0;
	this->existe = false;
}

void Bandera::colocarBandera(uint quienColoco){
	jugadorQueColoco = quienColoco;
	existe = true;
}
