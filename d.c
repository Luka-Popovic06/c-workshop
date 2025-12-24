#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

//Faktorijal broja n (piše se n!) je proizvod svih celih brojeva od 1 do n.
//n!=1⋅2⋅3⋅...⋅n

void calculateAndPrintFactorial(){
  printf("Unesi broj:\n");
  int br;
  int rezultat=1;
  scanf("%d", &br);

  for(int i = 1; i<=br; i++){
    rezultat*=i;
  }
  printf("Faktorijal broja %d je %d", br, rezultat);
}
int main(){
  calculateAndPrintFactorial();
  return 0;
}