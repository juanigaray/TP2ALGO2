/*
 * Presentador.cpp
 *
 *  Created on: Oct 20, 2017
 *      Author: juan
 */

#include "Presentador.h"

Presentador::Presentador(){

	dificultad = 1;
	cantJugadores = 1;
	listaDeNombresDeJugadores = 0;
	filas = 10;
	columnas = 10;
	jugarDeNuevo = true;

}

int Presentador::pedirNumero(std::string mensaje){

	int numeroIngresado;

	std::cout << mensaje << std::endl;
	std::cin >> numeroIngresado;
	if(numeroIngresado == 0){
		std::cout << "El numero debe ser mayor a cero!" << std::endl;
		this->pedirNumero(mensaje);
	}
	return numeroIngresado;
}

int Presentador::pedirNumero(std::string mensaje, int numeroMaximo){

	int numeroIngresado;

	std::cout << mensaje;
	std::cin >> numeroIngresado;
	if (numeroIngresado == 0 || numeroIngresado > numeroMaximo){
		std::cout << "Numero no valido! " << std::endl;
		this->pedirNumero(mensaje, numeroMaximo);
	}
	return numeroIngresado;
}

void Presentador::pedirDimensionesDelTablero(){

	this->filas = this->pedirNumero("Ingrese el numero de filas: ");
	this->columnas = this->pedirNumero("Ingrese el numero de columnas: ");
}

void Presentador::pedirNumeroDeJugadores(){

	this->cantJugadores = this->pedirNumero("Ingrese la cantidad de jugadores: ");
	this->listaDeNombresDeJugadores = new std::string [this->cantJugadores];
}

void Presentador::pedirNombresDeJugadores(){

	bool estaseguro;
	char decision;
	std::string nombreDeJugador;

	for(int numeroDeNombre = 0;
			 numeroDeNombre < devolverNumeroDeJugadores();
			 numeroDeNombre++){

		estaseguro = false;

		while(! estaseguro){
			std::cout 	<< "Ingrese el nombre del jugador "
						<<  (numeroDeNombre + 1)
						<< ": ";

			std::cin 	>> nombreDeJugador;

			std::cout 	<< std::endl
						<< "El nombre del jugador "
						<<  (numeroDeNombre + 1)
						<< " es "
						<< nombreDeJugador
						<< ". Esta seguro de que quiere conservar ese nombre? (S/N)"
						<< std::endl;

			std::cin 	>> decision;
			if( decision == 's' || decision == 'S'){
				listaDeNombresDeJugadores[numeroDeNombre] = nombreDeJugador;
				estaseguro = true;
			}
		}
	}
}

void Presentador::pedirDatosDeJugadores(){
	pedirNumeroDeJugadores();
	pedirNombresDeJugadores();
}

void Presentador::pedirDificultad(){
	this->dificultad = pedirNumero("Ingrese la dificultad deseada (del 1 al 3): ", 3);
}

void Presentador::pedirDatosDeJuego(){
	this->pedirDificultad();
	this->pedirDatosDeJugadores();
	this->pedirDimensionesDelTablero();
}

int Presentador::devolverColumnas(){
	return this->columnas;
}

int Presentador::devolverFilas(){
	return this->filas;
}

int Presentador::devolverNumeroDeJugadores(){
	return this->cantJugadores;
}

int Presentador::devolverDificultad(){
	return this->dificultad;
}

std::string* Presentador::devolverNombresDeLosJugadores(){
	return this->listaDeNombresDeJugadores;
}

void Presentador::declararFinDelJuego(){
	std::cout << "Juego terminado!" << std::endl;
}

void Presentador::consultarSiJugarDeNuevo(){
	char decision;
	bool preguntarDeNuevo = true;

	while (preguntarDeNuevo) {

		std::cout 	<< "Desea jugar de nuevo? (S/N): ";

		std::cin 	>> decision;

		if( decision == 's' || decision == 'S'){

			this->jugarDeNuevo = true;
			preguntarDeNuevo = false;

		} else if (decision == 'n' || decision == 'N'){

			this->jugarDeNuevo = false;
			preguntarDeNuevo = false;

		} else {
			std::cout << "Opcion no valida!" << std::endl;
		}
	}

}

bool Presentador::devolverSiJugarDeNuevo(){
	return this->jugarDeNuevo;
}

Presentador::~Presentador(){
	delete [] listaDeNombresDeJugadores;
}
