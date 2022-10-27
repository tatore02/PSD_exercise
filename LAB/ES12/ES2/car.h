#include "list.h"
#include "item.h"

typedef struct car *Car;

Car newCar(char*,int,int,char*);
char *getModello(Car );
int getAnnoProd(Car );
int getAnnoImm(Car );
char *getTarga(Car );
void addCar(List ,Car );
void deleteCar(List ,Item );
Car ricercaCar(List ,Car );
void sortCar(List );
void printCar(List );
