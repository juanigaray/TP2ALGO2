
/*
 * Arbitro.cpp
 *
 *  Created on: Oct 22, 2017
 *      Author: juan
 */

#include "Juego.h"

Juego::Juego(uint dificultadPedida, uint numeroDeJugadores, uint filas, uint columnas, cadena* nombresDeJugadores){

	bomba = "boom";
	bandera = "bandera";
	casilleroCubierto = "cubierto";
	margen = "margen";

	this->filaMaxima = filas;
	this->columnaMaxima = columnas;

	this->columnaDeJugada = 0;
	this->filaDeJugada = 0;

	this->dibujante = new Dibujante(columnas, filas, numeroDeJugadores);
	this->arbitro = new Arbitro(nombresDeJugadores, numeroDeJugadores, dificultadPedida);

	this->tablero = new Casillero**[columnaMaxima];

	inicializarTablero(dificultadPedida);

	this->casillerosDestapados = 0;
	this->bombasTotales =  (dificultadPedida * filaMaxima * columnaMaxima) % 16;
}

void Juego::inicializarTablero(uint dificultad){

	//A cada columna le asigno un array de n casilleros, n = nro de filas
	for(uint col =0; col < columnaMaxima; col++){

		tablero[col] = new Casillero*[filaMaxima];

		for(uint fil = 0; fil < filaMaxima; fil++ ){

			tablero[col][fil] = NULL;
		}
	}
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

	cadena queDibujar;

	uint opcionElegida = this->tomarTipoDeJugada();

	uint jugadorActual = this->arbitro->devolverTurno();

	tomarUbicacionDeJugada();

	this->prepararCasillero();
	std::cout << "preparo casillero!";

	//Si es colocar/quitar bandera:
	if (opcionElegida == 1){

		//No hay bandera, pone
		if ( ! tablero[columnaDeJugada][filaDeJugada]->tieneBandera() ){

			queDibujar = bandera;

			if ( (tablero[columnaDeJugada][filaDeJugada])->tieneBomba() ){ // es una bandera donde hay bomba
				this->arbitro->sumarPuntaje(1);
			} else { // no hay bomba
				this->arbitro->sumarPuntaje(-1);
			}

			this->tablero[columnaDeJugada][filaDeJugada]->colocarBandera(jugadorActual);

		//Hay bandera, saca
		} else {

			queDibujar = casilleroCubierto;

			//No pertenece a este jugador
			if ( ! (tablero[columnaDeJugada][filaDeJugada]->quienPusoLaBandera() == jugadorActual) ){

				//Era una bandera bien puesta
				if ( tablero[columnaDeJugada][filaDeJugada]->tieneBomba() ){
					this->arbitro->sumarPuntaje(-2);

				//Era una bandera mal puesta
				} else {
					this->arbitro->sumarPuntaje(2);
				}
			}
			this->tablero[columnaDeJugada][filaDeJugada]->quitarBandera();

		}

		this->dibujante->cambiarPuntaje( this->arbitro->devolverPuntaje(), jugadorActual );

	//Opcion elegida: descubrir casillero
	} else {

		// ver si las coordenadas son validas

		//Tiene bomba
		if ( (tablero[columnaDeJugada][filaDeJugada])->tieneBomba() ){

			queDibujar = bomba;
			arbitro->eliminarJugador();
			dibujante->eliminarJugador(jugadorActual);

		//No tiene bomba
		} else {

			uint numeroDeBombasCircundantes = evaluarBombasCircundantes(columnaDeJugada, filaDeJugada);
			queDibujar = hacerCadena(numeroDeBombasCircundantes);

			if(numeroDeBombasCircundantes == 0){
				//DESTAPO LAS CIRCUNDANTES
			}
		}
	}
	this->dibujante->cambiarCuadrante(columnaDeJugada,filaDeJugada,queDibujar, this->arbitro->devolverTurno(), false);
	this->dibujante->dibujarTablero();
}

void Juego::prepararCasillero(){
	if(tablero[columnaDeJugada][filaDeJugada] == 0){
		( tablero[columnaDeJugada][filaDeJugada] ) = new Casillero();
		std::cout << "ok" << std::endl;
	}
}

uint Juego::evaluarBombasCircundantes(uint columnaDeCasillero, uint filaDeCasillero){

	uint circundantes;
	for(int dFila = -1; dFila < 2; dFila++){
		for(int dColumna = -1; dColumna < 2; dColumna++ ){

			int columnaAEvaluar = columnaDeCasillero - dColumna;
			int filaAEvaluar = filaDeCasillero - dFila;

			if	 ( validarCoordenada(filaAEvaluar, columnaAEvaluar) &&
								(filaAEvaluar != filaDeCasillero  ) &&
								(columnaAEvaluar != columnaDeCasillero) &&
								tablero[filaDeCasillero][columnaDeCasillero]->tieneBomba()	){
				circundantes++;

			}
		}
	}
	return circundantes;
}

bool Juego::validarCoordenada(uint fila, uint columna){
	return ( (fila < filaMaxima) && (columna < columnaMaxima) && (fila >= 0) && (columna >= 0) );
}

void Juego::declararTurno(){
	std::cout << "Es el turno de "<< (arbitro->devolverJugador())->consultarNombre() << std::endl;
}

int Juego::devolverPuntaje(){
	int puntajeJugador = arbitro->devolverJugador()->consultarPuntaje();
	if (puntajeJugador < 0) {
		return 0;
	} else {
		return puntajeJugador;
	}
}

void Juego::crearBombas(uint dificultad){

	srand (time(NULL));
	int bombasRestantes = bombasTotales;
	while (bombasRestantes > 0){
		//Genero dos numeros semi-aleatorios para usar de coordenada
		uint xAleatorio = rand() % filaMaxima;
		uint yAleatorio = rand() % columnaMaxima;
		//solo afecta el casillero si no hay una mina ya sobre el
		if ( tablero[xAleatorio][yAleatorio] == 0 ){

			(tablero[xAleatorio][yAleatorio]) = new Casillero(true);

			bombasRestantes --;

		}
	}
}

void Juego::eliminarBandera(uint fila, uint columna){
	tablero[columna][fila]->quitarBandera();
}

bool Juego::terminoLaPartida(){
	return (arbitro->murieronTodos() || this->noQuedanCasilleros() );
}

bool Juego::noQuedanCasilleros(){
	return (casillerosDestapados == ( (filaMaxima * columnaMaxima) - bombasTotales ));
}

cadena Juego::hacerCadena(int numero){
	std::ostringstream ossnumero;
	ossnumero << numero;
	return ossnumero.str();
}

Juego::~Juego(){
	//LIBERAR MEMORIA DEL TABLERO!!

}
