#include <stdio.h>
#include <string.h>

int quante_parole(char **vett,int);
char **quali_parole(int n);

int main(){
  FILE *fp = fopen("text.txt","r");
  char vett[100][20];
  char buffer[20];
  int i=0;
  while(fscanf(fp,"%s",buffer) != EOF){
    strcpy(vett[i],buffer);
    i++;
  }

  int n = 4;
  int count = 0;
  printf("Parole con %d caratteri:\n",n);
  for(int j=0;j<=i;j++){
    if(strlen(vett[j]) == n){
      puts(vett[j]);
      count++;
    }
  }
  printf("\n%d\n",count);
}
