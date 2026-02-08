#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
//MATRICE
//uvek se prosledjuje njena prava vrednost, a ne kopija
/*
( vrsta , kolona )

(0,0) (0,1) (0,2) 
(1,0) (1,1) (1,2) = A
(2,0) (2,1) (2,2)
*/
/*
1.PRISTUPANJE ELEMENTU:
- A[V][K] ==> A[1][1]

2.ZA POPUNJAVANJE MATRICE KORISTIMO:
-Dve ugnjezdene for petlje
-prva je za vrste, a drga je za kolone

3.Deklaracija Matrice:
 int A[3][3]


4.Galvna dijagonal:
   i = j
5.Iznad glavne dijagonale:
   i < j
6.ispod glavne dijagonale:
   i > j


//RAD SA ADRESAMA(& - putem ovoga pristupam adresi promenljive)
// f-ja( &MIN )
1.REFERENCIRANJE:
-STAVLJAMO INT *MIN (DOBIJAMO ADRESU PROMENLJIVE)
2.DEFERENCIRANJE:
-PONOVO STAVLJAMO ZVEZDICU:
- *MIN (PRISTUPAMO VREDNSOTI)
*/
void popuni_matricu(int a[3][3], int n){
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      printf("Unesi te [%d,%d] element u matricu\n", i, j);
      scanf("%d", &a[i][j]);
    }
  }
}
void ispisi_matricu(int a[][3], int n){
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      printf("%d ",a[i][j]);
    }
    printf("\n");
  }
}
//1.Ispisati srednju vrednost elemenata iznad glavne dijagonale
void zad01(){
  int a[3][3];
  int n = 3;
  popuni_matricu(a,n);
  ispisi_matricu(a,n);
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if(i < j) printf("%d", a[i][j]);
      else continue;
    }
  }
}
//2.Ucitava matricu i potom je transponuje
void zad02(){
  int m[3][3];
  int n = 3;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      printf("Unesi [%d,%d] element:", i,j);
      scanf("%d", &m[i][j]);
    }
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      printf("%d ", m[j][i]);
    }
    printf("\n");
  }
  
  
}
//3.ispisati unatu mat. tako da su joj kolone sortirane u rastucem poredku
void swap(int *x, int *y){
  
  if(*x > *y){
    int tmp = *y;
    *y = *x;
    *x = tmp;
  }
}
void sortKoloneMatrice(int mat[][3], int n){
  for (int kolona = 0; kolona < n; kolona++)
  {
    for (int vrsta1 = 0; vrsta1 < n - 1; vrsta1++)
    {
      for (int vrsta2 = vrsta1 + 1; vrsta2 < n; vrsta2++)
      {
        swap(&mat[vrsta1][kolona], &mat[vrsta2][kolona]);
      }
    }
  }
}
void zad03(int n){
  int mat[3][3];
  popuni_matricu(mat, n);
  ispisi_matricu(mat,n);
  printf("\n");
  sortKoloneMatrice(mat,n);
  printf("\n");
  ispisi_matricu(mat,n);
  printf("\n");
}
//4.F-ja za uneti br n= 45371 pravi matricu
//prva vrsta su cif broja
//svaka sledeca vrsta umanjuje vrednost za 1 ili 2 naizmenicno
//kad se dojde do 0 krece se od 9 i odma se primenjuje (1 ili 2)
//neparna kolona se smanjuje za 1
//parna za 2
//kad se spustim ispod 0 dodajem 10 i primenjeujem pravilo
void zad04(int n){
  int a[5][5];
  int rot_n=0;
  while (n > 0)
  {
    rot_n=rot_n * 10 + (n % 10);
    n/=10;
  }
  
  for (int vrsta = 0; vrsta < 5; vrsta++)
  {
    for (int kolona = 0; kolona < 5; kolona++)
    {
      if(vrsta == 0 ){
      a[vrsta][kolona]=rot_n%10;
      rot_n/=10;
      }else if(vrsta % 2 != 0){
        if(a[vrsta-1][kolona] > 0 && (a[vrsta-1][kolona] != 1)){
        a[vrsta][kolona]=a[vrsta - 1][kolona] - 1;
        }else if(a[vrsta-1][kolona] == 0){
          a[vrsta][kolona] = 10 - 1;
        }else if(a[vrsta-1][kolona] == 1){
          a[vrsta][kolona] = 10 - 1;
        }
      }else{
        if(a[vrsta-1][kolona] > 0 && (a[vrsta-1][kolona] != 1)){
        a[vrsta][kolona]=a[vrsta - 1][kolona] - 2;
        }else if(a[vrsta-1][kolona] == 0){
          a[vrsta][kolona] = 10 - 2;
        }else if(a[vrsta-1][kolona] == 1){
          a[vrsta][kolona] = 10 - 1;
        }
      }
    }
  }
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      printf("%d ", a[i][j]);
    }
    printf("\n");
  }
}
//////////////////////////////////////////////////////////////////////////////////////
// STRINGOVI //
/*
1.NIZ KARAKTERA
- ['A','N','A','\0']
- na kraju svakog stringa ide '\0' (govori gde je kraj niza)
- za brisanje dela stringa brojimo mesta i ispred dela koji zelimo da izbacimo
stavimo '\0'

2.DEKLARACIJA STRINGA (NIZA):
- char text[100]

3.PRISTUPANJE ELEMENTIMA STRINGA (NIZA):
string[0]=> prvi element iz niza

4.KORISTI SE BIBLIOTEKA:
 <STRING.H>

5.FUNKCIJE:
 a) strlen(s) => broji elemente u stringu, broji i '\0', pa zato oduzmemo - 1

 b) fgets(s, n, stdin)=> unos stringa
     - s => nas string
     - n => duzina stringa
     - stdin => ulaz(tastatura)

  v)puts(s)=>ispisivanje stringa
*/
//5.Napisati program koji ucitava text, uklanja mu razmake i ispisuje ga na konzolu
#include <string.h>
#define MAX 100

void removeWhiteSpace(char *s){
  int n = strlen(s) - 1;
  int j = 0;
  for (int i = 0; i < n; i++)
  {
    if(s[i] != ' ' && s[i] != '\t'){
      s[j] = s[i];
      j++;
    }
  }
  s[j]='\0';
}
void stringPrvi(){
  char s[MAX];
  printf("Unesite neki tekst:");
  fgets(s, MAX, stdin);
  removeWhiteSpace(s);
  puts(s);
}
int main(){
  stringPrvi();
  return 0;
}