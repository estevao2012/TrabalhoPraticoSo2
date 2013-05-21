personagem *inicializa_personagem(int id,char *nome){
  personagem *p;
  p = malloc(sizeof(personagem));
  p->id = id;
  p->nome = (char*) nome;
  return p;
}

void quem_sou_eu(personagem p){
  printf("Ola eu sou o %s.Meu id eh %i\n", p.nome,p.id);
}

void minha_acao(personagem p,int acao){
  switch (acao){
        case 0:
            printf("%s esta esperando o forno\n", p.nome );
            break;
        case 1:
            printf("%s esta usando o forno\n", p.nome );
            break;
        case 2:
            printf("%s esta comendo\n", p.nome );
            break;
        default:
            printf("%s nao esta fazendo nada!\n", p.nome );
            break;
    }
}

void seta_prioridade(personagem *Eu , personagem *Sobre){
  Sobre->TemMaiorPrioridade = Eu;
}

void seta_namorado(personagem *homem , personagem *mulher){
  homem->namorado = mulher;
  mulher->namorado = homem;
}