link: list.o main.o item-int.o stack.o
	gcc list.o main.o item-int.o stack.o -o main.exe

main.o:
	gcc -c main.c

item-str.o:
	gcc -c item-str.c

list.o:
	gcc -c list.c

stack.o:
	gcc -c stack.c

clean:
	rm -f *.o main.exe
