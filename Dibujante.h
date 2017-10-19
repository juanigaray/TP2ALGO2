/*
 * Dibujante.h
 *
 *  Created on: Oct 18, 2017
 *      Author: juan
 */

#ifndef DIBUJANTE_H_
#define DIBUJANTE_H_
#include "EasyBMP/EasyBMP.h"
#include <sstream>

typedef unsigned int uint;

class Dibujante{

  private:
	uint ordinalDeDibujo;

	uint alturaDeCuadrante;
	uint anchoDeCuadrante;
	uint anchoDeMargenIzquierdo;
	uint anchoDeMargenDerecho;
	uint alturaDeMargenSuperior;
	uint alturaDeMargenInferior;
	uint pixelesDeAncho;
	uint pixelesDeAlto;

	BMP imagen;

	std::string directorioDeImagenesFuente;

	//Post: La imagen tiene todos sus casilleros dibujados como cubiertos.
	void inicializarImagen(uint cantidadDeColumnas, uint cantidadDeFilas);

	char* strAPChar(std::string cadena);

  public:


	//Pre: Se pasan la cantidad de filas y de columnas del tablero, que son numeros naturales.
	//	   Si se pasan argumentos para las dimensiones de los margenes, deben ser naturales.
	//Post: Se crea un dibujante que solo va a crear la imagen con los casilleros, sin margenes
	//		Si se pasaron
	Dibujante(uint cantidadDeColumnas, uint cantidadDeFilas,
			  uint anchoDeMargenIzqPedido = 0, uint anchoMargenDerPedido = 0,
			  uint alturaDeMargenSupPedido = 0, uint alturaDeMargenInfPedido = 0);



	//Post: Devuelve el numero correspondiente al dibujo que se esta preparando.
	//		Es decir, la cantidad de dibujos que ya se hicieron es
	//		( informarNumeroDeDibujo() - 1 )
	uint informarNumeroDeDibujo();

	//Pre:
	//Post:
	void cambiarCuadrante(uint fila, uint columna, std::string queDibujar, uint jugador = 0);

	//Post:	Guarda una nueva imagen BMP con los cambios aplicados al tablero.
	//		El nombre de la imagen se crea de acuerdo a cuantas veces se llamo este metodo.
	void dibujarTablero();

};

#endif /* DIBUJANTE_H_ */
