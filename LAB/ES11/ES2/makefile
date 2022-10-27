link: stackToQueue.o main.o item-int.o list.o stack.o
	gcc stackToQueue.o main.o item-int.o list.o stack.o -o main.exe

main.o:
	gcc -c main.c

item-int.o:
	gcc -c item-int.c

stackToQueue.o:
	gcc -c stackToQueue.c

list.o:
	gcc -c list.c

stack.o:
	gcc -c stack.c

clean:
	rm -f *.o main.exe
