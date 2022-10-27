link: list.o main.o item-song.o playlist.o song.o
	gcc list.o main.o item-song.o playlist.o song.o -o playlist.exe

list.o:
	gcc -c list.c

main.o:
	gcc -c main.c

item-song.o :
	gcc -c item-song.c

playlist.o :
	gcc -c playlist.c

song.o :
	gcc -c song.c

clean:
	rm -f list.o main.o item-song.o playlist.o song.o playlist.exe
