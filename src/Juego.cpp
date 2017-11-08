
/*
 * Arbitro.cpp
 *
 *  Created on: Oct 22, 2017
 *      Author: juan
 */

#include "Juego.h"

Juego::Juego(uint dificultadPedida, uint numeroDeJugadores, uint filas, uint columnas, cadena* nombresDeJugadores){

	this->filaMaxima = filas;
	this->columnaMaxima = columnas;

	this->columnaDeJugada = 0;
	this->filaDeJugada = 0;
	this->diferenciaDePuntaje = 0;

	this->dibujante = new Dibujante(columnas, filas, numeroDeJugadores);
	this->arbitro = new Arbitro(nombresDeJugadores, numeroDeJugadores, dificultadPedida);

	this->tablero = new Casillero*[filas];
	inicializarTablero(filas, columnas, dificultadPedida);

	this->jugadorActual = 0;

	this->casillerosDestapados = 0;
}

uint Juego::pedirNumero(std::string mensaje){

	uint numeroIngresado;
	std::cout << mensaje << std::endl;
	std::cin >> numeroIngresado;
	if(numeroIngresado == 0){
		std::cout << "El numero debe ser mayor a cero!" << std::endl;
		this->pedirNumero(mensaje);
	}
	return numeroIngresado;
}

uint Juego::pedirNumero(std::string mensaje, uint numeroMaximo){

	uint numeroIngresado;
	std::cout << mensaje << std::endl;
	std::cin >> numeroIngresado;
	if(numeroIngresado == 0 || numeroIngresado > numeroMaximo){
		std::cout << "Numero no valido! " << std::endl;
		this->pedirNumero(mensaje);
	}
	return numeroIngresado;
}

uint Juego::tomarTipoDeJugada(){

	std::string pedido = "Ingrese el numero de la opcion elegida: \n";
	std::string opcion1 = "1) Colocar / quitar bandera \n";
	std::string opcion2 = "2) Descubrir casillero \n";
	std::string mensajeDeOpciones = pedido + opcion1 + opcion2;

	uint tipoDeJugada = pedirNumero(mensajeDeOpciones, 3);
	return tipoDeJugada;
}

void Juego::tomarUbicacionDeJugada(){
	filaDeJugada = pedirNumero("Por favor, ingrese la fila donde desea realizar la jugada", filaMaxima);
	columnaDeJugada = pedirNumero("Por favor, ingrese la columna donde desea realizar la jugada", columnaMaxima);
}

void Juego::avanzarTurno(){
	arbitro->avanzarTurno();
}

void Juego::tomarJugada(){

	uint opcionElegida = tomarTipoDeJugada();

	tomarUbicacionDeJugada();

	//Si es colocar/quitar bandera:
	if (opcionElegida == 1){

		//si no hay bandera, pone una
		if ( ){

			this->tipoDeJugada = "bandera";

			if (){ // es una bandera donde hay bomba
				//Sumo puntaje a jugador
			} else { // no hay bomba
				//Resto puntaje a jugador
			}
			this->jugadorActual->asignarPuntaje(puntajeJugador);

		} else { // Quiere sacar bandera

				// si no pertenece a este jugador entonces la quita
				Jugador* propietarioBandera = unaBandera.obtenerJugador();
				if (this->jugadorActual->consultarNombre() == propietarioBandera->consultarNombre()){ //es el mismo
					// elimina bandera de la lista cuando sale
					this->tipoDeJugada = "cubierto";

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

uint Juego::evaluarBombasCircundantes(uint columnaDeCasillero, uint filaDeCasillero){
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
	this->casillerosDestapados++;
	return cantidadDeCircundantes;
}

uint Juego::devolverColumnaDeJugada(){
	return columnaDeJugada;
}

uint Juego::devolverFilaDeJugada(){
	return filaDeJugada;
}

void Juego::declararTurno(){
	std::cout << "Es el turno de "<< (arbitro->devolverJugadorActual())->consultarNombre() << std::endl;
}

int Juego::devolverPuntaje(){
	int puntajeJugador = jugadorActual->consultarPuntaje();
	if (puntajeJugador <= 0) {
		return -1;
	} else {
		return puntajeJugador;
	}
}



void Juego::inicializarListaDeBombas(){
	if(this->dificultad == 1){
		crearBombas((this->filaMaxima * this->columnaMaxima) * 0.15); //multiplicador de dificultad

	} else if(this->dificultad == 2){
		crearBombas((this->filaMaxima * this->columnaMaxima) * 0.25); //multiplicador de dificultad

    } else {
        crearBombas((this->filaMaxima * this->columnaMaxima) * 0.35); //multiplicador de dificultad
    }

}

void Juego::crearBombas(int cantBombas){
	while (cantBombas != 0)
	{
		int fila = 1 + rand() % (filaMaxima);
		int columna = 1 + rand() % (columnaMaxima) ;
		Bomba bomba(fila, columna);
		if(!existeBomba(bomba)){
		this->listaDeBombas.agregarElemento(bomba);
		}
		cantBombas--;
	}
}

bool Juego::existeBomba(Bomba bomba){
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

bool Juego::existeBandera(Bandera bandera){

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

void Juego::eliminarBandera(Bandera banderaABorrar){
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



uint Juego::devolverColumnaMaxima(){
	return this->columnaMaxima;
}

uint Juego::devolverFilaMaxima(){
	return this->filaMaxima;
}

bool Juego::terminoLaPartida(){
	if (this->listaDeJugadoresEliminados.contarElementos() == this->cantJugadores){
		return true;
	}
	if ( ((filaMaxima * columnaMaxima) - this->listaDeBombas.contarElementos()) == this->casillerosDestapados ){

		return true;
	}
	return false;
}

cadena Juego::hacerCadena(int numero){
	std::ostringstream ossnumero;
	ossnumero << numero;
	return ossnumero.str();
}
