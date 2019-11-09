run: partie1
	./partie1 sequences_ADN

partie1: sequence.o distance.o main1.o
	gcc sequence.o distance.o main1.o -o partie1

sequence.o: sequence.c sequence.h
	gcc -c -Wall sequence.c

distance.o: distance.c distance.h
	gcc -c -Wall distance.c

main1.o: main1.c 
	gcc -c -Wall main1.c

clean:
	rm *.o
	rm partie1