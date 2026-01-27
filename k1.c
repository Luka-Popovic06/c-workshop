#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/*
Random funkcija:
1.Napisati program koji simulira bacanje šestostrane, dvanaestostrane i 
dvadesetostrane "kockice" (poliedra).
1 - je prvi prirodan broj
*/
void task01(){
  time_t t;
  srand(time(&t));

  int kocka_1 = rand() % 6 + 1; // X % n = {0, ... , n - 1}
  int kocka_2 = rand() % 12 + 1;
  int kocka_3 = rand() % 20 + 1;

  printf("%d %d %d \n", kocka_1, kocka_2, kocka_3);

}

/*
2025/26
k1 - grupa 5
2.
*/
double g_sredina(int x){
  int n = 0;//brojač cifara
  double proizvod = 1.0;

  while (x > 0)
  {
    proizvod *= x % 10;
    n++;
    x /= 10;
  }

  return pow(proizvod, 1.0 / n);//1.0/n pravi realan stepen
  //(koren na n)√ a1 · · · · · an.
  //koren na nesto je ustvari (br / 1.0), i sa ovim kvadrirano
  // treći koren od 7 je: pow(7, 1.0 / 3);
}
/*
2025/26
k1 - grupa 1
3.
//Kongumerentnost:
dva broja(a, b) su kongumerenta po modulu m ako daju isti ostatak pri deljenju sa m:
(i = isto)
a % m = i
b % m = i

//Simetricnost:
dva broja su simetricna ako:
a % m == b % m ===> i     <==>   b % m == a % m ===> i

//unose se m, min i max
proveravamo simetricnost svih br u intervalu [min, max]
min = 5 [5,6] [5,7] [5,8] [5,9] 


*/

int kongumerentnost(int br1, int br2, int m){
  int res = 0;
  if(br1 % m == br2 % m)
   res = 1;

  return res;
}
int simetricnost(int br1, int br2, int m){
  int res = 1;
  if(kongumerentnost(br1,br2,m) && !kongumerentnost(br2,br1,m))// ako jedno jeste a drugo nije vrati 0
  //ako A == 1 i B == 0 ====> res = 0;
    res = 0;
    
  return res;
}
void zad03(){
  int m,min,max;
  printf("Unesite broj m:\n");
  scanf("%d", &m);
  printf("Unesite min i max:\n");
  scanf("%d %d", &min, &max);
  int resenje = 1;
  for (int i = min; i <= max; i++)
  {
    for (int j = i; j <= max; j++)
    {
      if(simetricnost(i,j,m) == 0){
       resenje = 0;
      }
    }
    
  }
  if(resenje == 1)
   printf("Relacija kongruentnosti po modulu %d je simetricna na skupu [%d, %d]\n", m,min,max);
  else
  printf("Relacija kongruentnosti po modulu %d je NIJE simetricna na skupu [%d, %d]\n", m,min,max);

}
/*
25/26
k1 g-2
4.

Pretvori 32 u bazu 3:

32 ÷ 3 = 10 ostatak 2
10 ÷ 3 = 3 ostatak 1
3 ÷ 3 = 1 ostatak 0
1 ÷ 3 = 0 ostatak 1

Ostatke čitamo od dole prema gore → 1012 (baza 3)

Obrnemo cifre: 1012 → 2101

Vratimo u decimalni sistem:

2×3³ + 1×3² + 0×3¹ + 1×3⁰

2×27 + 1×9 + 0×3 + 1×1 = 64
1.Uzimam cifre od 2 do 9 iz broja
ako je cifra 1 ili 0 vratim 0
za svaku cif koja nije 0 ili 1 uzmimam da je osnova i radim 
*/
//Ovde pretvaram taj broj u bazu i potom ga obrcem
int pretvaranje_broja_u_bazu(int N, int baza){
  int rezultat = 0;
  while (N > 0)
  {
    rezultat = rezultat * 10 + (N % baza);
    N/= baza;
  }
  return rezultat;
}
int vracanje_broja_u_decimalni_sistem(int N, int baza){
  int stepen = 0;
  int br = pretvaranje_broja_u_bazu(N,baza);
  int rezultat = 0;

  while (br > 0)
  {
    rezultat += (br % 10) * pow(baza,stepen);
    stepen++;
    br/=10; 
  }
  return rezultat;
}
void zad04(){
  int N;
  printf("Unesite broj N:\n");
  scanf("%d", &N);
  int N_copy = N;//NESMEM DA DEKLARISEM PROMENLJIVU PRE NEGO STO DODAM VREDNOST U GLAVNU PROMENLJIVU
  while (N > 0)
  {
    int cifra = N % 10;
    if(cifra == 0 || cifra == 1){
      printf("%d ", 0);
    }else{
      printf("%d ", vracanje_broja_u_decimalni_sistem(N_copy,cifra));
    }
    N/=10;
  }
  
}
/*
25/26
k1 g-3
5.
// f-ja pom(x, min, max)
f-ja ispituje da li se:
1. barem jedna cifra od x nalazi u intervalu od min do max(min <= x <= max)
2. barem jedna cifra od x nalazi van intervala od min do max
==> AKO VAZE OBA USLOVA VRACA 1 
==> A AKO NE VAZE VRACA 0

Glavna Logika:
1.Ucitavamo a i b [a, b] to je interval brojeva x
2.Ucitavamo [min, max] okvir za pom()
*/
int pom01(int x, int min, int max){
  int slucaj1 = 0;
  int slucaj2 = 0;
  int rezultat = 0;
  int x_copy = x;
  //ispituje 1 slucaj za obe cifre
  while (x > 0)
  {
    int c = x % 10;
    if((min <= c) && (c <= max)){
       slucaj1 = 1;
    }
    x/=10;
  }
  while (x_copy > 0)
  {
    int c = x_copy % 10;
    if((c < min) || (c > max)){
      slucaj2 = 1;
    }
    x_copy/=10;
  }

  if((slucaj1 == 1) && (slucaj2 == 1))
    rezultat = 1;

  return rezultat;
  
}
void zad05(int a, int b, int min , int max){
  for (int i = a; i <= b; i++)
  {
    if(pom01(i, min, max)){
      printf("%d ", i);
    }
  }
  
}
int main(){
  //printf("%d", pretvaranje_broja_u_bazu(32,3));
  zad05(30, 60, 4, 5);
  return 0;
}