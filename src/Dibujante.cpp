/*
 * Dibujante.cpp
 *
 *  Created on: Oct 18, 2017
 *      Author: juan
 */
#include "Dibujante.h"

Dibujante::Dibujante(int cantidadDeColumnas, int cantidadDeFilas, int cantidadDeJugadores){

	//Definen de donde se van a leer los BMPs que componen la imagen
	directorioDeImagenesFuente= "src/ImagenesFuente/";
	directorioDeCasilleros = "Casilleros/";
	directorioDeMargenes = "Margenes/";
	directorioDePuntajes = "Puntajes/";
	bomba = "boom";
	bandera = "bandera";
	casilleroCubierto = "cubierto";
	margen = "margen";

	numeroDeDibujo = 1;
	columnasMinimasImagen = 18;
	columnasDelTablero = cantidadDeColumnas;
	filasDelTablero = cantidadDeFilas;

	columnasMargenLateral = 1;
	filasMargenSuperior = 1;

	//Dejo espacio para que se escriba "Jugador" hztalmente
	if (cantidadDeColumnas > columnasMinimasImagen){
		columnasTotalesImagen = cantidadDeColumnas + columnasMargenLateral * 2;
	} else {
		columnasTotalesImagen = columnasMinimasImagen;
	}

	filasTotalesImagen = filasDelTablero + 2 * (cantidadDeJugadores + 1) + filasMargenSuperior;

	BMP ejemploDeImagenFuente;
	cadena directorioDeEjemplo = directorioDeImagenesFuente + directorioDeCasilleros + casilleroCubierto + ".bmp";
	char* directorioLegible = &directorioDeEjemplo[0];
	ejemploDeImagenFuente.ReadFromFile(directorioLegible);

	alturaDeCuadrante = ejemploDeImagenFuente.TellHeight();
	anchoDeCuadrante = ejemploDeImagenFuente.TellWidth();

	inicializarImagen(cantidadDeJugadores);

}

void Dibujante::inicializarImagen(int cantidadDeJugadores){

	int pixelesDeAncho = columnasTotalesImagen * anchoDeCuadrante;
	int pixelesDeAlto = filasTotalesImagen * alturaDeCuadrante;

	imagen.SetSize(pixelesDeAncho, pixelesDeAlto);

	inicializarCasilleros();
	inicializarMargen(cantidadDeJugadores);
}

void Dibujante::inicializarCasilleros(){

	for(int filaActual = 0; filaActual < filasDelTablero; filaActual++){
		for(int columnaActual = 0; columnaActual < columnasDelTablero; columnaActual++){
			cambiarCuadrante(columnaActual, filaActual, casilleroCubierto, 0, false);
		}
	}
}

void Dibujante::inicializarPuntajes(int cantidadDeJugadores){

	for(int nroJugador = 1; nroJugador <= cantidadDeJugadores; nroJugador++){

		int filaDelJugador = filasMargenSuperior + filasDelTablero + 2 * nroJugador;

		cadena nombreJugador = "JUGADOR";

		cadena strNroJugador = hacerCadena(nroJugador);

		//Escribe "Jugador"
		for(int caracter = 0; caracter < nombreJugador.size() ; caracter++ ){

			cadena directorio = nombreJugador.substr(caracter, 1);
			cambiarCuadrante( 1 + caracter  , filaDelJugador, directorio , 0, true);
		}

		//Escribe el nro de jugador
		for(int cifra = 0; cifra < strNroJugador.size() ; cifra++ ){

			cadena directorio = strNroJugador.substr(cifra, 1);
			cambiarCuadrante( 9 + cifra  , filaDelJugador, directorio , 0, true);
		}

		cambiarPuntaje(0, nroJugador);
	}
}

void Dibujante::inicializarMargen(int cantidadDeJugadores){

	int columnaDeCuadrante;
	int filaDeCuadrante;

	//Superior
	for (columnaDeCuadrante = 0; columnaDeCuadrante < columnasTotalesImagen; columnaDeCuadrante++){
		for (filaDeCuadrante = 0; filaDeCuadrante < filasMargenSuperior; filaDeCuadrante++){
			cambiarCuadrante(columnaDeCuadrante, filaDeCuadrante, margen, 0, true);
		}
	}

	//Izquierdo
	for (columnaDeCuadrante = 0; columnaDeCuadrante < columnasMargenLateral; columnaDeCuadrante++){
		for (filaDeCuadrante = filasMargenSuperior; filaDeCuadrante < filasTotalesImagen; filaDeCuadrante++){
			cambiarCuadrante(columnaDeCuadrante, filaDeCuadrante, margen, 0, true);
		}
	}

	//Inferior
	for(columnaDeCuadrante = 0; columnaDeCuadrante < columnasTotalesImagen; columnaDeCuadrante++){
		cambiarCuadrante(columnaDeCuadrante, filasDelTablero + filasMargenSuperior, margen, 0, true);
	}

	//Derecho
	for(columnaDeCuadrante = columnasDelTablero + columnasMargenLateral; columnaDeCuadrante < columnasTotalesImagen; columnaDeCuadrante++){
		for(filaDeCuadrante = 1; filaDeCuadrante < filasDelTablero + filasMargenSuperior; filaDeCuadrante++){
			cambiarCuadrante(columnaDeCuadrante, filaDeCuadrante, margen, 0, true);
		}
	}

	//Espacio para los puntajes de los jugadores
	for(filaDeCuadrante = filasDelTablero + filasMargenSuperior; filaDeCuadrante < filasTotalesImagen; filaDeCuadrante++){
		for(columnaDeCuadrante = 0; columnaDeCuadrante < columnasTotalesImagen; columnaDeCuadrante++){
			cambiarCuadrante(columnaDeCuadrante, filaDeCuadrante, margen, 0, true);
		}
	}

	inicializarPuntajes(cantidadDeJugadores);
}

int Dibujante::informarNumeroDeDibujo(){
	return numeroDeDibujo;
}

void Dibujante::cambiarCuadrante(int columna, int fila, cadena queDibujar, int jugador, bool esMargen){

	int yAbsolutoDePixel = 0;
	int xAbsolutoDePixel = 0;

	BMP cuadrante;
	cadena subdirectorio;

	if(esMargen){
		subdirectorio = directorioDeMargenes;
	}else{
		subdirectorio = directorioDeCasilleros;;
		fila += filasMargenSuperior;
		columna += columnasMargenLateral;
	}

	cadena nombre = (directorioDeImagenesFuente + subdirectorio) + (queDibujar + ".bmp");
	char* nombreCompatible = &nombre[0];
	cuadrante.ReadFromFile( nombreCompatible );

	if (queDibujar == "bandera"){
		cuadrante.CreateStandardColorTable();
	}

	for ( int yRelativoDePixel = 0; yRelativoDePixel < alturaDeCuadrante; yRelativoDePixel++){

		yAbsolutoDePixel = yRelativoDePixel + fila * alturaDeCuadrante;

		for (int xRelativoDePixel = 0; xRelativoDePixel < anchoDeCuadrante; xRelativoDePixel++){

			xAbsolutoDePixel = xRelativoDePixel + columna * anchoDeCuadrante;

			//Si es bandera, tengo que asignarle el color del jugador al icono.
			if (	queDibujar == "bandera"
					&& 	cuadrante(xRelativoDePixel, yRelativoDePixel)->Red == 255
					&&	cuadrante(xRelativoDePixel, yRelativoDePixel)->Blue == 255
					&&	cuadrante(xRelativoDePixel, yRelativoDePixel)->Green == 255 ){

				imagen(xAbsolutoDePixel, yAbsolutoDePixel)->Red = cuadrante.GetColor(jugador).Red + 30;
				imagen(xAbsolutoDePixel, yAbsolutoDePixel)->Blue = cuadrante.GetColor(jugador).Blue + 30;
				imagen(xAbsolutoDePixel, yAbsolutoDePixel)->Green = cuadrante.GetColor(jugador).Green + 30;

			//Si el pixel es generico, lo copio de la imagen fuente
			} else {
				//Copio el pixel de la fuente a la imagen.
				PixelToPixelCopy(	cuadrante,	xRelativoDePixel, yRelativoDePixel,
									imagen, 	xAbsolutoDePixel, yAbsolutoDePixel);
			}
		}
	}
}

void Dibujante::cambiarPuntaje(int puntaje, int nroJugador){

	int filaDelJugador = filasDelTablero + filasMargenSuperior + 2 * nroJugador;

	cadena strJugador = hacerCadena(nroJugador);
	cadena strPuntaje = hacerCadena(puntaje);

	for(int cifra = 0; cifra < strPuntaje.size() ; cifra++ ){

		cadena directorio =  directorioDePuntajes + strPuntaje.substr(cifra, 1);

		cambiarCuadrante( 15 + cifra  , filaDelJugador, directorio , 0, true);
	}
}

void Dibujante::dibujarTablero(){

	cadena nombreDeArchivo = "Imagen " + hacerCadena(numeroDeDibujo) +".bmp";
	char* nombreCompatible = &nombreDeArchivo[0];

	imagen.WriteToFile( nombreCompatible );

	numeroDeDibujo++;
}

void Dibujante::eliminarJugador(int nroJugador){

	int filaDelJugador = filasDelTablero + 2 * nroJugador + filasMargenSuperior;
	int yInicial = alturaDeCuadrante * filaDelJugador + alturaDeCuadrante / 2;
	int yMax = yInicial + alturaDeCuadrante / 8;
	int xMax = columnasMinimasImagen * anchoDeCuadrante;

	for(int xDePixel = 0; xDePixel <  xMax; xDePixel++ ){
		for(int yDePixel = yInicial; yDePixel <  yMax; yDePixel++ ){
			imagen(xDePixel, yDePixel)->Red = 150;
		}
	}
}

cadena Dibujante::hacerCadena(int numero){
	std::ostringstream ossnumero;
	ossnumero << numero;
	return ossnumero.str();
}
