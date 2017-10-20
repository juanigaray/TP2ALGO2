/*
 * Presentador.cpp
 *
 *  Created on: Oct 20, 2017
 *      Author: juan
 */
#include <stdio.h>      /* printf, fgets */
#include <stdlib.h>     /* atoi */
#include "Presentador.h"

Presentador::Presentador(){

	dificultad = 1;
	cantJugadores = 1;
	listaDeNombresDeJugadores = 0;
	filas = 1;
	columnas = 1;

}


void Presentador::pedirDimensiones(){


}

void Presentador::pedirNumeroDeJugadores(){
	std::string entrada;
	std::cout << "Ingrese la cantidad de jugadores: " << std::endl;
	std::cin >> entrada;

	if ( validarNumeros(entrada) ){
		uint numJugadores = atoi(entrada.c_str()); //Que es atoi?
		this->cantJugadores = numJugadores;

	} else { // si no es un numero vuelve a llamar
		this->pedirNumeroDeJugadores();
	}

	listaDeNombresDeJugadores = new std::string [this->cantJugadores];
}

void Presentador::pedirNombresDeJugadores(){

	std::string nombreDeJugador;

	for(uint numeroDeNombre = 0;
			 numeroDeNombre < devolverNumeroDeJugadores();
			 numeroDeNombre++){

		listaDeNombresDeJugadores[numeroDeNombre] = pedirNombre();

	}


}


void Presentador::pedirDatosDeJugadores(){
	pedirNumeroDeJugadores();
	pedirNombresDeJugadores();
}



void Presentador::pedirDificultad(){

}


Presentador::~Presentador(){
	delete [] listaDeNombresDeJugadores;
}
