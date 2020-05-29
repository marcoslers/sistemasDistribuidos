class PaqueteDatagrama{
	private:
		char *datos;
		unsigned int longitud;
		char ip[16];
		int puerto;
	public:
		PaqueteDatagrama(char *, unsigned int, char *, int );
		PaqueteDatagrama(unsigned int);
		~PaqueteDatagrama();
		char *obtieneDireccion();
		unsigned int obtieneLongitud();
		int obtienePuerto();
		char *obtieneDatos();
		void inicializaPuerto(int);
		void inicializaIp(char *);
		void inicializaDatos(char *);
};