class Casillero{
	private:
	
		bool hayMina;
		unsigned int minasCircundantes;
		bool hayBandera;
		bool esVisible;	
		
	public:
	
		/*PRE: 
		 *POST: El casillero sin mina, cubierto y sin bandera.
		 *		Provisoriamente con 0 minas circundantes
		 */
		Casillero();
		
		/*PRE:
		 *POST: Informa si el casillero tiene una mina 
		 */
		 bool consultarMina();

		/*PRE:
		 *POST: Informa si el casillero tiene una bandera 
		 */
		bool consultarBandera();
			
		/*PRE:
		 *POST: el casillero pasa a tener una mina 
		 */		
		void asignarMina();
		
		/*PRE: 	Se le pasa como parametro el numero de minas circundantes
		 *POST: el casillero almacena este numero
		 */
		void asignarMinasCircundantes(unsigned int cantidad);
			
		/*PRE:	El casillero no tiene bandera
		 *POST: El casillero tiene bandera 
		 */
		void colocarBandera();
		
		/*PRE:	El casillero tiene bandera
		 *POST: El casillero no tiene bandera 
		 */
		void quitarBandera();

		/*PRE:
		 *POST: el casillero pasa a ser visible 
		 */
		void hacerVisible();
		
		/*PRE:
		 *POST: Si el casillero no es visible,
		 *			Si no tiene bandera, dibuja " -".
		 *			Si tiene bandera, dibuja " ?"
		 *		Si es visible,
		 *			Si tiene mina, dibuja " X".
		 *			Si no tiene mina, dibuja " " y consultarMinasCircundantes.
		 */
		void dibujar();
};