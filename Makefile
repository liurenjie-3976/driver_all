main:a.o b.o
	gcc -o main a.o b.o

b.o:b.c
	gcc -c b.c -o b.o
	
a.o:a.c
	gcc -c a.c -o a.o
clean:
	rm -rf *.o main