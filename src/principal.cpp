/*
 * principal.cpp
 *
 *  Created on: Sep 5, 2017
 *      Author: juan
 */

#include "Dibujante.h"


int main(){
	bool jugarDeNuevo = true;
	bool sigueLaPartida = true;

	while(jugarDeNuevo){
		Presentador presentador;
		presentador.mostrarPresentacion();
		presentador.pedirDatosDeJuego();
		while(sigueLaPartida){



			Dibujante dibujante( presentador.devolverColumnas(),
								 presentador.devolverFilas(),
								 presentador.devolverNumeroDeJugadores() );

			Arbitro arbitro( presentador.devolverDificultad(),
							 presentador.devolverNumeroDeJugadores() );

			arbitro.declararTurno();
			arbitro.tomarJugada();
			dibujante.cambiarCuadrante( arbitro.devolverColumnaDeJugada(),
										arbitro.devolverFilaDeJugada(),
										arbitro.devolverTipoDeJugada(),
										arbitro.devolverTurno() );

			dibujante.cambiarPuntaje( 	arbitro.devolverPuntaje(),
										arbitro.devolverTurno() );
			dibujante.dibujarTablero();

			sigueLaPartida = ( ! arbitro.terminoElJuego() );
		}
		presentador.consultarSiJugarDeNuevo();
		jugarDeNuevo = presentador.devolverSiJugarDeNuevo();
	}

	return 0;
}

