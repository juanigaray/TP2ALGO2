/*
 * Arbitro.h
 *
 *  Created on: Oct 19, 2017
 *      Author: juan
 */

#ifndef ARBITRO_H_
#define ARBITRO_H_

class Arbitro{
  private:




  public:
	Arbitro(uint dificultad, uint numeroDeJugadores);
	uint devolverColumnaDeJugada();
	uint devolverFilaDeJugada();
	std::string devolverTipoDeJugada();
	uint devolverTurno();
	uint devolverPuntaje();
	bool terminoElJuego();
	void declararTurno();
	void tomarJugada();
};



#endif /* ARBITRO_H_ */
