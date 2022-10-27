link: main.o playlist.o song.o list.o item-song.o
	gcc main.o playlist.o song.o list.o item-song.o -o main.exe

main.o:
	gcc -c main.c

playlist.o:
	gcc -c playlist.c

song.o:
	gcc -c song.c

list.o:
	gcc -c list.c

item-song.o:
	gcc -c item-song.c

clean:
	rm -f *.o main.exe
