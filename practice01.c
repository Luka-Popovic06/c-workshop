#include <stdio.h>
#include <stdlib.h>
//ova biblioteka mi treba za sve naprednije matematičke operacije pr. Koren
#include <math.h>
//ovo nam treba za vreme
#include <time.h>

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

  //sqrt(promenljiva)-za koren od broja
  //sqrt vraća tip double, čak i ako je a tipa float ili int.
  printf("Koren: %f \n", sqrt(a));

}


//Task-3
void task03(){

  //char- se stavlja za caracter(karakter) npr. Slovo-(%c)
  //Karakter možemo izraziti kao karakter(%c) ili kao broj(%d)
  char a;

  printf("Unesite slovo: \n");
  scanf("%c", &a);

  printf("ASCII vrednost unetog karakter %c je: %d \n", a, a);
}

//Task-4
void task04(){
  char veliko_slovo;

  printf("Unesite veliko slovo: \n");
  scanf("%c", &veliko_slovo);

  if(veliko_slovo >= 'A' && veliko_slovo <= 'Z'){

    char malo_slovo=veliko_slovo+('a' - 'A');
    
    printf("Odgovarajuće malo slovo je: %c \n",malo_slovo);

  }else{
    printf("Niste uneli malo slovo \n");
  }
}


//TASK-5
void task05(){

  //`time_t t;` – pravi promenljivu u kojoj će biti vreme (broj sekundi od 1.1.1970.)
  //time(&t)-ovako pristupamo toj promenljivoj(tom vremenu)
  time_t t;
  //`srand(time(&t));` – postavlja *seed* za generator slučajnih brojeva.
  srand(time(&t));
  //Ovo znači: **svaki put kad pokreneš program, `rand()` će davati druge brojeve**.  
  //Da nema ovoga, svako pokretanje bi imalo iste rezultate.

  int k1, k2, k3;

  k1=rand()%6+1;
  k2=rand()%12+1;
  k3=rand()%20+1;

  printf("Rezultat prvog bacanja: %d, %d, %d \n", k1, k2, k3);

  k1=rand()%6;//daje: 0 1 2 3 4 5
  // ++k1;- ovo prvo povecava, pa ispise broj
  k1++;//pomera na 1-6
  k2=rand()%12;
  k2++;
  k3=rand()%20;
  k3++;

  printf("Rezultat drugog bacanja: %d, %d, %d \n", k1, k2, k3);

  //pow(n,s)=> se koristi da se digne neki broj na odredjeni stepen
  //n-broj koji dižemo
  //s-stepen
  int d=pow(2,3);
  printf("Dva na treci stepen je: %d \n", d);

}


//TASK-6
void task06(){

  int a,q,k;
  int suma=0;
  int clan;

  printf("Unesite a: \n");
  scanf("%d", &a);
  printf("Unesite q: \n");
  scanf("%d",&q);
  printf("Unesite k: \n");
  scanf("%d",&k);

  for(int i=0;i<k;i++){
    clan=a*pow(q,i);
    suma+=clan;
  }

  printf("Suma prvih k članova je: %d, a K-ti član je: %d \n", suma,clan);

}

//Task-7
void task07() {
    int total;
    printf("Unesite broj sekundi:\n");
    scanf("%d", &total);

    int sekundi = total % 60;//sekunde % 60 → koliko ostane sekundi kada izbacimo minute
    int minuti = (total / 60) % 60;//minuti % 60 → koliko ostane minuta kada izbacimo sate
    int sati = total / 3600;

    printf("Sati:\t%d\nMinuti:\t%d\nSekunde:\t%d\n",
           sati, minuti, sekundi);
}
void task08() {
    time_t t;
    srand(time(&t));
    int max,min;
    printf("Unesite broj od koga počinje interval:\n");
    scanf("%d", &min);
    printf("Unesite broj do koga ide interval:\n");
    scanf("%d",&max);
    int random_number = rand() % (max - min + 1) + min;
    printf("Random broj od %d do %d je: %d\n",min,max, random_number);
}


int main(){
  task08();
  return 0;
}