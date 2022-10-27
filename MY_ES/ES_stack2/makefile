link: list.o main.o item-string.o stack.o
	gcc list.o main.o item-string.o stack.o -o main.exe

main.o:
	gcc -c main.c

item-int.o:
	gcc -c item-int.c

item-string.o:
	gcc -c item-string.c

list.o:
	gcc -c list.c

stack.o:
	gcc -c stack.c

clean:
	rm -f *.o main.exe
