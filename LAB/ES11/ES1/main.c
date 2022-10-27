#include <stdio.h>
#define N 7

void mergeIter(int *a,int dim);
void merge(int *a,int *b,int n1,int n2,int *c);
void inputArray(int *a, int dim);
void outputArray(int *a,int dim);
int min(int x,int y);

int main(){
  int x[N];
  puts("Inserire elementi:");
  inputArray(x,N);
  int size = sizeof(x)/sizeof(int);
  mergeIter(x,size);
  puts("Array ordinato:");
  outputArray(x,size);
}


void mergeIter(int *a,int dim){
  int size;
  int start;
  int end;
  int end2;

  for(size=1;size <= dim-1; size*=2){
    for(start=0;start < dim-1; start += size*2){
      end = start + size-1;
      end2 = min(start + 2*size-1, dim-1);
      merge(a+start, a+(end+1), size, end2 - end, a+start);
      //printf("merge di %d-%d e %d-%d\n",start,end,end+1,end2);
    }
  }
}


void merge(int *a,int *b,int n1,int n2,int *c){
  int i, j, k;
  int d[n1+n2];

  for(i=0, j=0, k=0; i<n1 && j<n2; k++){
    if(a[i] < b[j]){
      d[k] = a[i];
      i++;
    }else{
      d[k] = b[j];
      j++;
    }
  }
  for(;i < n1; i++, k++)
    d[k] = a[i];
  for(;j < n2; j++, k++)
    d[k] = b[j];

  for(k=0; k < n1+n2; k++)
    c[k] = d[k];
}

void inputArray(int *a, int dim){
  for(int i=0;i<dim;i++)
    scanf("%d",&a[i]);
}

void outputArray(int *a,int dim){
  for(int i=0;i<dim;i++)
    printf("%d ",a[i]);
  puts("");
}

int min(int x,int y){
  if(x<y)
    return x;
  else
    return y;
}
