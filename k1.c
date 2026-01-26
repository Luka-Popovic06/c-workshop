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
int srednja_cifra(int n){
  int copy_n = n;
  int br_cifara = 0;
  int redni_br_srednje_cif = 0;
  int c = 0;
  while (n > 0)
  {
    br_cifara++;
    n/=10;
  }
  if(br_cifara % 2 != 0 ){
    redni_br_srednje_cif = br_cifara / 2 + 1;
    while (redni_br_srednje_cif > 0)
    {
      
      if(redni_br_srednje_cif == 1){
        c = copy_n % 10;
      }
       copy_n /= 10;
      redni_br_srednje_cif--;
    }
  }else{
    redni_br_srednje_cif = br_cifara / 2;
    while (redni_br_srednje_cif >= 0)
    { 
      if(redni_br_srednje_cif == 1){
        c = copy_n % 10;
      }
      if(redni_br_srednje_cif == 0){
        c = c + ((copy_n % 10) * 10);
      }
      copy_n /= 10;
      redni_br_srednje_cif--;
    }
  }

  return c;
}


int main(){
  printf("%d\n", uslov2(889)); //2345678
  return 0;
}