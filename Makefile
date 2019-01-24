main.o : HSC.c 
	gcc  HSC.c -lm  -g -ggdb3 -lmpfr -lgmp -o main 

all: main.o


run: main.o
	./main
	
clean :
	rm edit main.o main a.out 
	 
