#ifndef PUNTAJE_H_
#define PUNTAJE_H_

#include <iostream>

// debe ser creado por el arbitro al iniciarlo
class Puntaje{

  private:

	int puntos;
	int puntosEspeciales;


  public:

	/* Pre puntaje recibe la dificultad
		 * Post inicializa los puntajes de acuerdo a la dificultad
		 */
		Puntaje(int dificultad);
  
  	/* 
	 * Post devuelve puntaje estandar
	 */
	int devolverPuntos();
	
	/* 
	 * Post devuelve puntaje especial
	 * caso de un jugador corrige a otro
	 */
	int devolverPuntosEspeciales();
	
};



#endif
