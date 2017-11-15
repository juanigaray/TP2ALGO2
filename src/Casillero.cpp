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

void Casillero::colocarBandera(uint jugador){
	if (bandera == 0){
		bandera = new Bandera;
	}
	this->bandera->colocarBandera(jugador);
}

void Casillero::quitarBandera(){
		delete this->bandera;
		bandera = 0;
}

uint Casillero::quienPusoLaBandera(){
	return ( this->bandera->obtenerJugador() );
}

bool Casillero::tieneBomba(){
	return bomba;
}

bool Casillero::tieneBandera(){
	return ( (this->bandera != 0) && this->bandera->hayBandera() );
}

bool Casillero::estaDescubierto(){
	return esVisible;
}

void Casillero::destapar(){
	this->esVisible = true;
}

Casillero::~Casillero(){
	if (bandera != 0){
		delete bandera;
	}
}

