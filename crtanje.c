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
