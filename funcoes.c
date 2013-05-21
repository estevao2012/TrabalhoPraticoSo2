
int a_esta_fila_vazia(personagem **fila){
    int i;
    for(i=0;i<num_threads;i++)
        if(fila[i] != NULL) return 0;
    return 1;
}

void entra_na_fila(personagem *p){
    fila[p->id] = p;
}

void mostra_fila(){
    int i;
    for(i=1;i<num_threads;i++)
        if(fila[i] != NULL)
            printf("%s Esta na fila \n", fila[i]->nome );
}

void espera_o_forno(personagem *p){
    pthread_mutex_lock(&mutex);
        printf("%s esta esperando o forno\n", p->nome );

        if(p->id == 1 || p->id == 2)
            pthread_cond_wait(&casais[0], &mutex);  
        else if(p->id == 3 || p->id == 4)
            pthread_cond_wait(&casais[1], &mutex);  
        else if(p->id == 5 || p->id == 6)
            pthread_cond_wait(&casais[2], &mutex); 

    pthread_mutex_unlock(&mutex);
}

int posicao_var_condicao(int id){
    int thread_correta = 0;
    thread_correta = id/3;
    if(id==5) thread_correta++;

    return thread_correta;
}

void libera_o_que_sobra(){
    int i,thread_correta;
    while(a_esta_fila_vazia(fila) == 0){
        if(fila[i] != NULL && fila[i] != usando){
            thread_correta = thread_correta = posicao_var_condicao(i);                    
            pthread_cond_signal(&casais[thread_correta]); 
            break;
        }
        i++;
    }
}

int libera(){
    
    int i=1;
    int thread_correta;
    int namorada = 0;

    personagem *homem; 
    
    //Quer dizer que é a namorada
    if(usando->id % 2 == 0) homem = usando->namorado;
    else homem = usando;
    
    
    if(fila[ homem->TemMaiorPrioridade->id ] != NULL || fila[ homem->TemMaiorPrioridade->namorado->id ] != NULL){
        thread_correta = posicao_var_condicao( homem->TemMaiorPrioridade->id  );                    
        pthread_cond_signal(&casais[thread_correta]); 
        return 1;
    }else if( (fila[ homem->id ] != NULL || fila[ homem->namorado->id ] != NULL) ){
            thread_correta = posicao_var_condicao( homem->id );    
            pthread_cond_signal(&casais[thread_correta]); 
            return 1;
    }

    libera_o_que_sobra();

    return 0;

}

void esquenta_comida(personagem *p){
    
    fila_vazia--;

    printf("%s ,ESTA USANDO O FORNO\n",p->nome);  
    sleep(1); 
    printf("%s Finalizo\n",p->nome);

    usando = p;

    fila_vazia++;

    fila[p->id] = NULL;

    libera();          

}

void *usar_forno(void *vargp)
{
    int i;
    personagem *a = (personagem *) vargp; 

    entra_na_fila(a);

    while(a_esta_fila_vazia(fila) == 0){
        
        if(fila_vazia == 1 && fila[a->id] != NULL){
            esquenta_comida(a);
        }
        else if(fila[a->id] != NULL){
            espera_o_forno(a);
        }  
    }
    

    pthread_exit((void *)NULL);
}
