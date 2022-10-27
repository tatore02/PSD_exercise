link: main.o item-int.o list.o queue-list.o
	gcc main.o item-int.o list.o queue-list.o -o main.exe

main.o:
	gcc -c main.c

item-int.o:
	gcc -c item-int.c

list.o:
	gcc -c list.c
	
queue-list.o:
	gcc -c queue-list.c

clean:
	rm -f *.o main.exe
