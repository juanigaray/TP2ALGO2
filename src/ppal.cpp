/*
 * ppal.cpp
 *
 *  Created on: Oct 23, 2017
 *      Author: juan
 */

typedef unsigned int uint;

#include "Presentador.h"
#include "Dibujante.h"
#include "Juego.h"


int main(){

	bool jugarDeNuevo = true;
	bool finDeLaPartida = true;

	while(jugarDeNuevo){

		Presentador presentador;
		presentador.pedirDatosDeJuego();

		Juego juego( 	 presentador.devolverDificultad(),
						 presentador.devolverNumeroDeJugadores(),
						 presentador.devolverFilas(),
						 presentador.devolverColumnas(),
			       		 presentador.devolverNombresDeLosJugadores() );

		while(! finDeLaPartida){

			juego.avanzarTurno();
			juego.declararTurno();
			juego.tomarJugada();
			finDeLaPartida = juego.terminoLaPartida();
		}

		presentador.consultarSiJugarDeNuevo();
		jugarDeNuevo = presentador.devolverSiJugarDeNuevo();
	}
	return 0;
}
