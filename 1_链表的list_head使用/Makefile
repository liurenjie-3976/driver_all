main:main.o link_list.o
	gcc -o main main.o link_list.o
main.o:main.c
	gcc -c main.c -o main.o
linklist.o:link_list.c
	gcc -c link_list.c -o link_list.o

clean:
	rm -rf *.o main