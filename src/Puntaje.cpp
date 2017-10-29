#include "Puntaje.h"

Puntaje::Puntaje(uint dificultad){
	
	if (dificultad == 1){
		this->puntos = 1;
		this->puntosEspeciales = 2;
		
	} else {
		
		if (dificultad == 2){
			this->puntos = 2;
			this->puntosEspeciales = 3;
			
		} else { 	// dificultad es 3
			this->puntos = 3;
			this->puntosEspeciales = 5;
			
		}
	}
}

uint Puntaje::devolverPuntos(){
	return this->puntos;
}

uint Puntaje::devolverPuntosEspeciales(){
	return this->puntosEspeciales;
}

