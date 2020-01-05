partie1: compile1
	./partie1 sequences_ADN

compile1: sequence.o distance.o main1.o
	gcc sequence.o distance.o main1.o -o partie1

sequence.o: sequence.c sequence.h
	gcc -c -Wall sequence.c

distance.o: distance.c distance.h
	gcc -c -Wall distance.c

main1.o: main1.c 
	gcc -c -Wall main1.c

	
	
partie2: compile2
	./partie2 sequences_ADN

compile2: sequence.o distance.o main2.o famille.o
	gcc sequence.o distance.o main2.o famille.o -o partie2
	
main2.o: main2.c 
		gcc -c -Wall main2.c
	
famille.o: famille.c famille.h
	gcc -c -Wall famille.c 



partie3: compile3
	./partie3 sequences_ADN

compile3: sequence.o distance.o main3.o famille.o alignement.o
	gcc sequence.o distance.o famille.o alignement.o main3.o -o partie3

alignement.o: alignement.c alignement.h
	gcc -c -g -Wall alignement.c 

main3.o: main3.c
	gcc -c -Wall main3.c


clean1:
	rm partie1
	rm *.o
	ls 
clean2: 
	rm -R Reps/
	rm *.o
	rm partie2
	ls 
clean3:
	rm partie3
	rm *.o
	ls 
	
