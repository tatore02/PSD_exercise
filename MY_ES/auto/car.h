#include "item.h"

typedef struct car *Car;

Car createCar(char *,char *,int);
char* getModello(Car);
char* getTarga(Car);
int getAnno(Car);
