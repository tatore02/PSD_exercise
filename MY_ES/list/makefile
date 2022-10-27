link: list.o main.o item-int.o
	gcc list.o main.o item-int.o -o main.exe

main.o:
	gcc -c main.c

item-int.o:
	gcc -c item-int.c

list.o:
	gcc -c list.c

clean:
	rm -f *.o main.exe
