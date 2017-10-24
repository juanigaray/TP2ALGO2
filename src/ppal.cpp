/*
 * ppal.cpp
 *
 *  Created on: Oct 23, 2017
 *      Author: juan
 */

typedef unsigned int uint;

#include "Presentador.h"
#include "Dibujante.h"
#include "Arbitro.h"

int main(){

	bool jugarDeNuevo = true;
	bool sigueLaPartida = true;

	while(jugarDeNuevo){

		Presentador presentador;
		//presentador.mostrarPresentacion();
		presentador.pedirDatosDeJuego();

		Dibujante dibujante( presentador.devolverColumnas(),
							 presentador.devolverFilas(),
							 presentador.devolverNumeroDeJugadores() );

		Arbitro arbitro( presentador.devolverDificultad(),
						 presentador.devolverNumeroDeJugadores(),
						 presentador.devolverFilas(),
						 presentador.devolverColumnas(),
			       		 presentador.devolverNombresDeLosJugadores() );

		while(sigueLaPartida){

			arbitro.declararTurno();
			arbitro.tomarJugada();
			dibujante.cambiarCuadrante( arbitro.devolverColumnaDeJugada(),
										arbitro.devolverFilaDeJugada(),
										arbitro.devolverTipoDeJugada(),
										arbitro.devolverTurno() );

			dibujante.cambiarPuntaje( 	arbitro.devolverPuntaje(),
										arbitro.devolverTurno()  );
			dibujante.dibujarTablero();

			sigueLaPartida = ( ! arbitro.terminoElJuego() );
		}
		presentador.consultarSiJugarDeNuevo();
		jugarDeNuevo = presentador.devolverSiJugarDeNuevo();
	}
	return 0;
}
