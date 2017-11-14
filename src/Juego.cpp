
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
	filaDeJugada = pedirNumero("Por favor, ingrese la fila donde desea realizar la jugada", filaMaxima) - 1;
	columnaDeJugada = pedirNumero("Por favor, ingrese la columna donde desea realizar la jugada", columnaMaxima) - 1;
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

	//Es colocar/quitar bandera:
	if (opcionElegida == 1){
		//NO PUEDE HACER ESTO SI EL CASILLERO ESTA DESCUBIERTO. CHEQUEAR.

		queDibujar = colocarBandera(jugadorActual);

	//Es destapar
	} else {
		//NO PUEDE HACER ESTO SI EL CASILLERO TIENE BANDERA. CHEQUEAR.

		queDibujar = destaparCasillero(jugadorActual);

	}

	this->dibujante->cambiarCuadrante(columnaDeJugada, filaDeJugada, queDibujar, this->arbitro->devolverTurno(), false);
	this->dibujante->dibujarTablero();
}

cadena Juego::colocarBandera(uint jugadorActual){

	cadena queDibujar;
	//No hay bandera, pone
	if ( ! tablero[columnaDeJugada][filaDeJugada]->tieneBandera() ){

		queDibujar = bandera;

		if ( (tablero[columnaDeJugada][filaDeJugada])->tieneBomba() ){
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

	return queDibujar;
}

cadena Juego::destaparCasillero(uint jugadorActual){

	cadena queDibujar;

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
	return queDibujar;
}


void Juego::prepararCasillero(){
	if(tablero[columnaDeJugada][filaDeJugada] == 0)
		( tablero[columnaDeJugada][filaDeJugada] ) = new Casillero();
}

uint Juego::evaluarBombasCircundantes(uint columnaDeCasillero, uint filaDeCasillero){

	uint circundantes = 0;
	for(int dFila = -1; dFila < 2; dFila++){
		for(int dColumna = -1; dColumna < 2; dColumna++ ){

			int columnaAEvaluar = columnaDeCasillero - dColumna;
			int filaAEvaluar = filaDeCasillero - dFila;

			if	 ( validarCoordenada(filaAEvaluar, columnaAEvaluar) &&
								(filaAEvaluar != (int)filaDeCasillero  ) &&
								(columnaAEvaluar != (int)columnaDeCasillero) &&
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

	for(uint columna = 0; columna < columnaMaxima; columna++ ){
		for(uint fila = 0; fila < filaMaxima; fila++){
			delete tablero[columna][fila];
		}
		delete tablero[columna];
	}
	delete [] tablero;
}




//			if(arbitro.devolverTipoDeJugada() == "0"){
//				for(int nFila = -1; nFila < 2; nFila++){
//					for(int nColumna = -1; nColumna < 2; nColumna++ ){
//
//						int columnaADescubrir = arbitro.devolverColumnaDeJugada() - nColumna;
//			    		int filaADescubrir = arbitro.devolverFilaDeJugada() - nFila;
//			            if( (filaADescubrir > 0 ) && (columnaADescubrir > 0) &&
//			            	(filaADescubrir <= (int)arbitro.devolverFilaMaxima() ) &&
//							columnaADescubrir <= (int)arbitro.devolverColumnaMaxima() ){
//
//			            	uint cantidadDeCircundantes = arbitro.evaluarBombasCircundantes(columnaADescubrir, filaADescubrir);
//							std::ostringstream ossNumeroADibujar;
//							ossNumeroADibujar << cantidadDeCircundantes;
//							std::string numeroADibujar = ossNumeroADibujar.str();
//							dibujante.cambiarCuadrante( columnaADescubrir -1, filaADescubrir -1, numeroADibujar, 0, false);
//			            }
//			        }
//				}
//			} else {
//				dibujante.cambiarCuadrante( arbitro.devolverColumnaDeJugada() -1,
//											arbitro.devolverFilaDeJugada() -1,
//											arbitro.devolverTipoDeJugada(),
//											arbitro.devolverTurno() + 1,
//											false);
//			}
//			dibujante.cambiarPuntaje( 	arbitro.devolverPuntaje(),
//										arbitro.devolverTurno() + 1 );
//
//			sigueLaPartida = ( ! arbitro.terminoLaPartida() );
