/*
 * Casillero.cpp
 *
 *  Created on: Nov 8, 2017
 *      Author: juan
 */

#include "Casillero.h"

Casillero::Casillero(){
	this->bomba = false;
	this->esVisible = false;
	this->bandera = 0;
}

Casillero::Casillero(bool conBomba){
	this->bomba = true;
	this->esVisible = false;
	this->bandera = 0;
}

bool Casillero::tieneBandera(){
	return ( (this->bandera != 0) && this->bandera->hayBandera() );
}

void Casillero::colocarBandera(uint jugador){
	this->bandera->colocarBandera(jugador);
}

void Casillero::quitarBandera(){
	this->bandera->eliminarBandera();
}

uint Casillero::quienPusoLaBandera(){
	return ( this->bandera->obtenerJugador() );
}

bool Casillero::tieneBomba(){
	return this->bomba;
}
