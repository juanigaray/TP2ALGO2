
/*
 * Arbitro.cpp
 *
 *  Created on: Oct 22, 2017
 *      Author: juan
 */

#include "Juego.h"

Juego::Juego(int dificultad, int numeroDeJugadores, int filas, int columnas, cadena* nombresDeJugadores){

	bomba = "boom";
	bandera = "bandera";
	casilleroCubierto = "cubierto";
	margen = "margen";

	this->columnaDeJugada = 0;
	this->filaDeJugada = 0;
	this->seDebeEliminarJugador = false;

	this->dibujante = new Dibujante(columnas, filas, numeroDeJugadores);
	this->arbitro = new Arbitro(nombresDeJugadores, numeroDeJugadores, dificultad);

	tablero.asignarDimensionesYDificultad(columnas, filas, dificultad);

	this->dibujante->dibujarTablero();
}



int Juego::pedirNumero(std::string mensaje){

	int numeroIngresado;
	std::cout << mensaje << std::endl;
	std::cin >> numeroIngresado;
	if(numeroIngresado == 0){
		std::cout << "El numero debe ser mayor a cero!" << std::endl;
		this->pedirNumero(mensaje);
	}
	return numeroIngresado;
}

int Juego::pedirNumero(std::string mensaje, int numeroMaximo){

	int numeroIngresado;
	std::cout << mensaje << std::endl;
	std::cin >> numeroIngresado;
	if(numeroIngresado == 0 || numeroIngresado > numeroMaximo){
		std::cout << "Numero no valido! " << std::endl;
		this->pedirNumero(mensaje, numeroMaximo);
	}
	return numeroIngresado;
}

int Juego::tomarTipoDeJugada(){

	std::string pedido = "Ingrese el numero de la opcion elegida: \n";
	std::string opcion1 = "1) Colocar / quitar bandera \n";
	std::string opcion2 = "2) Descubrir casillero \n";
	std::string mensajeDeOpciones = pedido + opcion1 + opcion2;

	int tipoDeJugada = pedirNumero(mensajeDeOpciones, 3);
	return tipoDeJugada;
}

void Juego::tomarUbicacionDeJugada(){
	filaDeJugada = pedirNumero("Por favor, ingrese la fila donde desea realizar la jugada", tablero.obtenerFilaMaxima() ) - 1;
	columnaDeJugada = pedirNumero("Por favor, ingrese la columna donde desea realizar la jugada", tablero.obtenerColumnaMaxima() ) - 1;
}

void Juego::avanzarTurno(){
	arbitro->avanzarTurno(seDebeEliminarJugador);
	seDebeEliminarJugador = false;
}

void Juego::tomarJugada(){
	cadena queDibujar;
	bool haJugado = false;
	int opcionElegida;
	int jugadorActual;

	while (! haJugado){

		opcionElegida = tomarTipoDeJugada();
		jugadorActual = arbitro->devolverNumeroDeTurno();
		tomarUbicacionDeJugada();

		//Es colocar/quitar bandera:
		if ((opcionElegida == 1) && (! tablero.estaDescubierto(columnaDeJugada, filaDeJugada) )){

			cambiarBandera(jugadorActual);
			haJugado = true;

		//Es destapar
		} else if ( ! tablero.hayBanderaEn(columnaDeJugada, filaDeJugada) ) {

			descubrirCasillero(columnaDeJugada, filaDeJugada, jugadorActual);
			haJugado = true;

		} else {
			std::cout << "Esa jugada no es valida!" << std::endl;
		}
	}

	this->dibujante->dibujarTablero();
}

void Juego::cambiarBandera(int jugadorActual){

	cadena queDibujar;

	//No hay bandera, la pone
	if ( ! tablero.hayBanderaEn(columnaDeJugada, filaDeJugada) ){

		bool pusoBien = tablero.colocarBandera(columnaDeJugada, filaDeJugada, jugadorActual);
		queDibujar = bandera;

		if (pusoBien){
			arbitro->sumarPuntaje(1);

		} else {
			arbitro->sumarPuntaje(-1);
		}

	//Hay bandera, saca
	} else {

		unsigned int cuantoSuma = tablero.quitarBandera(columnaDeJugada, filaDeJugada, jugadorActual);
		queDibujar = casilleroCubierto;

		this->arbitro->sumarPuntaje(cuantoSuma);
	}

	int puntaje = arbitro->devolverPuntaje();
	this->dibujante->cambiarPuntaje( puntaje, jugadorActual );
	this->dibujante->cambiarCuadrante(columnaDeJugada, filaDeJugada, queDibujar, jugadorActual, false);
}

void Juego::descubrirCasillero(int columnaDeCasillero, int filaDeCasillero, int jugadorActual){

	cadena queDibujar = "";

	tablero.descubrirCasillero(columnaDeCasillero, filaDeCasillero);

	//Tiene bomba
	if (tablero.hayBombaEn(columnaDeCasillero, filaDeCasillero) ){

		queDibujar = bomba;
		seDebeEliminarJugador = true;
		dibujante->eliminarJugador(jugadorActual);

	//No tiene bomba
	} else {

		int numeroDeBombasCircundantes = tablero.obtenerNumeroDeBombasCircundantes(columnaDeCasillero, filaDeCasillero);
		queDibujar = hacerCadena(numeroDeBombasCircundantes);

		if (numeroDeBombasCircundantes == 0){
			descubrirCasillerosCircundantes(columnaDeCasillero, filaDeCasillero);
		}
	}
	this->dibujante->cambiarCuadrante(columnaDeCasillero, filaDeCasillero, queDibujar, jugadorActual, false);
}


void Juego::descubrirCasillerosCircundantes(int columnaDeCasillero, int filaDeCasillero){

	for(int dFila = -1; dFila < 2; dFila++){
		for(int dColumna = -1; dColumna < 2; dColumna++ ){

			int columnaAEvaluar = columnaDeCasillero + dColumna;
			int filaAEvaluar = filaDeCasillero + dFila;

			if (! tablero.estaDescubierto(columnaAEvaluar, filaAEvaluar) ){
				//Llamada recursiva entre el metodo actual y descubrirCasillero.
				descubrirCasillero(columnaAEvaluar, filaAEvaluar, 0);
			}
		}
	}
}


void Juego::declararTurno(){
	std::cout << "Es el turno de "<< (arbitro->devolverJugador()).consultarNombre() << std::endl;
}

bool Juego::terminoLaPartida(){
	if ( arbitro->quedaUno() || tablero.noQuedanCasilleros() ){
		arbitro->anunciarGanador();
		return true;
	}
	else return false;
}

cadena Juego::hacerCadena(int numero){
	std::ostringstream ossnumero;
	ossnumero << numero;
	return ossnumero.str();
}

Juego::~Juego(){
	delete dibujante;
	delete arbitro;
}


