link: list.o main.o item-int.o
	gcc list.o main.o item-int.o -o list.exe

link-str : list.o main.o item-str.o
	gcc list.o main.o item-str.o -o list.exe

list.o:
	gcc -c list.c

main.o:
	gcc -c main.c

item-int.o :
	gcc -c item-int.c

item-str.o :
	gcc -c item-str.c

clean:
	rm -f list.o main.o item-int.o item-str.o list.exe
