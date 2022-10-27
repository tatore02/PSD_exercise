link: list.o main.o item-car.o car.o
	gcc list.o main.o item-car.o car.o -o main.exe

list.o:
	gcc -c list.c

main.o:
	gcc -c main.c

car.o:
	gcc -c car.c

item-car.o :
	gcc -c item-car.c

clean:
	rm -f *.o main.exe
