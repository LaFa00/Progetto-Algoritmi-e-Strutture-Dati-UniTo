all: merge_binary_insertion_sort_test merge_binary_insertion_sort_main

merge_binary_insertion_sort_test: test_merge_binary_insertion_sort.o merge_binary_insertion_sort.o unity.o
	gcc test_merge_binary_insertion_sort.o merge_binary_insertion_sort.o unity.o -o merge_binary_insertion_sort_test

merge_binary_insertion_sort_main: main.o merge_binary_insertion_sort.o
	gcc main.o merge_binary_insertion_sort.o -o merge_binary_insertion_sort_main

merge_binary_insertion_sort.o: merge_binary_insertion_sort.c merge_binary_insertion_sort.h
	gcc -c merge_binary_insertion_sort.c

test_merge_binary_insertion_sort.o: test_merge_binary_insertion_sort.c 
	gcc -c test_merge_binary_insertion_sort.c 

unity.o: unity.c unity.h unity_internals.h
		gcc -c unity.c

main.o: main.c
	gcc -c main.c

clean:
	rm -f *.o *.exe