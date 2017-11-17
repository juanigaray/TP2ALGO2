#include "Puntaje.h"

Puntaje::Puntaje(int dificultad){
	
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

int Puntaje::devolverPuntos(){
	return this->puntos;
}

int Puntaje::devolverPuntosEspeciales(){
	return this->puntosEspeciales;
}

