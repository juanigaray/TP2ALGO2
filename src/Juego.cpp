
/*
 * Arbitro.cpp
 *
 *  Created on: Oct 22, 2017
 *      Author: juan
 */

#include "Juego.h"

Juego::Juego(int dificultadPedida, int numeroDeJugadores, int filas, int columnas, cadena* nombresDeJugadores){

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

	inicializarTablero();

	this->casillerosDestapados = 0;
	this->bombasTotales =  (filaMaxima * columnaMaxima * dificultadPedida)/5 ;
	crearBombas(dificultadPedida);

	this->dibujante->dibujarTablero();
}

void Juego::inicializarTablero(){

	//A cada columna le asigno un array de n casilleros, n = nro de filas
	for(int col =0; col < columnaMaxima; col++){

		tablero[col] = new Casillero*[filaMaxima];

		for(int fil = 0; fil < filaMaxima; fil++ ){

			tablero[col][fil] = NULL;
		}
	}
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
	filaDeJugada = pedirNumero("Por favor, ingrese la fila donde desea realizar la jugada", filaMaxima) - 1;
	columnaDeJugada = pedirNumero("Por favor, ingrese la columna donde desea realizar la jugada", columnaMaxima) - 1;
}

void Juego::avanzarTurno(){
	arbitro->avanzarTurno();
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

		prepararCasillero(columnaDeJugada, filaDeJugada);

		//Es colocar/quitar bandera:
		if ( (opcionElegida == 1) && (! estaDescubierto()) ){

			cambiarBandera(jugadorActual);
			haJugado = true;

		//Es destapar
		} else if ( ! tieneBandera() ) {

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
	if ( ! tieneBandera() ){

		queDibujar = bandera;

		if ( tieneBomba() ){
			this->arbitro->sumarPuntaje(1);

		} else {
			this->arbitro->sumarPuntaje(-1);
		}

		this->tablero[columnaDeJugada][filaDeJugada]->colocarBandera(jugadorActual);

	//Hay bandera, saca
	} else {

		queDibujar = casilleroCubierto;

		//No pertenece a este jugador
		if ( ! (tablero[columnaDeJugada][filaDeJugada]->quienPusoLaBandera() == jugadorActual) ){

			//Era una bandera bien puesta
			if ( tieneBomba() ){
				this->arbitro->sumarPuntaje(-2);

			//Era una bandera mal puesta
			} else {
				this->arbitro->sumarPuntaje(2);
			}
		}
		this->tablero[columnaDeJugada][filaDeJugada]->quitarBandera();
	}
	this->dibujante->cambiarPuntaje( devolverPuntaje(), jugadorActual );
	this->dibujante->cambiarCuadrante(columnaDeJugada, filaDeJugada, queDibujar, jugadorActual, false);
}

void Juego::descubrirCasillero(int columnaDeCasillero, int filaDeCasillero, int jugadorActual){

	cadena queDibujar;

	tablero[columnaDeCasillero][filaDeCasillero]->destapar();

	//Tiene bomba
	if ( tablero[columnaDeCasillero][filaDeCasillero]->tieneBomba() ){

		queDibujar = bomba;
		arbitro->eliminarJugador();
		dibujante->eliminarJugador(jugadorActual);

	//No tiene bomba
	} else {

		int numeroDeBombasCircundantes = evaluarBombasCircundantes(columnaDeCasillero, filaDeCasillero);
		queDibujar = hacerCadena(numeroDeBombasCircundantes);
		if(numeroDeBombasCircundantes == 0){

			descubrirCasillerosCircundantes(columnaDeCasillero, filaDeCasillero);
		}
	}
	this->dibujante->cambiarCuadrante(columnaDeCasillero, filaDeCasillero, queDibujar, jugadorActual, false);
}


void Juego::prepararCasillero(int columnaDeCasillero, int filaDeCasillero){
	if(tablero[columnaDeCasillero][filaDeCasillero] == 0)
		tablero[columnaDeCasillero][filaDeCasillero] = new Casillero();
}

int Juego::evaluarBombasCircundantes(int columnaDeCasillero, int filaDeCasillero){

	int circundantes = 0;
	for(int dFila = -1; dFila < 2; dFila++){
		for(int dColumna = -1; dColumna < 2; dColumna++ ){

			int columnaAEvaluar = columnaDeCasillero + dColumna;
			int filaAEvaluar = filaDeCasillero + dFila;

			if	( validarCoordenada(columnaAEvaluar, filaAEvaluar) &&
				(filaAEvaluar != (int)filaDeCasillero  ) &&
				(columnaAEvaluar != (int)columnaDeCasillero) &&
				(tablero[columnaAEvaluar][filaAEvaluar] != 0) &&
				tablero[columnaAEvaluar][filaAEvaluar]->tieneBomba()	){

				circundantes++;

			}
		}
	}
	return circundantes;
}

void Juego::descubrirCasillerosCircundantes(int columnaDeCasillero, int filaDeCasillero){

	for(int dFila = -1; dFila < 2; dFila++){
		for(int dColumna = -1; dColumna < 2; dColumna++ ){

			int columnaAEvaluar = columnaDeCasillero + dColumna;
			int filaAEvaluar = filaDeCasillero + dFila;

			if	( validarCoordenada(columnaAEvaluar, filaAEvaluar)){

				prepararCasillero(columnaAEvaluar, filaAEvaluar);

				if (! tablero[columnaAEvaluar][filaAEvaluar]->estaDescubierto() ){

					//Llamada recursiva entre el metodo actual y descubrirCasillero.
					descubrirCasillero(columnaAEvaluar, filaAEvaluar, 0);
				}
			}
		}
	}
}

bool Juego::validarCoordenada(int columna, int fila){
	return ( (fila < (int)filaMaxima) && (columna < (int)columnaMaxima) && (fila >= 0) && (columna >= 0) );
}

void Juego::declararTurno(){
	std::cout << "Es el turno de "<< (arbitro->devolverJugador())->consultarNombre() << std::endl;
}

int Juego::devolverPuntaje(){
	int puntajeJugador = arbitro->devolverPuntaje();
	if (puntajeJugador < 0) {
		return 0;
	} else {
		return puntajeJugador;
	}
}

bool Juego::tieneBandera(){
	return ( ( tablero[columnaDeJugada][filaDeJugada] != 0) && tablero[columnaDeJugada][filaDeJugada]->tieneBandera()  );
}

bool Juego::tieneBomba(){
	return ( ( tablero[columnaDeJugada][filaDeJugada] != 0) && tablero[columnaDeJugada][filaDeJugada]->tieneBomba()  );
}

bool Juego::estaDescubierto(){
	return ( ( tablero[columnaDeJugada][filaDeJugada] != 0) && tablero[columnaDeJugada][filaDeJugada]->estaDescubierto()  );
}

void Juego::crearBombas(int dificultad){

	srand (time(NULL));
	int bombasRestantes = bombasTotales;

	while (bombasRestantes > 0){

		//Genero dos numeros semi-aleatorios para usar de coordenada
		int xAleatorio = rand() % (columnaMaxima - 1);
		int yAleatorio = rand() % (filaMaxima - 1);

		//solo afecta el casillero si no hay una mina ya sobre el
		if ( tablero[xAleatorio][yAleatorio] == 0 ){

			tablero[xAleatorio][yAleatorio] = new Casillero(true);
			bombasRestantes --;
		}
	}
}

void Juego::eliminarBandera(int fila, int columna){
	tablero[columna][fila]->quitarBandera();
}

bool Juego::terminoLaPartida(){
	if ( arbitro->quedaUno() || this->noQuedanCasilleros() ){
		arbitro->anunciarGanador();
		return true;
	}
	else return false;
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

	for(int columna = 0; columna < columnaMaxima; columna++ ){
		for(int fila = 0; fila < filaMaxima; fila++){
			if (tablero[columna][fila] != 0){
				delete tablero[columna][fila];
			}
		}
		delete tablero[columna];
	}
	delete [] tablero;
}


