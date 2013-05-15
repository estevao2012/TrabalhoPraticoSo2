all: compila_t executa

compila:
	gcc -c -g main.c funcoes.h monitor.h
	gcc monitor.h funcoes.h main.c -o bbtmovw
 
compila_t:
	gcc -c -g main.c funcoes.h
	gcc funcoes.h main.c -o bbtmovw -lpthread  
 
executa:
	./bbtmovw

valgrind:
	@echo "Executando o valgrind"
	valgrind ./bbtmovw
