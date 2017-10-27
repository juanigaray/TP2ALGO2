/*
 * Dibujante.cpp
 *
 *  Created on: Oct 18, 2017
 *      Author: juan
 */
#include "Dibujante.h"

Dibujante::Dibujante(uint cantidadDeColumnas, uint cantidadDeFilas, uint cantidadDeJugadores){

	directorioDeImagenesFuente = "src/ImagenesFuente/";
	directorioDeCasilleros = "Casilleros/";
	directorioDeMargenes = "Margenes/";
	numeroDeDibujo = 1;

	columnasDelTablero = cantidadDeColumnas;
	filasDelTablero = cantidadDeFilas;

	columnaInicialTablero = 2;
	columnaFinalTablero = columnasDelTablero + columnaInicialTablero;
	filaInicialTablero = ;
	filaFinalTablero = filasDelTablero + filaInicialTablero;

	columnasTotalesImagen = columnaFinalTablero + 2;
	filasTotalesImagen = filaFinalTablero + 2 * (cantidadDeJugadores + 1);



	BMP ejemploDeImagenFuente;
	ejemploDeImagenFuente.ReadFromFile("src/ImagenesFuente/Casilleros/0.bmp");

	alturaDeCuadrante = ejemploDeImagenFuente.TellHeight();
	anchoDeCuadrante = ejemploDeImagenFuente.TellWidth();



	inicializarImagen(cantidadDeJugadores);

}

void Dibujante::inicializarCasilleros(){

	for(uint filaActual = 0; filaActual < filasDelTablero; filaActual++){
		for(uint columnaActual = 0; columnaActual < columnasDelTablero; columnaActual++){
			cambiarCuadrante(columnaActual, filaActual, "cubierto");
		}
	}
}

void Dibujante::inicializarMargen(uint desdeFila, uint hastaFila, uint desdeColumna, uint hastaColumna){


}

void Dibujante::inicializarMargenes(uint cantidadDeJugadores){
	//Sup
	inicializarMargen(0, filaInicialTablero, 0, columnasTotalesImagen);
	//Izq
	inicializarMargen(filaInicialTablero, filaFinalTablero, 0, columnaInicialTablero);
	//Inf
	inicializarMargen(filaFinalTablero, filasTotalesImagen, 0, columnasTotalesImagen);
	//Der
	inicializarMargen(filaInicialTablero, filaFinalTablero, columnaFinalTablero, columnasTotalesImagen);
}

uint Dibujante::informarNumeroDeDibujo(){
	return numeroDeDibujo;
}

void Dibujante::cambiarCuadrante(uint columna, uint fila, std::string queDibujar, uint jugador, bool margen){

	uint yAbsolutoDePixel = 0;
	uint xAbsolutoDePixel = 0;

	BMP cuadrante;
	std::string subdirectorio;

	if(margen){
		subdirectorio = directorioDeMargenes;
	}else{
		subdirectorio = directorioDeCasilleros;

		fila += filaInicialTablero;
		columna += columnaInicialTablero;
	}

	std::string nombre = directorioDeImagenesFuente + subdirectorio + queDibujar + ".bmp";

	char* nombreCompatible = &nombre[0];

	cuadrante.ReadFromFile( nombreCompatible );
	cuadrante.CreateStandardColorTable();

	for ( uint yRelativoDePixel = 0; yRelativoDePixel < alturaDeCuadrante; yRelativoDePixel++){

		yAbsolutoDePixel = yRelativoDePixel + fila * alturaDeCuadrante;

		for (uint xRelativoDePixel = 0; xRelativoDePixel < anchoDeCuadrante; xRelativoDePixel++){

			xAbsolutoDePixel = xRelativoDePixel + columna * anchoDeCuadrante;

			//Si es bandera, tengo que asignarle el color del jugador al icono.
			if (	queDibujar == "bandera"
					&& 	cuadrante(xRelativoDePixel, yRelativoDePixel)->Red == 255
					&&	cuadrante(xRelativoDePixel, yRelativoDePixel)->Blue == 255
					&&	cuadrante(xRelativoDePixel, yRelativoDePixel)->Green == 255 ){

				imagen(xAbsolutoDePixel, yAbsolutoDePixel)->Red = cuadrante.GetColor(jugador).Red;
				imagen(xAbsolutoDePixel, yAbsolutoDePixel)->Blue = cuadrante.GetColor(jugador).Blue;
				imagen(xAbsolutoDePixel, yAbsolutoDePixel)->Green = cuadrante.GetColor(jugador).Green;

			//Si el pixel es generico, lo copio de la imagen fuente
			} else {
				//Copio el pixel de la fuente a la imagen.
				PixelToPixelCopy(	cuadrante,	xRelativoDePixel, yRelativoDePixel,
									imagen, 	xAbsolutoDePixel, yAbsolutoDePixel);
			}
		}
	}
}

void Dibujante::cambiarPuntaje(int puntaje, uint jugador){
	if (puntaje != -1 ){
		//

	}
}

void Dibujante::dibujarTablero(){

	std::ostringstream numero;
	numero << numeroDeDibujo;
	std::string nombreDeArchivo = "Imagen " + numero.str() +".bmp";
	char* nombreCompatible = &nombreDeArchivo[0];

	imagen.WriteToFile( nombreCompatible );

	numeroDeDibujo++;
}



