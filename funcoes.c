void *usar_forno(void *vargp)
{
    // Converte a estrutura recebida
    int i=1;
    personagem *a = (personagem *) vargp; 
    
    // monitor *fila;
    
    // // inicializa_monitor(&fila);
    // fila = malloc(sizeof(fila*));
    // fila->tamanho = 0;

    // incluir_personagem(*fila,a);

    // mostra_personagens(*fila);
    
        
    // printf("%s esta esperando o forno\n",a->nome);
    // sleep(3);

    // pthread_mutex_lock(&mutex);
    
    // printf("%s ,Acessa o forno\n",a->nome);

    // sleep(1);

    // pthread_mutex_unlock(&mutex);

    // printf("%s esta comendo\n", a->nome );
    // sleep(3);
        

    pthread_exit((void *)NULL);
}
