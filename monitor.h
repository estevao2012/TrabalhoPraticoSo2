#include <stdlib.h>
#include <stdio.h> 

typedef struct monitor
{
	int tamanho;
	personagem *personagem[10];
}monitor;

void inicializa_monitor(monitor *fila);

void incluir_personagem(monitor *fila,personagem *p);

void mostra_ultimo(monitor *fila);

void mostra_personagens(monitor *fila);

#include "monitor.c"