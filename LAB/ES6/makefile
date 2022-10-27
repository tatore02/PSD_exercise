link: main.o item-string.o stack.o list.o
	gcc main.o item-string.o stack.o list.o -o main.exe

main.o:
	gcc -c main.c

item-string.o:
	gcc -c item-string.c

item-int.o:
	gcc -c item-int.c

item-char.o:
	gcc -c item-char.c

stack.o:
	gcc -c stack.c

list.o:
	gcc -c list.c

stack-array.o:
	gcc -c stack-array.c

clean:
	rm -f *.o main.exe
