/*
 * principal.cpp
 *
 *  Created on: Sep 5, 2017
 *      Author: juan
 */

#include "Dibujante.h"


int main(){

	Dibujante dibujante(3,3);
	dibujante.cambiarCuadrante(0, 0, "0");
	dibujante.cambiarCuadrante(3, 3, "bandera", 1);
	dibujante.cambiarCuadrante(4, 4, "bandera", 2);
//	dibujante.cambiarCuadrante(6, 3, "bandera", 3);
//	dibujante.cambiarCuadrante(6, 2, "4");
//	dibujante.cambiarCuadrante(6, 1, "5");
//	dibujante.cambiarCuadrante(6, 0, "boom");
//	dibujante.cambiarCuadrante(5, 0, "6");
//	dibujante.cambiarCuadrante(5, 1, "7");
//	dibujante.cambiarCuadrante(5, 2, "8");
//	dibujante.cambiarCuadrante(5, 3, "bandera");


	dibujante.dibujarTablero();

	return 0;
}

