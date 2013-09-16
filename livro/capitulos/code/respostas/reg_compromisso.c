typedef struct {
	short ano;
	short mes;
	short dia;
	short hora;
	short minuto;
} Horario;

typedef struct {
	int codigo;
	char titulo[100];
	char local[100];
	char detalhes[255];
	Horario horario;
} Compromisso;

