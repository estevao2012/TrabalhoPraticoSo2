#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct personagens
{
    int id;
    char *nome;
    int prioridade;
} personagem;

personagem* inicializa_personagem(int id,char *nome);

void quem_sou_eu(personagem p);

void minha_acao(personagem p,int acao);

void seta_prioridade(personagem *p , int prioridade);

#include "personagens.c"