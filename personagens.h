#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct personagens{
    int id;
    char *nome;
    struct personagens *TemMaiorPrioridade;
    struct personagens *namorado;
    int qntsVezesUsoOForno;
};
typedef struct personagens personagem;

personagem* inicializa_personagem(int id,char *nome);

void quem_sou_eu(personagem p);

void minha_acao(personagem p,int acao);

void seta_prioridade(personagem *Eu , personagem *Sobre);

void seta_namorado(personagem *homem , personagem *mulher);

#include "personagens.c"