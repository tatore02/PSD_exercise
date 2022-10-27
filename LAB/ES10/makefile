link: btree.o main.o item-int.o list.o stack.o
	gcc btree.o main.o item-int.o list.o stack.o -o main.exe

main.o:
	gcc -c main.c

item-string.o:
	gcc -c item-string.c

item-int.o:
	gcc -c item-int.c

btree.o:
	gcc -c btree.c

list.o:
	gcc -c list.c

stack.o:
	gcc -c stack.c

clean:
	rm -f *.o main.exe
