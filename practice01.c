#include <stdio.h>
#include <stdlib.h>

/* 
int main(){
  printf("Hello world!\n");
  return 0;
} 
*/


//TASK-1

void task01(){ //void znači da funkcija ne vraća nikakvu vrednost
  int a;//promenljiva / tipa int (celobrojni tip) / integer
  int b;

  // printf ispisuje poruku na ekran i traži od korisnika unos.
  // \n - novi red
  printf("Unesite prvi broj:\n");

  // scanf("%d", &a) čita celobrojni unos (%d) i smešta ga u promenljivu a.
  // &a znači da šaljemo adresu promenljive da scanf može da upiše vrednost direktno u a.
  scanf("%d", &a);

  printf("Unesite drugi broj:\n");
  scanf("%d", &b);

  //%d je placeholder za celobrojni rezultat.
  printf("Rezultat sabiranja je: %d \n", a+b);
  printf("Rezultata oduzimanja je: %d \n", a-b);
  printf("Rezultat množenja je: %d \n", a*b);
  printf("Rezultat deljenja je: %d \n", a/b);

  printf("Sabiranje: %d \n Oduzimanje: %d \n Množenje: %d \n ", a+b, a-b, a*b);
  
}


//TASK-2

void task02(){
  //Kreiraju se dve promenljive tipa float (brojevi sa decimalama).
  //Primer vrednosti: 3.5, 7.2, -1.0.
  //double - mozemo i ovo da koristimo za brojeve sa decimalama (64 bit)
  //float (32 bit)
  float a;
  float b;

  printf("Unesite prvi broj:\n");
  scanf("%f", &a);
  printf("Unesite drugi broj: \n");
  scanf("%f", &b);

  printf("Zbir: %f \n", a+b);
  printf("Razlika: %f \n", a-b);

}

int main(){
  task02();
  return 0;
}