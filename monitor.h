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


//Função usada para entrar no monitor do forno
void *usar_forno(void *vargp);
//Função de vigilancia do raj , valida casos de deadlocks
void *quebra_o_galho_raj(void *vargp);
//Função que verifica se a fila implementada está vazia
int a_esta_fila_vazia();
//Coloca o personagem p na posição da fila que refere ao seu ID
void entra_na_fila(personagem *p);
//Função que coloca o personagem na espera do forno
void espera_o_forno(personagem *p);
//Retorna o id do casal pelo id do personagem
int get_casal_id(int id);
//função que libera algum personagem menos o de casal id
int libera_o_que_sobrou(int menos_casal_id);
//recoloca o personagem na fila
void me_recola_na_fila(personagem *p);
//Libera o proximo usuario a utilizar o forno
int libera(personagem *atual);
//Realiza o uso do forno
void esquenta_comida(personagem *p);


#include "monitor.c"