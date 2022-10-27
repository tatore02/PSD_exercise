link: main.o libro.o item-libro.o list.o biblioteca.o
	gcc main.o libro.o item-libro.o list.o biblioteca.o -o main.exe

main.o:
	gcc -c main.c

libro.o:
	gcc -c libro.c

item-libro.o:
	gcc -c item-libro.c

list.o:
	gcc -c list.c

biblioteca.o:
	gcc -c biblioteca.c

clean:
	rm -f *.o main.exe
