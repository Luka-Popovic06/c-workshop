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
int main(){
  zad02();
  return 0;
}