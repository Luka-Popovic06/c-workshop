#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/*
Random funkcija:
1.Napisati program koji simulira bacanje šestostrane, dvanaestostrane i 
dvadesetostrane "kockice" (poliedra).
*/
void task01(){
  time_t t;
  srand(time(&t));

  int kocka_1 = rand() % 6 + 1; // X % n = {0, ... , n - 1}
  int kocka_2 = rand() % 12 + 1;
  int kocka_3 = rand() % 20 + 1;

  printf("%d %d %d \n", kocka_1, kocka_2, kocka_3);

}
void task02(){
  int n;
  printf("Unesite broj n:\n");
  scanf("%d", &n);
  int max = 0;
  int res = 0;
  for (int i = 0; i < n; i++)
  {
    int br = 0;
    int counter = 0;
    printf("Unesi te %d. broj\n", i);
    scanf("%d", &br);
    int br_copy = br;
    while (counter <= 3)
    {
      int c = br % 10;
      if(counter == 3)
        max = max < c ? c : max;

      if(max < c)
       res = br_copy;
        

      counter++;
      br/=10;
    }
    
  }
  printf("%d \n", res);
}

int main(){
  task02();
  return 0;
}