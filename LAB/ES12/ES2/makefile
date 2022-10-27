link: car.o main.o item-car.o list.o
	gcc car.o main.o item-car.o list.o -o main.exe

main.o:
	gcc -c main.c

item-car.o:
	gcc -c item-car.c

car.o:
	gcc -c car.c

list.o:
	gcc -c list.c

clean:
	rm -f *.o main.exe
