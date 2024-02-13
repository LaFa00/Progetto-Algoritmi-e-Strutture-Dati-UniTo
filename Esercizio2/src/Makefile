all: edit_distance_dynamic_main edit_distance_dynamic_test edit_distance_test

edit_distance_dynamic_main: edit_distance_dynamic.o main.o
	gcc edit_distance_dynamic.o main.o -o edit_distance_main

edit_distance_dynamic.o: edit_distance_dynamic.c edit_distance_dynamic.h
	gcc -c edit_distance_dynamic.c 

edit_distance_dynamic_test: edit_distance_dynamic.o edit_distance_dynamic_test.o unity.o
	gcc edit_distance_dynamic.o edit_distance_dynamic_test.o unity.o -o edit_distance_dynamic_test

edit_distance_dynamic_test.o: edit_distance_dynamic_test.c
	gcc -c edit_distance_dynamic_test.c

edit_distance_test: edit_distance.o edit_distance_test.o unity.o
	gcc edit_distance.o edit_distance_test.o unity.o -o edit_distance_test

edit_distance.o: edit_distance.c edit_distance.h
	gcc -c edit_distance.c

edit_distance_test.o:
	gcc -c edit_distance_test.c

unity.o: unity.c unity.h unity_internals.h
	gcc -c unity.c

main.o: main.c 
	gcc -c main.c

clean:
	rm -f *.o *.exe