
/*
 * Arbitro.cpp
 *
 *  Created on: Oct 22, 2017
 *      Author: juan
 */
 
#include "Arbitro.h"
#include <iostream>

 
Arbitro::Arbitro(uint dificultadPedida, uint numeroDeJugadores, uint filas, uint columnas, cadena* listaDeNombresDeJugadores){

	dificultad = dificultadPedida;
	cantJugadores = numeroDeJugadores;

	filaMaxima = filas;
	columnaMaxima = columnas;

	columnaDeJugada = 0;
	filaDeJugada = 0;

	finDeJuego = false;
}

uint Arbitro::pedirNumero(std::string mensaje){

	uint numeroIngresado;

	std::cout << mensaje << std::endl;
	std::cin >> numeroIngresado;
	if(numeroIngresado == 0){
		std::cout << "El numero debe ser mayor a cero!" << std::endl;
		this->pedirNumero(mensaje);
	}
	return numeroIngresado;
}

uint Arbitro::pedirNumero(std::string mensaje, uint numeroMaximo){

	uint numeroIngresado;

	std::cout << mensaje << std::endl;
	std::cin >> numeroIngresado;
	if(numeroIngresado == 0 || numeroIngresado > numeroMaximo){
		std::cout << "Numero no valido! " << std::endl;
		this->pedirNumero(mensaje);
	}
	return numeroIngresado;
}

void Arbitro::tomarTipoDeJugada(){
	std::string pedido = "Ingrese el numero de la opcion elegida: \n";
	std::string opcion1 = "1) Colocar / quitar bandera \n";
	std::string opcion2 = "2) Descubrir casillero \n";
	std::string mensajeDeOpciones = pedido + opcion1 + opcion2;

	uint tipoDeJugada = pedirNumero(mensajeDeOpciones, 3);

}

void Arbitro::tomarUbicacionDeJugada(){
	filaDeJugada = pedirNumero("Por favor, ingrese la fila donde desea realizar la jugada");
	columnaDeJugada = pedirNumero("Por favor, ingrese la columna donde desea realizar la jugada");
}


void Arbitro::tomarJugada(){
	//modularizar e implementar
	uint opcionElegida;
	std::cout << "Si desea colocar o quitar una bandera, bla bla bla" << std::endl; //JAJAJJAJAJJAJAJJA
	std::cin >> opcionElegida;
	tomarTipoDeJugada();
	tomarUbicacionDeJugada();
}

uint Arbitro::devolverColumnaDeJugada(){
	return columnaDeJugada;
}

uint Arbitro::devolverFilaDeJugada(){
	return filaDeJugada;
}
	
std::string Arbitro::devolverTipoDeJugada(){
	//Sacar del objeto Jugada
	return "bandera";
}
	
uint Arbitro::devolverTurno(){
	//Sacar de la lista
	return 0;
}
	
void Arbitro::declararTurno(){
	//De lista sacar string con nombre del jugador
	std::cout << "Es el turno del jugador " << std::endl;

}
	
int Arbitro::devolverPuntaje(){
	//El jugador deberia tener una variable "diferencia de puntaje".
	//Si es cero,
	return -1;
	//De lo contrario, devuelve el puntaje.
}

bool Arbitro::terminoElJuego(){
	return finDeJuego;
}
