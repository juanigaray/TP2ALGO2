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
	std::cout << "Ingrese la cantidad de jugadores (mayor a cero): " << std::endl;
	std::cin >> entrada;

	uint numJugadores = atoi(entrada.c_str());
	if ( numJugadores > 0  ){
		this->cantJugadores = numJugadores;

	} else {
		this->pedirNumeroDeJugadores();
	}

	this->listaDeNombresDeJugadores = new std::string [this->cantJugadores];
}

void Presentador::pedirNombresDeJugadores(){

	std::string nombreDeJugador;

	for(uint numeroDeNombre = 0;
			 numeroDeNombre < devolverNumeroDeJugadores();
			 numeroDeNombre++){

		std::cout 	<< "Ingrese el nombre del jugador"
					<<  (numeroDeNombre + 1)
					<< ": ";

		std::cin 	>> nombreDeJugador;

		listaDeNombresDeJugadores[numeroDeNombre] = nombreDeJugador;

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
