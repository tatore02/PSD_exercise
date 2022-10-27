link : main.o funzioni.o
	gcc main.o funzioni.o -o main.exe

driver_somma : driver_somma.o funzioni.o
	gcc driver_somma.o funzioni.o -o driver_somma.exe

driver_sumVec : driver_sumVec.o funzioni.o
	gcc driver_sumVec.o funzioni.o -o driver_sumVec.exe

driver_scalare : driver_scalare.o funzioni.o
	gcc driver_scalare.o funzioni.o -o driver_scalare.exe

driver_somma.o :
	gcc -c driver_somma.c

driver_sumVec.o :
	gcc -c driver_sumVec.c

driver_scalare.o :
	gcc -c driver_scalare.c

main.o :
	gcc -c main.c

funzioni.o :
	gcc -c funzioni.c

clean :
	rm -f driver_somma.o driver_sumVec.o driver_scalare.o main.o funzioni.o main.exe driver_somma.exe driver_sumVec.exe driver_scalare.exe
