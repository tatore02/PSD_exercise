link-1: list.o main1.o item-int.o
	gcc list.o main1.o item-int.o -o list.exe

link-2: list.o main2.o item-int.o
	gcc list.o main2.o item-int.o -o list.exe

link-3: list.o main3.o item-int.o
	gcc list.o main3.o item-int.o -o list.exe

link-4: list.o main4.o item-int.o
	gcc list.o main4.o item-int.o -o list.exe

list.o:
	gcc -c list.c

main1.o:
	gcc -c main1.c

main2.o:
	gcc -c main2.c

main3.o:
	gcc -c main3.c

main4.o:
	gcc -c main4.c

item-int.o :
	gcc -c item-int.c

item-str.o :
	gcc -c item-str.c

clean:
	rm -f *.o list.exe
