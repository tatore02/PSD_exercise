link: btree.o main.o item-int.o
	gcc btree.o main.o item-int.o -o main.exe

main.o:
	gcc -c main.c

item-string.o:
	gcc -c item-string.c

item-int.o:
	gcc -c item-int.c

btree.o:
	gcc -c btree.c

clean:
	rm -f *.o main.exe
