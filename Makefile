all: compila_t executa

compila:
	gcc -c -g main.c monitor.h
	gcc monitor.h main.c -o bbtmovw
 
compila_t:
	gcc -c -g main.c monitor.h
	gcc monitor.h main.c -o bbtmovw -lpthread  
 
executa:
	./bbtmovw

valgrind:
	@echo "Executando o valgrind"
	valgrind ./bbtmovw
