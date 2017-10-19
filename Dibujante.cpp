/*
 * Dibujante.cpp
 *
 *  Created on: Oct 18, 2017
 *      Author: juan
 */
#include "Dibujante.h"


Dibujante::Dibujante(uint cantidadDeColumnas, uint cantidadDeFilas, uint cantidadDeJugadores){

	ordinalDeDibujo = 0;
	directorioDeImagenesFuente = "src/ImagenesFuente/";

	BMP ejemploDeImagenFuente;
	ejemploDeImagenFuente.ReadFromFile("src/ImagenesFuente/0.bmp");

	alturaDeCuadrante = ejemploDeImagenFuente.TellHeight();
	anchoDeCuadrante = ejemploDeImagenFuente.TellWidth();

	std::cout << alturaDeCuadrante;

	anchoDeMargenLateral = anchoDeCuadrante * 2;

	alturaDeMargenInferior = alturaDeCuadrante * 2;
	//En el margen superior se van a anotar los puntajes de cada jugador.
	alturaDeMargenSuperior = cantidadDeJugadores * alturaDeMargenInferior;


	pixelesDeAncho = (anchoDeCuadrante * cantidadDeFilas) + 2 * anchoDeMargenLateral;
	pixelesDeAlto = (alturaDeCuadrante * cantidadDeColumnas) + alturaDeMargenSuperior + alturaDeMargenInferior;

	//Se pasan al reves los parametros en setsize
	imagen.SetSize(pixelesDeAlto, pixelesDeAncho);
	inicializarImagen(cantidadDeColumnas, cantidadDeFilas, cantidadDeJugadores);

}

uint Dibujante::informarNumeroDeDibujo(){
	return ordinalDeDibujo;
}


void Dibujante::cambiarCuadrante(uint columna, uint fila, std::string queDibujar, uint jugador){

	uint yAbsolutoDePixel = 0;
	uint xAbsolutoDePixel = 0;

	BMP cuadrante;

	std::string nombre = directorioDeImagenesFuente + queDibujar + ".bmp";

	char* nombreCompatible = &nombre[0];

	cuadrante.ReadFromFile( nombreCompatible );
	cuadrante.CreateStandardColorTable();

	for ( uint yRelativoDePixel = 0; yRelativoDePixel < alturaDeCuadrante; yRelativoDePixel++){

		yAbsolutoDePixel = yRelativoDePixel + (fila * alturaDeCuadrante) + alturaDeMargenSuperior;

		for (uint xRelativoDePixel = 0; xRelativoDePixel < anchoDeCuadrante; xRelativoDePixel++){

			xAbsolutoDePixel = xRelativoDePixel + (columna * anchoDeCuadrante) + anchoDeMargenLateral;



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

void Dibujante::inicializarCasilleros(uint cantidadDeColumnas, uint cantidadDeFilas){

	for(uint filaActual = 0; filaActual < cantidadDeFilas; filaActual++){
		for(uint columnaActual = 0; columnaActual < cantidadDeColumnas; columnaActual++){
			cambiarCuadrante(columnaActual, filaActual, "cubierto");
			}
	}
}

void Dibujante::inicializarMargenes(uint cantidadDeColumnas, uint cantidadDeFilas, uint cantidadDeJugadores){
		//Lo mejor sería dividir también los márgenes en celdas con una imagen precargada.
		//Me queda de tarea.

}

void Dibujante::inicializarImagen(uint cantidadDeColumnas, uint cantidadDeFilas, uint cantidadDeJugadores){
	inicializarCasilleros(cantidadDeColumnas, cantidadDeFilas);
	inicializarMargenes(cantidadDeColumnas, cantidadDeFilas, cantidadDeJugadores);

}


void Dibujante::dibujarTablero(){

	std::ostringstream numero;
	numero << ordinalDeDibujo;
	std::string nombreDeArchivo = "Imagen " + numero.str() +".bmp";
	char* nombreCompatible = &nombreDeArchivo[0];

	imagen.WriteToFile( nombreCompatible );

	ordinalDeDibujo++;

}



