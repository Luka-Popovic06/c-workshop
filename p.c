#include <stdio.h>
#include <stdlib.h>
//ova biblioteka mi treba za sve naprednije matematičke operacije pr. Koren
#include <math.h>
//ovo nam treba za vreme
#include <time.h>

/* 
int main(){
  printf("Hello world!\n");
  return 0;
} 
*/


//TASK-1
void task01(){ //void znači da funkcija ne vraća nikakvu vrednost
  int a;//promenljiva / tipa int (celobrojni tip) / integer
  int b;

  // printf ispisuje poruku na ekran i traži od korisnika unos.
  // \n - novi red
  printf("Unesite prvi broj:\n");

  // scanf("%d", &a) čita celobrojni unos (%d) i smešta ga u promenljivu a.
  // &a znači da šaljemo adresu promenljive da scanf može da upiše vrednost direktno u a.
  scanf("%d", &a);

  printf("Unesite drugi broj:\n");
  scanf("%d", &b);

  //%d je placeholder za celobrojni rezultat.
  printf("Rezultat sabiranja je: %d \n", a+b);
  printf("Rezultata oduzimanja je: %d \n", a-b);
  printf("Rezultat množenja je: %d \n", a*b);
  printf("Rezultat deljenja je: %d \n", a/b);

  printf("Sabiranje: %d \n Oduzimanje: %d \n Množenje: %d \n ", a+b, a-b, a*b);
  
}


//TASK-2
void task02(){
  //Kreiraju se dve promenljive tipa float (brojevi sa decimalama).
  //Primer vrednosti: 3.5, 7.2, -1.0.
  //double - mozemo i ovo da koristimo za brojeve sa decimalama (64 bit)
  //float (32 bit)
  float a;
  float b;

  printf("Unesite prvi broj:\n");
  scanf("%f", &a);
  printf("Unesite drugi broj: \n");
  scanf("%f", &b);

  printf("Zbir: %f \n", a+b);
  printf("Razlika: %f \n", a-b);

  //sqrt(promenljiva)-za koren od broja
  //sqrt vraća tip double, čak i ako je a tipa float ili int.
  printf("Koren: %f \n", sqrt(a));

}


//Task-3
void task03(){

  //char- se stavlja za caracter(karakter) npr. Slovo-(%c)
  //Karakter možemo izraziti kao karakter(%c) ili kao broj(%d)
  char a;

  printf("Unesite slovo: \n");
  scanf("%c", &a);

  printf("ASCII vrednost unetog karakter %c je: %d \n", a, a);
}

//Task-4
void task04(){
  char veliko_slovo;

  printf("Unesite veliko slovo: \n");
  scanf("%c", &veliko_slovo);

  if(veliko_slovo >= 'A' && veliko_slovo <= 'Z'){

    char malo_slovo=veliko_slovo+('a' - 'A');
    
    printf("Odgovarajuće malo slovo je: %c \n",malo_slovo);

  }else{
    printf("Niste uneli malo slovo \n");
  }
}


//TASK-5
void task05(){

  //`time_t t;` – pravi promenljivu u kojoj će biti vreme (broj sekundi od 1.1.1970.)
  //time(&t)-ovako pristupamo toj promenljivoj(tom vremenu)
  time_t t;
  //`srand(time(&t));` – postavlja *seed* za generator slučajnih brojeva.
  srand(time(&t));
  //Ovo znači: **svaki put kad pokreneš program, `rand()` će davati druge brojeve**.  
  //Da nema ovoga, svako pokretanje bi imalo iste rezultate.

  int k1, k2, k3;

  k1=rand()%6+1;
  k2=rand()%12+1;
  k3=rand()%20+1;

  printf("Rezultat prvog bacanja: %d, %d, %d \n", k1, k2, k3);

  k1=rand()%6;//daje: 0 1 2 3 4 5
  // ++k1;- ovo prvo povecava, pa ispise broj
  k1++;//pomera na 1-6
  k2=rand()%12;
  k2++;
  k3=rand()%20;
  k3++;

  printf("Rezultat drugog bacanja: %d, %d, %d \n", k1, k2, k3);

  //pow(n,s)=> se koristi da se digne neki broj na odredjeni stepen
  //n-broj koji dižemo
  //s-stepen
  int d=pow(2,3);
  printf("Dva na treci stepen je: %d \n", d);

}


//TASK-6
void task06(){

  int a,q,k;
  int suma=0;
  int clan;

  printf("Unesite a: \n");
  scanf("%d", &a);
  printf("Unesite q: \n");
  scanf("%d",&q);
  printf("Unesite k: \n");
  scanf("%d",&k);

  for(int i=0;i<k;i++){
    clan=a*pow(q,i);
    suma+=clan;
  }

  printf("Suma prvih k članova je: %d, a K-ti član je: %d \n", suma,clan);

}

//Task-7
void task07() {
    int total;
    printf("Unesite broj sekundi:\n");
    scanf("%d", &total);

    int sekundi = total % 60;//sekunde % 60 → koliko ostane sekundi kada izbacimo minute
    int minuti = (total / 60) % 60;//minuti % 60 → koliko ostane minuta kada izbacimo sate
    int sati = total / 3600;

    printf("Sati:\t%d\nMinuti:\t%d\nSekunde:\t%d\n",
           sati, minuti, sekundi);
}

//TASK-8
void task08() {
    time_t t;
    srand(time(&t));
    int max,min;
    printf("Unesite broj od koga počinje interval:\n");
    scanf("%d", &min);
    printf("Unesite broj do koga ide interval:\n");
    scanf("%d",&max);
    //rand() % (max - min + 1) + min
    int random_number = rand() % (max - min + 1) + min;
    printf("Random broj od %d do %d je: %d\n",min,max, random_number);
}


//TASK-9
void task09(){
  int broj;
  printf("Unesite broj:\n");
  scanf("%d", &broj);
  //Modularno deljenje uvek vraca ostatak
  //4 % 2 = 0 , 3 % 2 = 1
  //Ukoliko imamo jednu liniju programskog koda posle if,for netrebaju nam {}
  if(broj % 2 == 0)
  printf("Broj je paran\n");
  else
  printf("Broj je neparan\n");
}


//TASK-10
//Argumenti u funkciji se nazivaju formalni elementi, mogu da ih imam formalan broj
void task10(int c1,int c2){
  if(c1 > c2){
    printf("Najveci dvocifren broj sastavljen od obe cifre je: %d\n", c1*10+c2);
  }else if(c2 > c1){
    printf("Najveci dvocifren broj sastavljen od obe cifre je: %d\n", c2*10+c1);
  }else{
    printf("Uneli ste dve iste cifre\n");
  }
  
}

//TASK-11
void task11(){
  int trocifren_br;
  printf("Unesite trocifren broj\n");
  scanf("%d", &trocifren_br);
  int c1,c2,c3;
  c1=trocifren_br/100;
  c2=(trocifren_br%100)/10;
  c3=trocifren_br%10;
  if(c2>c3 && c2>c1){
    printf("Da, srednji broj je veci od druga dva\n");
  }else if(c2<c3 || c2<c1){
    printf("Ne, srednji broj nije veci od druga dva\n");
  }else if(c2==c3 && c2==c1){
    printf("Brojevi su jednaki\n");
  }else{
    printf("Jedan od dva brja je jednak sa srednjim brojem\n");
  }
}


//TASK-12
void task12(){
  int mesec, godina;
  printf("Unesite mesec i godinu\n");
  scanf("%d %d", &mesec, &godina);

  int broj_dana_u_mesecu;

  switch(mesec){
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        broj_dana_u_mesecu=31;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        broj_dana_u_mesecu=30;
        break;
    case 2:
        if((godina % 4 ==0 && godina % 100 != 0) || godina % 400 == 0){
          broj_dana_u_mesecu=29;
        }else {
          broj_dana_u_mesecu=28;
        }
        break;
    default:
        printf("Pogresno ste uneli mesec!\n");   
        return; 
  }
  printf("Broj dana u mesecu je: %d\n", broj_dana_u_mesecu);
}

//TASK-13
void task13(){
  int b;
  printf("Unesite broj:\n");
  scanf("%d", &b);

  while(b%10==0){
    b/=10;
  }

  printf("Broj sa uklonjenim nulama je: %d \n", b);
}

//TASK-14
void task14(){
  int n;// broj brojrva
  printf("Unesite prirodan broj n: ");
  scanf("%d", &n);

  if(n <= 0){
    printf("Niste uneli prirodan broj!\n");
    return;
  }

  int broj;
  int max_br=0;
  int max_cifra_stotina=0;

  printf("Pocinjemo sa unosom n celih brojeva:\n");

  for(int i=1; i <= n; i++){

    printf("Unesite nam %d. broj: ", i);
    scanf("%d", &broj);

    //123456 ---> 123456 / 100 = 1234 % 10 = 4  ==> Ovako se dobija cifra stotina
    //broj = 458 → cifra stotina = 4
    //broj = 9823 → cifra stotina = 8

    int pom= broj / 100;
    int cifra_stotina=pom % 10;

    if(cifra_stotina > max_cifra_stotina){
      max_cifra_stotina=cifra_stotina;
      max_br=broj;
    }
  }
  printf("Broj sa maksimalnom cifrom stotina je: %d \n", max_br);
}


//TASK-15
void task15(){
  time_t t;
  srand(time(&t));
  int random_br=rand()%10+1;
  int uneti_br;
  int broj_pokusaja=1;
  do {
    printf("Unesite %d. broj:",broj_pokusaja);
    scanf("%d", &uneti_br);
    broj_pokusaja++;
  } while(uneti_br != random_br);

  printf("Bravo, pogodiliste broj! \n");
}

//TASK-16
void task16(){
  int ocena;
  int suma_ocena=0;
  int broj_ocena=0;
  double prosek;

  while(1){
    printf("Unesite ocenu: \n");
    scanf("%d", &ocena);

    //ocena == 0
    if(!ocena){
      break;
    }

    if(ocena < 6 || ocena > 10){
      printf("Unos nije validan.\n");
      continue;
    }
    suma_ocena += ocena;
    broj_ocena++;
  }

  //broj_ocena == 0
  if(!broj_ocena){
      printf("Nije uneta ni jedna ocena!\n");
      return;
  }  

  //ovo se zove kastovanje 
  //kada pretvaramo intiger u double tako sto jedan broj pomnozimi sa 1.0
  prosek = suma_ocena * 1.0 / broj_ocena;

  printf("Prosecna ocena je: %.2f", prosek);
}


//Task-17***
void task17(){
    int br;
    printf("Unesite broj:\n");
    scanf("%d", &br);

    int cifra;
    int hvatac_br = 0;
    int rezultat = 0;
    int brojac = 0;

    // Hvatamo svaku drugu cifru (od desne)
    while(br > 0){
        cifra = br % 10;

        if(brojac == 0){
            hvatac_br = hvatac_br * 10 + cifra;
            brojac = 1;
        } else {
            brojac = 0;
        }

        br /= 10;
    }

    // hvatac_br je obrnut – sada ga vraćamo
    while(hvatac_br > 0){
        rezultat = rezultat * 10 + (hvatac_br % 10);
        hvatac_br /= 10;
    }

    printf("Dobijeni broj je: %d\n", rezultat);
}

//TASK-18
void task18(){
  int n;
  printf("Unesite prost broj:\n");
  scanf("%d", &n);

  if(n <= 1){
    printf("Broj nije prost!\n");
    return;
  }
  if(n == 2){
    printf("Broj 2 je prost!\n");
    return;
  }
  //ceil() ===> se koristi za zaokruzivanje
  for(int i=2; i <= ceil(sqrt(n)); i++){
    if(n % i == 0){
      printf("Broj %d. nije prost broj!\n", n);
      return;
    }
  }
  printf("Broj %d je prost!\n",n);
}

//TASK-19
void task19(){
  //samo kad unosimo varijablu nam ne treba vrednost nje
  int broj;
  printf("Unesite broj\n");
  scanf("%d", &broj);
  int s,d,j;
  s=broj/100;
  d=(broj/10)%10;
  j=broj % 10;
  //ovde nam treba vrednost promenljive

  int amstrongovBroj=0;
  amstrongovBroj=pow(s,3)+pow(d,3)+pow(j,3);

  if(broj==amstrongovBroj){
    printf("Dobili smo Amstrongov Broj, broj %d je jednak sa %d\n", broj, amstrongovBroj);
  }else{
    printf("Nismo dobili Amstrongov broj\n");
  }
}

