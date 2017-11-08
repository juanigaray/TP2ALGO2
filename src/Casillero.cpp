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


