#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct personagens{
    int id;
    char *nome;
    struct personagens *TenhoPrioridadeSobre;
};
typedef struct personagens personagem;

personagem* inicializa_personagem(int id,char *nome);

void quem_sou_eu(personagem p);

void minha_acao(personagem p,int acao);

void seta_prioridade(personagem *Eu , personagem *Sobre);

#include "personagens.c"