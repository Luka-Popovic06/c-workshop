#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


// 1.
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

/*
2.Ispitujemo da li je neki broj prost
Prost broj je broj veći od 1 koji ima tačno dva delitelja: 1 i sebe samog.
*/

void isPrime(){
  printf("Unesi broj:\n");
  int br;
  scanf("%d",&br);
  if(br==1){
      printf("Broj je prost");
      return;
  }else if(br < 1){
    printf("Broj nije prost");
      return;
  }
  
  for(int i=2; i < br; i++){
    if(br % i == 0)
    {
      printf("Broj %d. nije prost\n", br);
      return;
    }
  }
  printf("Broj %d. je prost broj\n", br);
  
}
