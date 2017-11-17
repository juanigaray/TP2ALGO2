#include "Bandera.h"

Bandera::Bandera(int colocadaPor){
	this->jugadorQueColoco = colocadaPor;
	this->existe = true;
}

Bandera::Bandera(){
	this->jugadorQueColoco = 0;
	this->existe = false;
}

int Bandera::obtenerJugador(){
	return this->jugadorQueColoco;
}

bool Bandera::hayBandera(){
	return this->existe;
}

void Bandera::colocarBandera(int quienColoco){
	jugadorQueColoco = quienColoco;
	existe = true;
}
