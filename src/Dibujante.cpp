/*
 * Dibujante.cpp
 *
 *  Created on: Oct 18, 2017
 *      Author: juan
 */
#include "Dibujante.h"

/*
 * 		Privado
 */

void Dibujante::inicializarCasilleros(uint cantidadDeColumnas, uint cantidadDeFilas){

	for(uint filaActual = 0; filaActual < cantidadDeFilas; filaActual++){
		for(uint columnaActual = 0; columnaActual < cantidadDeColumnas; columnaActual++){
			cambiarCuadrante(columnaActual, filaActual, "cubierto");
		}
	}
}

void Dibujante::inicializarmargenSuperior(){

}

void Dibujante::inicializarmargenInferior(){

}

void Dibujante::inicializarmargenIzquierdo(){

}

void Dibujante::inicializarmargenDerecho(){

}

void Dibujante::inicializarMargenes(uint cantidadDeColumnas, uint cantidadDeFilas, uint cantidadDeJugadores){
	inicializarmargenSuperior();
	inicializarmargenSuperior();
	inicializarmargenIzquierdo();
	inicializarmargenDerecho();

}

void Dibujante::inicializarImagen(uint cantidadDeColumnas, uint cantidadDeFilas, uint cantidadDeJugadores){

	uint pixelesDeAncho = (cantidadDeFilas + columnasMargenIzquierdo + columnasMargenDerecho) * anchoDeCuadrante;
	uint pixelesDeAlto = (cantidadDeColumnas + filasMargenInferior + filasMargenInferior) * alturaDeCuadrante;

	imagen.SetSize(pixelesDeAlto, pixelesDeAncho);
	inicializarCasilleros(cantidadDeColumnas, cantidadDeFilas);
	inicializarMargenes(cantidadDeColumnas, cantidadDeFilas, cantidadDeJugadores);
}


/*
 * 		Publico
 */

Dibujante::Dibujante(uint cantidadDeColumnas, uint cantidadDeFilas, uint cantidadDeJugadores){

	directorioDeImagenesFuente = "src/ImagenesFuente/";
	directorioDeCasilleros = "Casilleros/";
	directorioDeMargenes = "Margenes";

	columnas = cantidadDeColumnas;
	filas = cantidadDeFilas;
	ordinalDeDibujo = 1;

	BMP ejemploDeImagenFuente;
	ejemploDeImagenFuente.ReadFromFile("src/ImagenesFuente/0.bmp");

	alturaDeCuadrante = ejemploDeImagenFuente.TellHeight();
	anchoDeCuadrante = ejemploDeImagenFuente.TellWidth();

	columnasMargenIzquierdo = 2;
	columnasMargenDerecho = 2;
	filasMargenInferior = 2;
	filasMargenSuperior= 2 * (cantidadDeJugadores + 1);

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

		yAbsolutoDePixel = yRelativoDePixel + (fila + filasMargenSuperior) * alturaDeCuadrante;

		for (uint xRelativoDePixel = 0; xRelativoDePixel < anchoDeCuadrante; xRelativoDePixel++){

			xAbsolutoDePixel = xRelativoDePixel + (columna + columnasMargenIzquierdo) * anchoDeCuadrante;

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

void Dibujante::cambiarPuntaje(uint puntaje, uint jugador){

}

void Dibujante::dibujarTablero(){

	std::ostringstream numero;
	numero << ordinalDeDibujo;
	std::string nombreDeArchivo = "Imagen " + numero.str() +".bmp";
	char* nombreCompatible = &nombreDeArchivo[0];

	imagen.WriteToFile( nombreCompatible );

	ordinalDeDibujo++;

}



