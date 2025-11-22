#include <stdio.h>
#include <stdlib.h>



// (0, 0) ==> 0-ta vrsta , 0-ta kolona, (0, 1) ==> nulta vrsta prva kolona
// (1, 0) ==> 1 vrsta , 0 kolona, (1, 1) ==> prva vrsta, prava kolona
//(2,0) (2,1) (2,2) (2,3)

//(0,0) (0,1) (0,2) (0,3)
//(1,0) (1,1) (1,2) (1,3)
//(2,0) (2,1) (2,2) (2,3)
//(3,0) (3,1) (3,2) (3,3)
//1.task
void task28(int n){
  for(int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      printf("*\t");
    }
    printf("\n");
  }
}

//2.task
void task29(int n){
  for(int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      if(i == 0 || i == n-1 || j == 0 || j == n - 1){
        printf("*");
      }else{
        printf(" ");
      }
    }
    printf("\n");
  }
}

//3.task
void task30(int n){
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(i == 0 || i == n-1 || j == 0 || j == n - 1 || i == j){
        printf("*");
      }else{
        printf(" ");
      }
    }
    printf("\n");
  }
}

//4.task
void task31(int n){
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(i == j || i == n - j - 1){
        printf("*");
      }else{
        printf(" ");
      }
    }
    printf("\n");
  }
}
//5.task
void task32(int n){
  for (int r = 0; r < n; r++)
  {
    for (int c = 0; c < n; c++)
    {
      if( r == c || r > c){
        printf("*");
      }
      
    }
    
    printf("\n");
  }
  
}

//6.task
void task33(int n){
  for (int i = 0; i < n; i++)
  {
    for(int j = 0; j < n - 1; j++){
      printf("*");
    }
    printf("\n");
  }
}

//7.task
//Ugnjezdena petlja
//Ispisati sve trocifrene brojeve cije su sve cifre razlicite.
void task34(){
  for(int i = 1; i <=9; i++){
    for(int j = 0; j <= 9 ; j++ ){
      for(int k = 0; k <=9; k++){//prva sa radom krece ova
        if(i != j && i!=k && j!=k){
          printf("%d%d%d\n", i, j, k);
        }
      }
    }
  }
}

//8.task
/*Naci i ispisati sve savrsene brojeve u intervalu [1, n]. Savrseni broj je onaj tiji je zbir
svih pravih delilaca jednak samom broju, npr. 6 = 1 + 2 + 3.*/
void task35(int n){
  for(int i = 2; i<=n; i++){ // pravi interval
    int suma=0;
    for(int j = 1; j < i; j++){//ovde trazimo prave delioce
      if(i % j == 0)
         suma += j;
    }
    if(suma == i)
       printf("Broj %d jeste savrsen broj!\n", i);
  }
}

//9.task
void task36(){
  // n! - faktorijal = n * (n-1) * (n-2)*... * 3 * 2 * 1
  //i! = 1 * 2*... * i
  // 0! = 1
  int x, n, p = 1, s = 0 , f = 1;
  printf("Unesite vrednost x: ");
  scanf("%d", &x);
  printf("Unesite vrednost n: ");
  scanf("%d", &n);

  for(int i = 0;i <= n; i++){
    for(int j=1; j <=i; j++)
    {
      p*= x;
    }
    for (int j = 1; j <= i; j++) {
        f *= j;
    }
    s +=p / f;
    p = f = 1;
  }

  printf("Suma reda je %d", s);
}

int main(){
  task36();
  return 0;
}