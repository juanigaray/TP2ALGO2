
/*
 * Arbitro.cpp
 *
 *  Created on: Oct 22, 2017
 *      Author: juan
 */
 
#include "Arbitro.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
 
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
	std::cout << "Si desea colocar o quitar una bandera, bla bla bla" << std::endl;
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
	
Jugador Arbitro::devolverTurno(){
	return listaDeJugadores.obtenerCursor();
}
	
void Arbitro::declararTurno(){
	Jugador jugador = listaDeJugadores.obtenerCursor();
	std::cout << "Es el turno del jugador "<< jugador.consultarNombre() << std::endl;

}
	
int Arbitro::devolverPuntaje(int puntos, Jugador recienJugo){
	if(puntos == 0)
	return -1;
	recienJugo.asignarPuntaje(puntos);
	return recienJugo.consultarPuntaje();
}

bool Arbitro::terminoElJuego(){
	return finDeJuego;
}
void Arbitro::inicializarListaDeJugadores(cadena* nombres, int cantidadJugadores){
	for(int i = 0; i < cantidadJugadores; i++){
	Jugador jugador(nombres[0], i);
	listaDeJugadores.agregarElemento(jugador);
	}
}
void Arbitro::inicializarListaDeBombas(int dificultad){

	if(dificultad == 1){
		crearBombas((filaMaxima * columnaMaxima) / 4);
	}else if(dificultad == 2){
		crearBombas((filaMaxima * columnaMaxima) / 3);
	}else{
		crearBombas((filaMaxima * columnaMaxima) / 2);
	}
}
void Arbitro::crearBombas(int cantBombas)
{
	while (cantBombas != 0)
	{
		int fila = rand() % (filaMaxima);
		int columna = rand() % (columnaMaxima) ;
		Bomba bomba(fila, columna);
		if(!existeBomba(bomba)){
		this->listaDeBombas.agregarElemento(bomba);
		}
		cantBombas--;
	}
}
bool Arbitro::existeBomba(Bomba bomba){
	this->listaDeBombas.iniciarCursor();
	 while (listaDeBombas.avanzarCursor()) {
		 Bomba bombaEnLista = listaDeBombas.obtenerCursor();
		 if(bomba.obtenerCoordenadaX() == bombaEnLista.obtenerCoordenadaX()
				 && bomba.obtenerCoordenadaY() == bombaEnLista.obtenerCoordenadaY()){
			 return true;
		 }
	    }

	return false;
}
