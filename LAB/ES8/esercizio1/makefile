link: main.o item-int.o array.o utils.o
	gcc main.o item-int.o array.o utils.o -o main.exe

main.o:
	gcc -c main.c

item-string.o:
	gcc -c item-string.c

item-int.o:
	gcc -c item-int.c

array.o:
	gcc -c array.c

utils.o:
	gcc -c utils.c

clean:
	rm -f *.o main.exe
