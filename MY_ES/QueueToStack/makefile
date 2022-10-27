link: queueToStack.o main.o item-int.o list.o queue.o
	gcc queueToStack.o main.o item-int.o list.o queue.o -o main.exe

main.o:
	gcc -c main.c

item-int.o:
	gcc -c item-int.c

queueToStack.o:
	gcc -c queueToStack.c

list.o:
	gcc -c list.c

queue.o:
	gcc -c queue.c

clean:
	rm -f *.o main.exe
