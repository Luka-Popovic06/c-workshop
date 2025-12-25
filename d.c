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
/*
3.Fibonačijev broj:
Fibonacijev (Fibonacci) broj je deo Fibonacijevog niza.
Svaki broj je zbir prethodna dva broja.
F0=0 , F1=1, F2= F0 + F1 = 1, F3=2, F4= F2 + F3 = 3, F5 = 5, F6=8 ....
*/
void isFibonacci(){
  printf("Unesi broj:\n");
  int br;
  int br1=1;
  int br2=2;
  int fibonacijev_br=3;

  scanf("%d",&br);
  if(br == 0 || br == 1 || br == 2){
    printf("Broj %d. jeste u Fibonacijevom nizu.\n", br);
    return;
  }
     
  while (fibonacijev_br <= br)
  {
    if(fibonacijev_br == br){
      printf("Broj %d. jeste u Fibonacijevom nizu.\n", br);
      return;
    }
    br1=br2;
    br2=fibonacijev_br;
    fibonacijev_br=br1+br2;
  }
  printf("Broj %d. nije u Fibonacijevom nizu.\n", br);
  
}

/*
4.Napisati program koji od unetog broja N ispisuje broj koji ima cifre kao broj N, samo u obnutom redosledu.
Primetiti da obrnuti broj nema vodecih nula.
N>0
*/
void reverseNumber(){
  int br;
  printf("Unesi broj N:\n");
  scanf("%d",&br);
  int reversedNumber = 0;
  while (br>0)
  {
    if(br==0){
      continue;
      br /= 10;
    }
    reversedNumber=reversedNumber * 10 + (br%10);
    br /= 10;
  }
  printf("Obrnut broj je: %d\n", reversedNumber);
}
/*
5.Napisati program kojim se izbacuje svako pojavijivanje cifre CF-cifra iz datog broja N.
*/

void removeDigit(){
  int br, CF;
  printf("Unesite broj:\n");
  scanf("%d", &br);
  printf("Unesite cifru koju hocete da izbacite:\n");
  scanf("%d", &CF);
  int result=0;
  int stepen=0;
  while (br>0)
  {
    if(br%10 != CF){
      result=result+((br%10)*pow(10,stepen));
      stepen++;
    }
    br/=10;
  }
  printf("Broj sa izbacenom cifrom je: %d", result);
}
int main(){
  removeDigit();
  return 0;
}