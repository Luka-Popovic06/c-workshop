/*
1. (6p) Napisati funkciju pom(int arg) koja proverava da li 
se uneti broj završava sa dve cifre od kojih (u bilo
kom poretku) može da se sastavi dvocifren prost broj. 
Ako ovo svojstvo važi, funkcija vraća taj prost broj,
a ako ne važi, vraća prvi prost broj veći od oba proverena dvocifrena broja. 
Ako su oba broja koja se
mogu sastaviti od poslednjih cifara broja arg prosta, funkcija vraća veći od njih.
 U glavnom programu se
unosi broj n i n brojeva za koje treba ispisati rezultate funkcije pom. 
Ograničenje: uneti brojevi se ne
završavaju sa 00 (tj. može da se sastavi bar jedan dvocifren broj 
od poslednje dve cifre).
Primer: Ulaz: 6 111 132 223 118 240 254
Izlaz: 11 23 23 83 41 59
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int da_li_je_prost_br(int number){
  if(number <= 1)
      return 0;

  for(int i = 2; i * i <= number; i++)
      if(number % i == 0)
         return 0;

  return 1;
}

int pom1(int arg){

  int c1= arg % 10;
  int c2= (arg / 10) % 10;

  int comb1 = c1 * 10 + c2;
  int comb2 = c2 * 10 + c1;

  if(da_li_je_prost_br(comb1) && da_li_je_prost_br(comb2))
        return comb1 > comb2 ? comb1 : comb2;

  if(da_li_je_prost_br(comb1))
         return comb1;
  
  if(da_li_je_prost_br(comb2))
         return comb2;
  int veci = comb1 > comb2 ? comb1 : comb2;

  for(int i = veci; i <= 100000; i++)
      if(da_li_je_prost_br(i))
         return i;

}

void zadatak1(){
  int n;
  printf("Unesite broj n: ");
  scanf("%d", &n);

  for(int i = 1; i <= n; i++){
    int broj;
    printf("Unesite %d. broj ",i );
    scanf("%d", &broj);

    if(broj % 10 == 0 && ((broj / 10) % 10) == 0)
       continue;//prekida petlju i vraca je na pocetak

    printf("%d\n",pom1(broj));
  }

}

//////////////////////////////////////////////////////////////////////////////////////////////

/* 1. (6p) Napisati funkciju pom(int min, int max, int num) koja proverava da li se sve
cifre prosleđenog broja num nalaze u intervalu između min i max (uključujući i
brojeve min i max).
U glavnom programu učitati četiri broja: min, max, low i high; i, uz pomoć funkcije
pom, ispisati koliko ima brojeva u intervalu od low do high čije su sve cifre između
min i max.
Primer: Ulaz: 2 4 10 50
Izlaz: 22 23 24 32 33 34 42 43 44 */

int pom2(int min, int max, int number){
  int provera = 1;

  while(number > 0){
  int cifra = number % 10;

  if(min > cifra || cifra > max){
     provera = 0;
     break;  
  }

  number /= 10;
  }

  return provera;
}

void zadatak2(){
  int min, max, low, high;
  printf("Unesite min i max: ");
  scanf("%d %d", &min ,&max);
  printf("Unesite low i high: ");
  scanf("%d %d", &low, &high);
  for(int i = low; i < high; i++){
    if(pom2(min,max,i))
       printf("%d\n", i);

    continue;
  }

}

///////////////////////////////////////////////////////////////////////////////////////

/*1. (6p) Napisati funkciju int pom(int x, int min, int max) koja vraća broj koji se dobije kad se iz broja x
izbace sve cifre iz intervala min, max.
U glavnom programu učitati dva prirodna broja: a i b (a<=b), i dve cifre: min i max (min<=max). Pomoću
funkcije pom ispisati sve brojeve iz intervala od a do b koji ne sadrže nijednu cifru iz intervala od min do
max. Svi zadati intervali u zadatku uključuju i donju i gornju graničnu vrednost.
Primer: Ulaz: 10 50 3 6
Izlaz: 10 11 12 17 18 19 20 21 22 27 28 29 */

int pom3(int x, int min, int max){

  int number=0;
  int stepen=0;
  
  while(x > 0 ){
    int cifra= x % 10;
    if(cifra < min || max < cifra){
       number = number + cifra * pow(10, stepen);
       stepen++;
    }
    x /= 10;
  }

  return number;

}

void zadatak3(){
  int a, b, min, max;
  printf("Napisite dva prirodna broja: ");
  scanf("%d %d", &a,&b);
  printf("Unesite min i max: ");
  scanf("%d %d", &min,&max);

  if(a > b){
   printf("a mora da bude a <= b\n");
    return;
  }else if(min > max){
    printf("min ne moze da bude vece od max!!!\n");
    return;
  }

  for(int i = a; i <= b; i++){
    if(pom3(i,min,max) >= a && pom3(i,min,max) <= b)
      printf("%d \n", i);

  }

}

////////////////////////////////////////////////////////////////////////////////////////

/*(7p) Definišemo razdvojiv broj kao broj koji se može zapisati kao zbir neka 
dva različita fibonačijeva
broja. Npr. 18=13+5 je razdvojiv, 12 nije razdvojiv. 
Napisati program koji učitava broj n i zatim n prirodnih brojeva i 
izračunava količnik zbira svih unetih razdvojivih brojeva i najmanjeg od svih unetih
nerazdvojivih brojeva. Količnik pri ispisu zaokružiti na 4 decimale.
Primer: Ulaz: 5
18 47 241 111 12
Izlaz: 25.5000
Pojašnjenje: Razdvojivi su: 18=13+5, 47=34+13 i 241 = 233+8. 
Najmanji nerazdvojiv je 12, količnik je
(18+47+241)/12 = 306/12 = 25.5000. */

//FIBONAČIJEV NIZ:
//F0=0 , F1=1, F2= F0 + F1 = 1, F3=2, F4= F2 + F3 = 3, F5 = 5, F6=8 ....
//Fn= Fn - 1 + Fn - 2
//n = 34
//broj = j + (broj - j)
//uzme se jedan komad i pitam se kolko broju fali da stigne do tog nekog broja

int fibonacijev4(int n){
  if(n == 0 || n == 1)
     return 1;

  int fi = 0;
  int fj = 1;

  while (fi + fj < n)
  {
    int tmp=fi;
    fi = fj;
    fj= tmp + fi;
  }
  if(fi + fj == n)
     return 1;

  return 0;
}

void zadatak4(){
  int n;
  printf("Unesite broj n: ");
  scanf("%d", &n);

  int suma_razdvojivih = 0;
  int min_nerazdvojivih = 1000000;

  for(int i = 1; i <= n; i++){
    int br;
    printf("Unesite %d. broj: ", i);
    scanf("%d", &br);

    int razdvojiv = 0;

    for(int j = 0; j <= br; j++){
      if(fibonacijev4(j) && fibonacijev4(br - j) && j != br - j ){
        suma_razdvojivih += br;
        razdvojiv = 1;
        break;
      }
    }
    if(!razdvojiv){
      if(br < min_nerazdvojivih){
        min_nerazdvojivih = br;
      }
    }
  }
  double količnik = 0;
  količnik = suma_razdvojivih * 1.0 / min_nerazdvojivih;
  printf("Rezultat je %.4f", količnik);
}

