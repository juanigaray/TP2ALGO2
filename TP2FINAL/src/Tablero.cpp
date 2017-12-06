/*
 * Tablero.cpp
 *
 *  Created on: Nov 17, 2017
 *      Author: juan
 */

#include "Tablero.h"


//METODOS DE INICIALIZACION

Tablero::Tablero(){
	columnaMaxima = 1;
	filaMaxima = 1;
	bombasTotales = 0;
	casillerosDestapados = 0;
	matriz = 0;
}

Tablero::Tablero(int columnas, int filas,  int dificultad){
	if (columnas == 0 || filas == 0){
		throw "Intento de crear tablero de tamanyo cero";
	}

	columnaMaxima = columnas;
	filaMaxima = filas;
	bombasTotales =  (filas * columnas * dificultad) / 20;
	casillerosDestapados = 0;
	inicializarMatriz();
	crearBombas(bombasTotales);
}

void Tablero::asignarDimensionesYDificultad(int columnas, int filas,  int dificultad){
	if (columnas == 0 || filas == 0){
		throw "Intento de crear tablero de tamano cero";
	}

	columnaMaxima = columnas;
	filaMaxima = filas;
	bombasTotales =  (filas * columnas * dificultad) / 20;
	casillerosDestapados = 0;
	inicializarMatriz();
	crearBombas(bombasTotales);
}

void Tablero::inicializarMatriz(){

	matriz = new Casillero**[columnaMaxima];

	//A cada columna le asigno un array de n casilleros, n = nro de filas
	for ( int columna = 0; columna < columnaMaxima; columna++){

		matriz[columna] = new Casillero*[filaMaxima];

		for ( int fila = 0; fila < filaMaxima; fila++ ){

			matriz[columna][fila] = NULL;
		}
	}
}

void Tablero::crearBombas( int dificultad){

	srand(time(NULL));
	int bombasRestantes = bombasTotales;

	while (bombasRestantes > 0){
		//Genero dos numeros semi-aleatorios para usar de coordenada
		int xAleatorio = rand() % (columnaMaxima - 1);
		int yAleatorio = rand() % (filaMaxima - 1);

		//solo afecta el casillero si no hay una mina ya sobre el
		if ( matriz[xAleatorio][yAleatorio] == 0 ){
			matriz[xAleatorio][yAleatorio] = new Casillero(true);
			bombasRestantes --;
		}
	}
}

void Tablero::prepararCasillero(int columnaDeCasillero, int filaDeCasillero){
	if( esCoordenadaValida(columnaDeCasillero, filaDeCasillero) && (! estaIniciado(columnaDeCasillero, filaDeCasillero)) )
		matriz[columnaDeCasillero][filaDeCasillero] = new Casillero();
}





//SET

bool Tablero::colocarBandera(int columnaDeJugada, int filaDeJugada, int jugadorActual){

	if (! esCoordenadaValida(columnaDeJugada, filaDeJugada)){
		std::string mensaje = "Intenta colocar bandera fuera del tablero";
		throw mensaje;
	}
	prepararCasillero(columnaDeJugada, filaDeJugada);
	matriz[columnaDeJugada][filaDeJugada]->colocarBandera(jugadorActual);
	return matriz[columnaDeJugada][filaDeJugada]->tieneBomba();
}

bool Tablero::quitarBandera(int columnaDeJugada, int filaDeJugada){

	if (! esCoordenadaValida(columnaDeJugada, filaDeJugada)){
		throw "Intenta quitar bandera fuera del tablero";
	}
	matriz[columnaDeJugada][filaDeJugada]->quitarBandera();
	return (! matriz[columnaDeJugada][filaDeJugada]->tieneBomba());
}

void Tablero::descubrirCasillero(int columna, int fila){

	if ( esCoordenadaValida(columna, fila) ){
		prepararCasillero(columna, fila);
		matriz[columna][fila]->destapar();
		this->casillerosDestapados ++;
	}
}



//METODOS DE OBTENCION

 int Tablero::obtenerFilaMaxima(){
	return filaMaxima;
}

 int Tablero::obtenerColumnaMaxima(){
	return columnaMaxima;
}

 int Tablero::obtenerJugadorQueColocoBandera(int columnaDeJugada, int filaDeJugada){
  return matriz[columnaDeJugada][filaDeJugada]->quienPusoLaBandera();
 }

int Tablero::obtenerNumeroDeBombasCircundantes( int columnaDeCasillero,  int filaDeCasillero){

	int circundantes = 0;
	for(int dFila = -1; dFila < 2; dFila++){
		for(int dColumna = -1; dColumna < 2; dColumna++ ){

			int columnaAEvaluar = columnaDeCasillero + dColumna;
			int filaAEvaluar = filaDeCasillero + dFila;

			if	( hayBombaEn(columnaAEvaluar, filaAEvaluar)){
				circundantes++;
			}
		}
	}
	return circundantes;
}


//METODOS DE VALIDACION

bool Tablero::esCoordenadaValida(int columna, int fila){
	return ( columna >= 0 && fila >= 0 && columna < columnaMaxima && fila < filaMaxima);
}

bool Tablero::estaIniciado( int columna,  int fila){
	return (matriz[columna][fila] != NULL);
}

bool Tablero::existe( int columna,  int fila){
	return (esCoordenadaValida(columna, fila) && estaIniciado(columna, fila));
}

bool Tablero::hayBombaEn( int columna,  int fila){
	return ( existe(columna, fila) && matriz[columna][fila]->tieneBomba() );
}

bool Tablero::hayBanderaEn( int columna,  int fila){
	return ( existe(columna, fila) && matriz[columna][fila]->tieneBandera() );
}

bool Tablero::estaDescubierto( int columna,  int fila){
	return ( existe(columna, fila) && matriz[columna][fila]->estaDescubierto());
}

bool Tablero::noQuedanCasilleros(){
	return (casillerosDestapados == ( (filaMaxima * columnaMaxima) - bombasTotales ));
}


Tablero::~Tablero(){
	for(int columna = 0; columna < columnaMaxima; columna++ ){
		for(int fila = 0; fila < filaMaxima; fila++){
			if (matriz[columna][fila] != 0){
				delete matriz[columna][fila];
			}
		}
		delete matriz[columna];
	}
	delete [] matriz;
}
