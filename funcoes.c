void *usar_forno(void *vargp)
{
    // Converte a estrutura recebida
     

    personagem *a = (personagem *) vargp; 

    incluir_personagem(fila,a);

    mostra_personagens(fila);
    // sleep(3);        
    printf("%s esta esperando o forno\n",a->nome);

    pthread_mutex_lock(&mutex);
    
    sleep(1);
    printf("%s ,Acessa o forno\n",a->nome);

    pthread_mutex_unlock(&mutex);

    // sleep(3);
    printf("%s esta comendo\n", a->nome );
   

    pthread_exit((void *)NULL);
}
