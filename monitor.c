void inicializa_monitor(monitor *fila){
	fila = malloc(sizeof(monitor*));
    fila->tamanho = 0;
}

void incluir_personagem(monitor *fila,personagem *p){
	fila->personagem[fila->tamanho] = p;
	fila->tamanho++;
}

void mostra_ultimo(monitor *fila){
	personagem *p = fila->personagem[fila->tamanho-1];
	printf("%s\n", p->nome);
}


void mostra_personagens(monitor *fila){
	personagem *p;
	
	int i; 
	for(i=0;i<fila->tamanho;i++){
		p = fila->personagem[i];
		printf("%s\n", p->nome ); 
	} 
	// mostra_ultimo(fila);
}