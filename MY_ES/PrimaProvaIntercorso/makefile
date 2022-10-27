link: list.o main.o item-string.o
	gcc list.o main.o item-string.o -o main.exe

list.o:
	gcc -c list.c

main.o:
	gcc -c main.c

item-string.o:
	gcc -c item-string.c

clean:
	rm -f *.o main.exe
