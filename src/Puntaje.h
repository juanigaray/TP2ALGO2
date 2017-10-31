#ifndef PUNTAJE_H_
#define PUNTAJE_H_

#include <iostream>

typedef unsigned int uint;

// debe ser creado por el arbitro al iniciarlo
class Puntaje{

  private:

	uint puntos;
	uint puntosEspeciales;


  public:

	/* Pre puntaje recibe la dificultad
		 * Post inicializa los puntajes de acuerdo a la dificultad
		 */
		Puntaje(uint dificultad);
  
  	/* 
	 * Post devuelve puntaje estandar
	 */
	uint devolverPuntos();
	
	/* 
	 * Post devuelve puntaje especial
	 * caso de un jugador corrige a otro
	 */
	uint devolverPuntosEspeciales();
	
};



#endif
