#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include "personagens.h"   

pthread_mutex_t mutex;   
pthread_cond_t casais[3]; 

personagem *fila[7];
personagem *usando;

int fila_vazia = 1;
int num_threads = 7;

void *usar_forno(void *vargp);

int a_esta_fila_vazia(personagem **fila);

#include "funcoes.c"