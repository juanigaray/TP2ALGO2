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

	//Dejo espacio para que se escriba "Jugador" hztalmente
	if(cantidadDeColumnas > 8){
		columnasTotalesImagen = cantidadDeColumnas;
	} else {
		columnasTotalesImagen = 8;
	}

	filasTotalesImagen = filasDelTablero + 2 * (cantidadDeJugadores + 1);

	BMP ejemploDeImagenFuente;
	ejemploDeImagenFuente.ReadFromFile("src/ImagenesFuente/Casilleros/0.bmp");

	alturaDeCuadrante = ejemploDeImagenFuente.TellHeight();
	anchoDeCuadrante = ejemploDeImagenFuente.TellWidth();

	inicializarImagen(cantidadDeJugadores);

}

void Dibujante::inicializarImagen(uint cantidadDeJugadores){

	uint pixelesDeAncho = columnasTotalesImagen * anchoDeCuadrante;
	uint pixelesDeAlto = filasTotalesImagen * alturaDeCuadrante;

	imagen.SetSize(pixelesDeAlto,pixelesDeAncho);

	inicializarCasilleros();
	inicializarMargen(cantidadDeJugadores);

}

void Dibujante::inicializarCasilleros(){

	for(uint filaActual = 0; filaActual < filasDelTablero; filaActual++){
		for(uint columnaActual = 0; columnaActual < columnasDelTablero; columnaActual++){
			cambiarCuadrante(columnaActual, filaActual, "cubierto", 0, false);
		}
	}
}

void Dibujante::inicializarMargen(uint cantidadDeJugadores){

	uint columnaDeCuadrante;
	cambiarCuadrante(0, filasDelTablero,"margen", 0, true);
	cambiarCuadrante(1, filasDelTablero,"J", 0, true);
	cambiarCuadrante(2, filasDelTablero,"U", 0, true);
	cambiarCuadrante(3, filasDelTablero,"G", 0, true);
	cambiarCuadrante(4, filasDelTablero,"A", 0, true);
	cambiarCuadrante(5, filasDelTablero,"D", 0, true);
	cambiarCuadrante(6, filasDelTablero,"O", 0, true);
	cambiarCuadrante(7, filasDelTablero,"R", 0, true);
	cambiarCuadrante(8, filasDelTablero,"margen", 0, true);

	for(uint filaDeCuadrante = filasDelTablero + 1; filaDeCuadrante < filasTotalesImagen; filaDeCuadrante++){
		for(columnaDeCuadrante = 0; columnaDeCuadrante <= columnasTotalesImagen; columnaDeCuadrante++){
			cambiarCuadrante(columnaDeCuadrante, filaDeCuadrante, "margen", 0, true);
		}
	}
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
	}

	std::string nombre = directorioDeImagenesFuente + subdirectorio + queDibujar + ".bmp";
	char* nombreCompatible = &nombre[0];
	cuadrante.ReadFromFile( nombreCompatible );

	if (queDibujar == "bandera"){
		cuadrante.CreateStandardColorTable();
	}

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



