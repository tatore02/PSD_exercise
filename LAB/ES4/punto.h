typedef struct punto *Punto;

Punto creapunto(float x, float y);
float ascissa(Punto p);
float ordinata(Punto p);
float distanza(Punto p1, Punto p2);
void stampaCoordinata(Punto p);
void spostamento(Punto p,float x, float y);
Punto centroide(Punto vettore[], int dim);
int distCoppie(Punto vettore[],int dim, float distanza);
float distMax(Punto vettore[], int dim);
