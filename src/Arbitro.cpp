
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

	this->dificultad = dificultadPedida;
	this->cantJugadores = numeroDeJugadores;
	this->filaMaxima = filas;
	this->columnaMaxima = columnas;

	this->columnaDeJugada = 0;
	this->filaDeJugada = 0;

	this->finDeJuego = false;
	this->jugadorActual = 0;

	this->inicializarListaDeBombas();
	this->inicializarListaDeJugadores(listaDeNombresDeJugadores, numeroDeJugadores);
	this->listaDeBanderas.iniciarCursor();
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

uint Arbitro::tomarTipoDeJugada(){

	std::string pedido = "Ingrese el numero de la opcion elegida: \n";
	std::string opcion1 = "1) Colocar / quitar bandera \n";
	std::string opcion2 = "2) Descubrir casillero \n";
	std::string mensajeDeOpciones = pedido + opcion1 + opcion2;

	uint tipoDeJugada = pedirNumero(mensajeDeOpciones, 3);
	return tipoDeJugada;
}

void Arbitro::tomarUbicacionDeJugada(){
	this->filaDeJugada = pedirNumero("Por favor, ingrese la fila donde desea realizar la jugada", filaMaxima);
	this->columnaDeJugada = pedirNumero("Por favor, ingrese la columna donde desea realizar la jugada", columnaMaxima);
}

void Arbitro::avanzarTurno(){
	if(!listaDeJugadores.avanzarCursor())
		listaDeJugadores.avanzarCursor();
	jugadorActual = listaDeJugadores.obtenerCursor();
}

void Arbitro::tomarJugada(){

	Puntaje puntajes(this->dificultad);
	int puntajeJugador;
	uint opcionElegida = tomarTipoDeJugada();

	tomarUbicacionDeJugada();

	//Si es colocar/quitar bandera:
	if (opcionElegida == 1){

		Bandera unaBandera ((int)this->filaDeJugada, this->columnaDeJugada, jugadorActual);
		//si no hay bandera, pone una
		if ( !this->existeBandera(unaBandera) ){

			this->tipoDeJugada = "bandera";
			this->listaDeBanderas.agregarElemento(unaBandera);

			if (unaBandera.banderaBienColocada()){ // es una bandera donde hay bomba
				puntajeJugador = puntajes.devolverPuntos();
			} else { // no hay bomba
				puntajeJugador = -puntajes.devolverPuntos();
			}
			this->jugadorActual->asignarPuntaje(puntajeJugador);

		} else { // Quiere sacar bandera

				// si no pertenece a este jugador entonces la quita
				Jugador* propietarioBandera = unaBandera.obtenerJugador();
				if (this->jugadorActual->consultarNombre() == propietarioBandera->consultarNombre()){ //es el mismo
					// elimina bandera de la lista cuando sale
					this->tipoDeJugada = "cubierto";

					/********* hacer una funcion ******/
				} else { // es otro, caso en que corrige jugada del otro
					if ( unaBandera.banderaBienColocada() ){ // es una bandera donde hay bomba
						// la quita cuando sale pero le resta puntos porque si habia bomba
						puntajeJugador = -puntajes.devolverPuntosEspeciales();
						this->tipoDeJugada = "cubierto";

					} else { // era una bandera mal puesta
						puntajeJugador = puntajes.devolverPuntosEspeciales();
					}
					this->jugadorActual->asignarPuntaje(puntajeJugador);
				}
				// elimina la bandera
				this->eliminarBandera(unaBandera);
		}

	} else { //Descubrir casillero

		// ver si las coordenadas son validas
		Bomba supuestaBomba(this->columnaDeJugada, this->filaDeJugada);

		if (existeBomba(supuestaBomba)){
			this->jugadorActual->asignarEstado(true); // (perdio)
			this->tipoDeJugada = "boom";
			// se saca de la lista de jugadores y se agrega a la de eliminados
			this->eliminarJugador();
		} else { //Debo pasar en string el numero de bombas circundantes.

			uint numeroDeBombasCircundantes = evaluarBombasCircundantes(columnaDeJugada, filaDeJugada);
			std::ostringstream ossCircundantes;
			ossCircundantes << numeroDeBombasCircundantes;
			this->tipoDeJugada = ossCircundantes.str();
		}
	}
}

uint Arbitro::evaluarBombasCircundantes(uint columnaDeCasillero, uint filaDeCasillero){
	uint cantidadDeCircundantes = 0;
	for(int dFila = -1; dFila < 2; dFila++){
		for(int dColumna = -1; dColumna < 2; dColumna++ ){

			int columnaAEvaluar = columnaDeCasillero - dColumna;
			int filaAEvaluar = filaDeCasillero - dFila;

			if( (filaAEvaluar > -1 ) && (columnaAEvaluar > -1) &&
					(filaAEvaluar <= (int)this->filaMaxima) &&
					(columnaAEvaluar <= (int)this->columnaMaxima) ){
				Bomba supuestaBomba(columnaAEvaluar, filaAEvaluar);
				if (existeBomba(supuestaBomba)){
					cantidadDeCircundantes++;
				}
			}
		}
	}
	return cantidadDeCircundantes;
}

uint Arbitro::devolverColumnaDeJugada(){
	return columnaDeJugada;
}

uint Arbitro::devolverFilaDeJugada(){
	return filaDeJugada;
}

std::string Arbitro::devolverTipoDeJugada(){
	return this->tipoDeJugada;
}

uint Arbitro::devolverTurno(){
	return (uint)( listaDeJugadores.obtenerCursor()->consultarNumero() );
}

void Arbitro::declararTurno(){
	std::cout << "Es el turno de "<< jugadorActual->consultarNombre() << std::endl;
}

int Arbitro::devolverPuntaje(){
	int puntajeJugador = jugadorActual->consultarPuntaje();
	if (puntajeJugador <= 0) {
		return -1;
	} else {
		return puntajeJugador;
	}
}

bool Arbitro::terminoElJuego(){
	return finDeJuego;
}

void Arbitro::inicializarListaDeJugadores(cadena* nombres, int cantidadJugadores){
	for(int i = 0; i < cantidadJugadores; i++){
        Jugador jugador(nombres[i], i);
        listaDeJugadores.agregarElemento(jugador);
	}
}

void Arbitro::inicializarListaDeBombas(){
	if(this->dificultad == 1){
		crearBombas((this->filaMaxima * this->columnaMaxima) * 0.15);

	} else if(this->dificultad == 2){
		crearBombas((this->filaMaxima * this->columnaMaxima) * 0.25);

    } else {
        crearBombas((this->filaMaxima * this->columnaMaxima) * 0.35);
    }

}

void Arbitro::crearBombas(int cantBombas){
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
	listaDeBombas.iniciarCursor();
	 while (listaDeBombas.avanzarCursor()) {
		 Bomba* bombaEnLista = listaDeBombas.obtenerCursor();
		 if(bomba.obtenerCoordenadaX() == bombaEnLista->obtenerCoordenadaX()
				 && bomba.obtenerCoordenadaY() == bombaEnLista->obtenerCoordenadaY()){
			 return true;
		 }
	 }
	 return false;
}

bool Arbitro::existeBandera(Bandera bandera){

	listaDeBanderas.iniciarCursor();

	while (listaDeBanderas.avanzarCursor() && listaDeBanderas.obtenerCursor() != 0 ) {
		Bandera* banderaEnLista = listaDeBanderas.obtenerCursor();
		if(bandera.obtenerCoordenadaX() == banderaEnLista->obtenerCoordenadaX()
			&& bandera.obtenerCoordenadaY() == banderaEnLista->obtenerCoordenadaY()){
			return true;
		 }
	 }
	 return false;
}

void Arbitro::eliminarBandera(Bandera banderaABorrar){
	this->listaDeBanderas.iniciarCursor();
	bool encontrado = false;
	int posicion = 0;
	while(listaDeBanderas.avanzarCursor() && encontrado ){
		posicion++;
		Bandera* bandera = listaDeBanderas.obtenerCursor();
		if(banderaABorrar.obtenerCoordenadaX() == bandera->obtenerCoordenadaX() &&
			banderaABorrar.obtenerCoordenadaY() == bandera->obtenerCoordenadaY()){
			encontrado = true;
			listaDeBanderas.removerNodo(posicion);
		}
	}
}

void Arbitro::eliminarJugador(){
	this->listaDeJugadores.iniciarCursor();
	bool encontrado = false;
	int posicion = 0;
	while(listaDeJugadores.avanzarCursor() && encontrado ){
		posicion++;
		Jugador* unJugador = listaDeJugadores.obtenerCursor();
		if( this->jugadorActual->consultarNombre() == unJugador->consultarNombre() ){
			encontrado = true;
		}
	}
	Jugador* jugadorEliminado = this->listaDeJugadores.obtener(posicion);
	listaDeJugadores.removerNodo(posicion);
	// se agrega a la lista de eliminados
	this->listaDeJugadoresEliminados.agregarElemento(*jugadorEliminado);
}

uint Arbitro::devolverColumnaMaxima(){
	return this->columnaMaxima;
}

uint Arbitro::devolverFilaMaxima(){
	return this->filaMaxima;
}


