link: heap.o main.o item-int.o
	gcc heap.o main.o item-int.o -o main.exe

main.o:
	gcc -c main.c

item-string.o:
	gcc -c item-string.c

item-int.o:
	gcc -c item-int.c

heap.o:
	gcc -c heap.c

clean:
	rm -f *.o main.exe
