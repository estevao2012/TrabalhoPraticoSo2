#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include "personagens.h"   

pthread_mutex_t mutex;   
pthread_cond_t casais[3]; 

personagem *fila[7];
personagem *usando;

int usando_forno = 1;
int num_threads = 7;
int deadlock = 0;
int vezes_entra_fila = 1;

int vezes_por_casal[3];

void *usar_forno(void *vargp);

void *quebra_o_galho_raj(void *vargp);

int a_esta_fila_vazia(personagem **fila);

void entra_na_fila(personagem *p);

void mostra_fila();

void espera_o_forno(personagem *p);

int get_casal_id(int id);

int libera_o_que_sobra();

void me_recola_na_fila(personagem *p);

int libera();

void esquenta_comida(personagem *p);


#include "monitor.c"