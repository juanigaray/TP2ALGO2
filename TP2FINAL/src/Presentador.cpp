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

//UI y Pedidos de datos

int Presentador::pedirNumero(std::string mensaje){

	int numeroIngresado;

	std::cout << mensaje << std::endl;
	std::cin >> numeroIngresado;

	while (std::cin.fail()){
		std::cin.clear();
		std::cin.ignore();
		std::cin >> numeroIngresado;
	}
	if(numeroIngresado <= 0){

		std::cout << "El numero debe ser mayor a cero!" << std::endl;
		numeroIngresado = pedirNumero(mensaje);
	}
	return numeroIngresado;
}

int Presentador::pedirNumero(std::string mensaje, int numeroMaximo){

	int numeroIngresado;

	std::cout << mensaje;
	std::cin >> numeroIngresado;

	while (std::cin.fail()){
		std::cin.clear();
		std::cin.ignore();
		std::cin >> numeroIngresado;
	}
	if (numeroIngresado <= 0 || numeroIngresado > numeroMaximo){

		std::cout << "Numero no valido! " << std::endl;
		numeroIngresado = pedirNumero(mensaje, numeroMaximo);
	}
	return numeroIngresado;
}

void Presentador::pedirDimensionesDelTablero(){

	this->filas = this->pedirNumero("Ingrese el numero de filas: ");
	this->columnas = this->pedirNumero("Ingrese el numero de columnas: ");
}

void Presentador::pedirNumeroDeJugadores(){

	this->cantJugadores = this->pedirNumero("Ingrese la cantidad de jugadores: ");
	this->listaDeNombresDeJugadores = new std::string [cantJugadores];
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
						<< " (hta 7 caracteres): ";

			std::cin 	>> nombreDeJugador;

			if (nombreDeJugador.size() <= 7){
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

void Presentador::consultarSiJugarDeNuevo(){

	char decision;
	bool preguntarDeNuevo = true;
	jugarDeNuevo = false;

	while (preguntarDeNuevo) {

		std::cout 	<< "Desea jugar de nuevo? (S/N): ";
		std::cin 	>> decision;

		while (std::cin.fail()){
			std::cin.clear();
			std::cin.ignore();
			std::cin >> decision;
		}

		jugarDeNuevo = ( decision == 's' || decision == 'S');
		preguntarDeNuevo = ( (! jugarDeNuevo) && (decision != 'n') && (decision != 'N') );

		if (preguntarDeNuevo){
			std::cout << "Opcion no valida!" << std::endl;
		}
	}
}

void Presentador::declararFinDelJuego(){
	std::cout << "Juego terminado!" << std::endl;
}


//Get

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

bool Presentador::devolverSiJugarDeNuevo(){
	return this->jugarDeNuevo;
}

Presentador::~Presentador(){
	if(listaDeNombresDeJugadores != NULL){
		delete [] listaDeNombresDeJugadores;
	}
}
