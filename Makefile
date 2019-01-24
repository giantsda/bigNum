main.o : HSC.c 
	gcc  HSC.c -lm  -g -lmpfr -lgmp -o main 

all: main.o


run: main.o
	./main
	
clean :
	rm edit main.o main a.out 
	 
