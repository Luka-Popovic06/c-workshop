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

#define MAX_N 50

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

  return 0;
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

//////////////////////////////////////////////////////////////////////////////////////////

/*
3. (7p) Uvodimo aritmetičku operaciju sabiranja bez pamćenja na sledeći način: za
dva broja sabiraju se njihove jedinice, njihove desetice, njihove stotine itd. i rezultat
se gradi tako što se poslednje cifre tih rezultata poređaju jedna do druge u istom
redosledu u kom su bile i u originalnim brojevima. Npr: sabiranje bez pamćenja za
brojeve 356 i 9948 treba da da rezultat 9294 (cifre jedinica: 6+8=14, dakle cifra
jedinica rezultata je 4; cifre desetica: 5+4=9, dakle cifra desetica rezultata je 9;
cifre stotina: 3+9=12, dakle cifra stotina rezultata je 2; cifre hiljada 0+9=9, dakle
cifra hiljada rezultata je 9)
Napisati program u kome se unose brojevi sve dok se ne unese 0. Uzimamo da je
početni rezultat 0. Svaki put kada se unese novi broj, potrebno je prethodni rezultat
sabrati bez pamćenja sa novim brojem i ispisati rezultat nakon sabiranja. Rezultat
nakon sabiranja se kao takav "odvodi" u sledeću iteraciju. Uzeti da korisnik unosi
isključivo prirodne brojeve.
Primer: Ulaz: 675 676 798 65
Izlaz: 675 241 939 994
*/

int sabiranje_bez_pamcenja(int br1, int br2){
  int rezultat=0;
  int br_cifre=0;
  int stepen=0;
  int veci_broj=br1 > br2 ? br1 : br2;

  while (veci_broj > 0)
  {
    br_cifre++;
    veci_broj /=10;
  }

  for(int i = 0; i <= br_cifre; i++){
    int cifra1 = br1 % 10;
    int cifra2 = br2 % 10;
    int suma_dve_cifre = cifra1 + cifra2;
    rezultat = rezultat + (suma_dve_cifre % 10) * pow(10,stepen);

    stepen++;
    br1 /= 10;
    br2 /= 10;
  }

  return rezultat;
}

void zadatak5(){
  int br;
  int rezultat=0;
  int kopija = 0;
  for (int i = 1; i != 0; i++)
  {
    printf("Unesite %d. broj", i);
    scanf("%d", &br);
    if(br == 0) break;
    //if(kopija != br)
     rezultat=sabiranje_bez_pamcenja(rezultat,br);
  }

  printf("%d", rezultat);
  
}
///////////////////////////////////////////////////////////////////////////////////////
/*,
Array
Nizovi:

int a[n] = {1, 2, 3, 4, 5, 0, 0, 0, 0, 0}

=> int a[5]; - on fiksira 5 lokacija i ne moze da se siri
=> a = {1, 2, 3, 4, 5};

- Da smo stavili n=10, askoristili smo samo 5 polja on bi sotatak prostora popunio
sa nulama

- Svi elementi imaju svoj neki index pomocu koga ja pristupam toj vrednosti
- index pocinje od 0 a zavrsava se na n - 1 index
- a[2] ===> 3
*/

/*
1.Napisati program koji učitava niz celih brojeva "a", dužine "n", 
a zatim ispisuje njegove elemente.
*/
void readArrayFromInput(){
  int n;
  printf("Unesite duzinu niza:\n");
  scanf("%d", &n);

  int a[n];//deklarisanje niza

  for(int i = 0; i < n; i++){
    printf("Unesite %d. vrednost niza\n", i);
    scanf("%d", &a[i]);
  }

  printf("Niz se sastoji od elemenata:\n");

  for(int j=0; j<n; j++){
    printf("%d ", a[j]);
  }
}

/*
2.Napisati program koji učitava niz celih brojeva "a", dužine "n", 
unete brojeve deljive sa 3 stavlja u jedan niz, brojeve deljive sa 5 
u drugi niz, a sve ostale brojeve u treći niz.
*/
//////
//kad se prosledjuje int n, to je ustvari kopija elementa;
//dok kad se prosledjuje niz int a[], to nije kopija niza nego je to orginal

void inputArray(int a[], int n){
  for(int i = 0; i < n; i++){
    printf("Unesite %d. vrednost niza\n", i);
    scanf("%d", &a[i]);
  }
}

void outputArray(int a[], int n){
  for(int j = 0; j < n; j++){
    printf("%d ", a[j]);
  }
}
/////

void zad2(){
  int n;
  printf("Unesite duzinu niza:\n");
  scanf("%d", &n);
  // n ==> treba de se deklarise pre niza a[]

  int a[n], b[MAX_N],c[MAX_N],d[MAX_N];
  int counter_b=0,counter_c=0,counter_d=0;
  
  inputArray(a, n);

  for(int i = 0; i<n; i++){
    if(a[i] % 3 == 0){
      b[counter_b]=a[i];
      counter_b++;
    }else if(a[i] % 5 == 0){
      c[counter_c]=a[i];
      counter_c++;
    }else{
      d[counter_d]=a[i];
      counter_d++;
    }
  }

  outputArray(b, counter_b);
  printf("\n");
  outputArray(c, counter_c);
  printf("\n");
  outputArray(d, counter_d);
}

/*
3.Napisati program koji učitava niz celih brojeva "a", dužine "n", 
a zatim niz unetih brojeva sortira u neopadajućem poretku.

[1, 2, 3, 4, 5] ===> rastuci poredak
[1, 2, 3, 4, 4, 4, 5, 5, 6, 7] ===> neopadajuci poredak
                            (kao rastuci samo ima stagnacija)

                         *Bubble Sort*  

 - Ideja je da se veći elementi “dižu” ka kraju niza, kao mehurići u vodi – otuda naziv bubble. 
[3, 5, 4, 1, 2]          
*/


void bubble_sort(int a[], int n){
  for(int i = 0; i < n; i++){//prolazi kroz elemente niza
    for(int j = 0; j < (n - i - 1); j++){ //poredi elemente niza
      if(a[j] > a[j + 1]){// da bi mogli da vidima element koji je ispred dodajemo 1
        int tmp = a[j];   //zbog ovog dodavanja keca smo oduzeli  jedan gore u uslovu
        a[j] = a[j + 1];
        a[j + 1] = tmp;
      }
    }
  }

}

void zad3(){
  int n;
  printf("Unesite duzinu niza:\n");
  scanf("%d", &n);
  int a[n];

  inputArray(a, n);

  bubble_sort(a, n);

  outputArray(a, n);
}

/*
4.Napisati program koji učitava niz celih brojeva "a", dužine "n", 
a zatim pronalazi element koji se najviše puta pojavljuje u učitanom nizu. 
Ispisati taj element i broj pojavljivanja tog elementa.
*/
void inputArray2(int a[], int n){
  for(int i = 0; i < n; i++){
    printf("Unesite %d. vrednost niza:\n", i);
    scanf("%d", &a[i]);
  }
}
void outputArray2(int a[], int n){
  for (int i = 0; i < n; i++)
  {
    printf("[");
    printf("%d", a[i]);
    if(i != (n - 1))
      printf(",");
    if(i == (n - 1))
     printf("]");
  }
}

void zad4(){
  int n;
  printf("Unesite duzinu niza:\n");
  scanf("%d", &n);
  int a[n];

  int max_number=0;
  int max_repetition = 0;
  int repetition = 0;
  
  inputArray2(a, n);

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if(a[i] == a[j])
        repetition++;
    }
    if(max_repetition < repetition){
      max_repetition = repetition;
      max_number = a[i];
    }
   repetition = 0;
  }
  printf("Num: %d Repetition: %d", max_number, max_repetition);
}
////////////////////////////////////////////////////////////////////////////////////
/*
,
Rekurzija:
Rekurzija je pojam u programiranju koji znači da funkcija poziva samu sebe da bi 
rešila neki problem, ali svaki put sa manjim / jednostavnijim delom problema.
n ---> podeliti problem na manje, jednostavnije delove
Babuška

4! = 4 * 3! ===> 4 * 6 = 24           4! = 24
3! = 3 * 2! ===> 3 * 2 = 6
2! = 2 * 1! ===> 2 * 1 = 2
1! = 1 --> u osnovnom slucaju, odmah znamo odgovor (kad nadjemo ovo onda od ovog prosledjujemo rezultat prema gore)
*/

/*
5.Napisati program koji učitava prirodan broj n i funkciju koja rekurzivno 
izračunava n-ti član Fibonačijevog niza brojêva.
*/
int fib(int n){
  
  if( n == 0)
   return 0;

  if( n == 1)
   return 1;

   return fib(n - 1) + fib(n - 2);
}
/*
6.Napisati program koji učitava prirodan broj n i funkciju koja rekurzivno 
izračunava sumu prvih n prirodnih brojeva.
==> Prvi prirodan broj je 1
n
n = 1
*/
int zad5(int n){
  if (n == 1)
   return 1;

  return n * zad5(n - 1);
}
/*
7.Napisati program koji učitava dva prirodna broja, n i s, i izračunava vrednost n^s. 
Rešenje zadatka realizovati pomoću rekurzivne funkcije za izračunavanje odredenog stepena 
datog broja.
*/
int zad6(int n, int s){
  if(s == 0)
   return 1;

  return n * zad6(n, (s - 1));
}
/*
8.Napisati program koji učitava prirodan broj n i pomoću rekurzivne funkcije izračunava zbir
njegovih cifara.
*/
int zad7(int n){
  if(n < 10)
  return n;

  return zad7(n % 10) + zad7(n / 10);
  
}

//9.
//rekurzija
//Funkcija poziva samu sebe dok ne dođe do osnovnog slučaja (base case).
double f1(int n){
  if(n == 1)
   return 1;

  return n + 1.0 / f1(n - 1);
}
//iterativno resenje
//Problem se rešava pomoću petlji (for, while).
double f1_i(int n){
  double s = 1;
  for (int i = 2; i <= n; i++)
    s= i + 1.0 / s;
  return s;
}
int main(){
  printf("%lf\n %lf\n", f1(6), f1_i(6) );
  return 0;
}