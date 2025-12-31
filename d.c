#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


// 1.
//Faktorijal broja n (piše se n!) je proizvod svih celih brojeva od 1 do n.
//n!=1⋅2⋅3⋅...⋅n

void calculateAndPrintFactorial(){
  printf("Unesi broj:\n");
  int br;
  int rezultat=1;
  scanf("%d", &br);

  for(int i = 1; i<=br; i++){
    rezultat*=i;
  }
  printf("Faktorijal broja %d je %d", br, rezultat);
}

/*
2.Ispitujemo da li je neki broj prost
Prost broj je broj veći od 1 koji ima tačno dva delitelja: 1 i sebe samog.
*/

void isPrime(){
  printf("Unesi broj:\n");
  int br;
  scanf("%d",&br);
  if(br==2){
      printf("Broj je prost");
      return;
  }else if(br < 2){
    printf("Broj nije prost");
      return;
  }
  
  for(int i=2; i < br; i++){
    if(br % i == 0)
    {
      printf("Broj %d. nije prost\n", br);
      return;
    }
  }
  printf("Broj %d. je prost broj\n", br);
  
}
/*
3.Fibonačijev broj:
Fibonacijev (Fibonacci) broj je deo Fibonacijevog niza.
Svaki broj je zbir prethodna dva broja.
F0=0 , F1=1, F2= F0 + F1 = 1, F3=2, F4= F2 + F3 = 3, F5 = 5, F6=8 ....
*/
void isFibonacci(){
  printf("Unesi broj:\n");
  int br;
  int br1=1;
  int br2=2;
  int fibonacijev_br=3;

  scanf("%d",&br);
  if(br == 0 || br == 1 || br == 2){
    printf("Broj %d. jeste u Fibonacijevom nizu.\n", br);
    return;
  }
     
  while (fibonacijev_br <= br)
  {
    if(fibonacijev_br == br){
      printf("Broj %d. jeste u Fibonacijevom nizu.\n", br);
      return;
    }
    br1=br2;
    br2=fibonacijev_br;
    fibonacijev_br=br1+br2;
  }
  printf("Broj %d. nije u Fibonacijevom nizu.\n", br);
  
}

/*
4.Napisati program koji od unetog broja N ispisuje broj koji ima cifre kao broj N, samo u obnutom redosledu.
Primetiti da obrnuti broj nema vodecih nula.
N>0
*/
void reverseNumber(){
  int br;
  printf("Unesi broj N:\n");
  scanf("%d",&br);
  int reversedNumber = 0;
  while (br>0)
  {
    if(br==0){
      continue;
      br /= 10;
    }
    reversedNumber=reversedNumber * 10 + (br%10);
    br /= 10;
  }
  printf("Obrnut broj je: %d\n", reversedNumber);
}
/*
5.Napisati program kojim se izbacuje svako pojavijivanje cifre CF-cifra iz datog broja N.
(0<=cf<=9)
*/

void removeDigit(){
  int br, CF;
  printf("Unesite broj:\n");
  scanf("%d", &br);
  printf("Unesite cifru koju hocete da izbacite:\n");
  scanf("%d", &CF);
  int result=0;
  int stepen=0;
  while (br>0)
  {
    if(br%10 != CF){
      result=result+((br%10)*pow(10,stepen));
      stepen++;
    }
    br/=10;
  }
  printf("Broj sa izbacenom cifrom je: %d", result);
}

/*
6.Napisati funkciju pom(int/arg) int ky koja vraca broj dobijen kada se iz 
argumenta arg uklone sve cifre manje od k (vratiti nula ako se izbace sve cifre).
 Sabrati brojeve koje vraca ova funkcija za 3 broja koja korisnik unese, i za
 k=5
*/
int removeNumber(int arg,int k){
  int number=0;
  int stepen=0;
  while (arg>0)
  {
    if(arg%10 > k){
      number=number+((arg%10)*pow(10,stepen));
      stepen++;
    }
    arg/=10;
  }
  return number;
}
void pom1(){
  int br1,br2,br3;
  printf("Unesite 1. broj:\n");
  scanf("%d",&br1);
  printf("Unesite 2. broj:\n");
  scanf("%d",&br2);
  printf("Unesite 3. broj:\n");
  scanf("%d",&br3);

  int result=removeNumber(br1,5)+removeNumber(br2,5)+removeNumber(br3,5);

  printf("Rezultat je: %d\n",result);
}

/*
7.Napisati funkciju pom(int arg) koja vraca najvecu razliku izmedu susednih 
cifara argumenta (pretpostavimo da argument uvek ima bar dve cifre). 
Zatim ispisati sve brojeve iz intervala koji unosi korisnik a kojima je najveca 
razlika izmedu cifara manja od 3.
*/
int pom2(int arg){
  int result=0;
  while (arg >= 10)
  {
    int cf1=arg%10;
    arg/=10;
    int cf2=arg%10;
    
    int razlika=abs(cf1-cf2);
    result=razlika>result ? razlika : result;
  }

  return result;
}

void task1(){
  int n,m;
  scanf("%d%d", &n, &m);
  for (int i = n; i <= m; i++)
  {
    if(pom2(i) < 3)
       printf("%d\n", i);
  }
  
}

/*
8.Napisati funkciju int pom(int num, int(min, int max) koja vraca broj u kome 
su cifre broja num koje su van intervala [min, max] zamenjene najblizom cifrom 
iz intervala. Ako je cifra unutar intervala, ostaje nepromenjena. 
U glavnom programu citati cetiri broja: 
min, max, a i b, gde je a <= bi 0 <= min <= max <= 9. 
Zatim, za svaki broj u intervalu od a do b, pozvati funkciju pom i ispisati broj 
posle zamene.
Primer: Ulaz: 3 5 130 140
Izlaz: 333 333 333 333 334 335 335 335 335 335 343
*/

int pom3(int num,int min, int max){
  int result=0;
  int stepen=0;
 
    while (num > 0)
    {
      if(min <= num%10 && num%10 <= max){
      result=result + ((num%10)* pow(10,stepen));
      }else if(min > num%10){
      result=result + (min* pow(10,stepen));
      }else if(max < num%10){
      result=result + (max * pow(10,stepen));
      }
      stepen++;
      num/=10;
    }
  return result;
}

void task2(){
  int min,max,a,b;
  int result=0;
  scanf("%d%d%d%d",&min,&max,&a,&b);
  for (int i = a; i <= b; i++)
  {
    result=pom3(i,min,max);
    printf("%d\n", result);
  }
  
}
/*
9.Napisati program u kojem se izbacuju samoglasnici iz unetog teksta.
,
*/
void removeVowels(){
  char c;
  while ((c=getchar())!= '\n')
  {
    switch(c){
      case 'a':
      case 'e':
      case 'i':
      case 'o':
      case 'u':
      //continue moze a i ne treba
       break;
      default:
       putchar(c);
       //return; da je ovde ono bi pravilo problem zato sto izlazi iz cele funkcije
    }
  }
  
}

/*
10.Napisati program koji pronalazi najveći broj u unetom tekstu.
*/
int isDiget(char c){
  if(c >= '0' && c <= '9')
    return 1;
  else
    return 0;
}
void findLargestNumber(){
  char c;
  int max_number=0;
  int br=0;
  while ((c = getchar()) != '\n')
  {
    if(isDiget(c) == 1){
      br=br*10 + (c - '0');
    }else{
      max_number= max_number < br  ? br : max_number;
      br=0;
    }
    
  }
  max_number= max_number < br ? br : max_number;
  printf("max %d\n",max_number);
}

/*
11.Svaka rec da pocinje velikim slovom
*/

void capitalizeWords(){
  char c;
  int flag=1;//flag(zastava) se koristi u programiranju da oznaci nesto u ovom slucaju space
  while ((c = getchar()) != '\n')
  {
    if(flag == 1 && c<='z' && c>='a'){
      c=c - ('a'-'A');
      flag = 0;
    }else if(c == ' '){
      flag=1;
    }else {
      flag=0;
    }
    putchar(c);
  }
  
}
/*
12.Sve sto je unutar zagrade ne treba da se ispise
*/
void removeParenthesesContent(){
  char c;
  int flag=0;
  while ((c = getchar()) != '\n')
  {
    if(c == '('){
      flag=1;
    }else if( c == ')'){
      flag=0;
    }else if(flag == 0){
      putchar(c);
    }
  }
  
}

/*
13.Koristeći naredbu while i funkciju getchar() za čitanje karaktera obraditi ulaznu
sekvencu slova i cifara, i izračunati zbir brojeva koji se nalaze izmedu dva 
slova koji su u ASCII taebli udaljeni najvise do 2 mesta (uključujući 2).
ab11cnh23zk37j1jht21m
,,
*/
int isDig(char c){
  return c<='9' && c>='0' ? 1 : 0;
}

void task3(){
  char c;
  int last = '1';
  int br = 0;
  int suma = 0;
while ((c = getchar()) != '\n')
{
  if(isDig(c) == 1){
    br=br*10+(c -'0');
  }else{
    if(abs(last - c) <= 2){
      suma += br;
    }
    br = 0;
    last = c;
  }
}
printf("%d", suma);
}

/*
14.Napisati program kojim se odreduju i ispisuju svi savršeni brojevi od 2 do N. 
Broj je savršen ako je jednak sumi svojih delitelja isključujući njega samog. 
28 je savršen broj, jer je: 28 = 1 + 2 + 4 +
7 + 14
,
*/

int isSavrsen(int br){
  int sum=0;
  for (int i = 0; i < br; i++)
  {
    if(br % i == 0){
     sum+=i;
    }
  }
  if(sum == br)
     return 1;
  else
     return 0;
}
void task4(){
  int n;
  printf("Unesite poslednji broj\n");
  scanf("%d", &n);
  for (int i = 2; i < n; i++)
  {
    if(isSavrsen(i) == 1)
       printf("%d \n", i);
  }
  
}
int main(){
  task4();
  return 0;
}