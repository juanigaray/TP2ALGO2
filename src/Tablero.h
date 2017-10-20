class Tablero{
	
	private:
	
		unsigned int nroFilas;
		unsigned int nroColumnas;
		Casillero* matriz[]; //chequear
	
	public:
	
		/*PRE: 	Se le pasan como parametros dos numeros enteros positivos
		 *POST: El tablero tiene la cantidad de filas igual al primer numero
		 *		y la cantidad de columnas igual al segundo numero.
		 *		
		 */
		Tablero(unsigned int filasIngresadas, unsigned int columnasIngresadas);

		/*PRE: 	Se le pasan dos enteros positivos menores a la cantidad total de filas 
		 *		y la cantidad total de columnas respectivamente.
		 *POST: Descubre el casillero. Devuelve si se piso una mina.
		*/
		bool descubrirCasillero(unsigned int fila, unsigned int columna);
		
		/*PRE: 	Se le pasan dos enteros positivos menores a la cantidad total de filas 
		 *		y la cantidad total de columnas respectivamente.
		 *		El casillero no esta descubierto.
		 *		El casillero no tiene bandera.
		 *POST: El casillero pasa a tener una bandera.
		 */
		void colocarBandera(unsigned int fila, unsigned int columna);
		
		/*PRE: 	Se le pasan dos enteros positivos menores a la cantidad total de filas 
		 *		y la cantidad total de columnas respectivamente.
		 *		El casillero no esta descubierto.
		 *		El casillero tiene bandera.
		 *POST: El casillero pasa a no tener una bandera.
		 */
		void quitarBandera(unsigned int fila, unsigned int columna);		
				
		/*PRE: Se le pasan coordenadas validas de un casillero
		 *POST:Devuelve si ese casillero tiene una mina.
		 */
		bool tieneMina(unsigned int fila, unsigned int columna);
		
		/*POST: Dibuja el tablero en la consola y
		 *		emite una imagen BMP del tablero a guardar en [...]
		 */
		void dibujar();
		
};