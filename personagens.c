personagem *inicializa_personagem(int id,char *nome){
  personagem *p;
  p = malloc(sizeof(personagem));
  p->id = id;
  p->nome = (char*) nome;
  p->qntsVezesUsoOForno = 1;
  return p;
}

void seta_prioridade(personagem *Eu , personagem *Sobre){
  Sobre->TemMaiorPrioridade = Eu;
}

void seta_namorado(personagem *homem , personagem *mulher){
  homem->namorado = mulher;
  mulher->namorado = homem;
}