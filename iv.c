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
  g)strtok(veliki text, granicnik)=> vraca sve pre granicnika, ne stavlja '\0'
  d)strstr(text, mali text)=> Trazi pojavljivanje 1 str. unutar 2 stra. Ako ga ima vraca nej adrsu u suprotnom NULL
  ð)strcat(str_u_koji_dodajemo, str_koji_se_dodaje);
  e)atoi => ascii to  int (pretvara string u int(broj)) pr("123" => 123)
  ž)strcpy(ime_naseg_stringa, "lol king johan") => ubacuje u nas string neku vrednost

6.Znak za ispis stringa je %s
printf("%s", text) => ovo je kao puts(text);

7.Kroz nje ga mozemo da se krecemo putem adrese od nekog njegovog dela

*/
//5.Napisati program koji ucitava text, uklanja mu razmake i ispisuje ga na konzolu
#include <string.h>
#define MAX 100

void removeWhiteSpace(char *s){
  int n = strlen(s) - 1;
  int j = 0;
  for (int i = 0; i < n; i++)
  {
    if(s[i] != ' ' && s[i] != '\t'){// s[i] = *(s + 1)
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
//6.Napisati program koji ucitava tekst i ispisuje sve njegove pod stringove
void make_strings(char *s){
  int n = strlen(s) - 1;
  //i oznacava poziciju pocetka stringa
  for (int i = 0; i < n; i++)
  {
    //j oznacava poziciju kraja stringa
    for (int j = i; j < n; j++)
    {
      int pozicija = i;
      while (pozicija <= j)
      {
        printf("%c", s[pozicija]);//ispisi taj karakter
        pozicija++;
      }
      printf("\n");
    }
  }
}
void zad05(){
  char s[100];
  printf("Unesi te text:\n");
  fgets(s,100,stdin);
  make_strings(s);
}
//7.Svaki karakter treba da se pojavi 2 puta
void dupliraj_slovo(char *s){
  int n = strlen(s) - 1;
  int brojac_mesta = 0;
  char c[100];
  for (int i = 0; i < n; i++)
  {
    int counter = 0;
    while (counter < 2)
    {
     c[brojac_mesta] = s[i];
     counter++;
     brojac_mesta++;
    }
  }
  c[brojac_mesta] = '\0';//nemoj da zaboravis da zatvoris string sa '\0' !!!
  puts(c);
}
void zad06(){
  char s[100];
  printf("Unesi te text:\n");
  fgets(s, 100, stdin);
  dupliraj_slovo(s);
}
//8.Napisati program koji ucitava dva texta
//iz prvog text se izbaci sve ono sto je u drugom textu
void pravljenjeTexta(char *text3, char *text2, char *text1){
  int n1 = strlen(text1)-1;
  int n2 = strlen(text2)-1;
  int flag =1;
  int counter=1;
  for (int i = 0; i < n1; i++)
  {
    for (int j = 0; j < n2; j++)
    {
      if(text1[i] == text2[j]) flag = 0;
    }
    if(flag){
      text3[counter]=text1[i];
      counter++;
    }else{
      flag = 1;
    }
  }
  text3[counter]='\0';
  puts(text3);
}
void zad07(){
  char text1[MAX];
  char text2[MAX];
  char text3[MAX];
  printf("Unesi te text1:\n");
  fgets(text1,MAX, stdin);
  printf("Unesi te text2: \n");
  fgets(text2,MAX,stdin);
  pravljenjeTexta(text3,text2,text1);
}
//9.Na osnovu unetog teksta izvuci reci koje se ponavljaju 2 puta

void printRecurringWords(char *pocetni){//pocetni string
  char krajni[100];//resenje 
  krajni[0]='\0';//u pocetku je prazan string

  //ovo je tehnika koja se zove tokenizacija, ili ti splitovanje
  char *token;
  token = strtok(pocetni," ");// za razmak nije ' ' nego je " "
  //KAD NE BUDE MOGAO DA IZVLACI VISE TOK VRACA NULL
  printf("%s", token);

  while (token)//dokle god je token razlicit od NULL
  {     //ako ne sadrzi token     //i ako ga ima u ostatku pocetnog str
   // strstr(krajni, token) ako vrati 0 ! ce ga pretvoriti u 1 i obrnuto
    if(!strstr(krajni, token) && strstr(token + strlen(token) + 1, token)){
                                  //da bi dobili ostatak od pocetnog str
                                  //pomeramo se putem memorijske adrese od tokena
                                  //putem nje idemo kroz pocetni string
                                  //pomeramo se od adrese tokena za broj njegovih elemenata 
                                  //+ 1 to je granicnik u nasem sl.(" ")

        strcat(krajni,token);//"Zelena" + "trava" => "Zelena trava"
        strcat(krajni, " ");//KonKanTeNacija
    }
    token = strtok(NULL," ");
    //ovako mu govorim da predje na sledecu rec
    //ovako mu kazem da tokenizuje sledecu rec
  }
  puts(krajni);
}
/////////////////////////////////////////////////////////////////////////////////////
/*                          //  STRUKTURA (STRUCT) //
1.strcpy(s1.string, "Luka sdk")=> sluzi za unos texta u string
2.Inicijalizacija odmah: // struct Student s1 = {"Marko", 2, 9.5}; //
*/
//Osnovna sintaksa:
struct Studen {
  char ime[30];
  int godine;
  double prosek;
};
//Ovde si definisao šablon (tip podatka).
void struDef(){
  struct Studen s1; //Kreiranje promenljive strukture
  s1.godine = 21;
  // (.) je operator pristupa
  s1.prosek = 10.00;
  strcpy(s1.ime,"Luka Popovic");//za ubacivanje strinag u neki drugi string
  //printf("%d\n%.2lf\n%s ", s1.godine,s1.prosek,s1.ime);

  struct Studen king;//kreiromo novu promenljivu strukturu

  king = s1;//ovako prenosimo informacije izmedju struktura 
  printf("%d\n%.2lf\n%s\n", king.godine,king.prosek,king.ime);
}
/*10.Napisati program koji učitava širinu i visinu pravougaonika, formira strukturu 
koja ga predstavlja, a zatim ispisuje površinu tog pravougaonika.*/
struct Pravougaonik
{
  double sirina;
  double visina;
  double povrsina;
};

void zad10(){
  struct Pravougaonik s1;
  scanf("%lf %lf", &s1.sirina,&s1.visina);
  s1.povrsina = s1.sirina * s1.visina;
  printf("%.2lf\n%.2lf\n%.2lf\n", s1.sirina,s1.visina,s1.povrsina);
}
////////////////////////////// Ugnježdene strukture /////////////////////////////////////////////////
/*11.Napisati program koji učitava ime, prezime i adresu prebivališta za jednog studenta. 
Adresa sadrži ime ulice i broj. Ispisati sve podatke o studentu.
//typedef => da ne pišeš stalno struct
*/
 typedef struct Adresa
 {
   char imeUlice[90];
   int broj;
 }adresa;
 

typedef struct Student {
  char ime[50];
  char prezime[50];
  adresa adr;//!!!!
}student;

void zad11(){
  student s1;
  adresa a1;
  printf("Unesite Ime studenta:\n");
  fgets(s1.ime, 50, stdin);
  s1.ime[strlen(s1.ime) - 1] = '\0';//ovo se stavlja zato sto, fgets() pokupi i '\n', ovako brisemo '\n'
  printf("Unesite Prezime studenta\n");//kad pokupi '\n' on ga i ispise posel
  fgets(s1.prezime, 50, stdin);
  s1.prezime[strlen(s1.prezime) - 1] = '\0';
  printf("Unesite Ime Ulice\n");
  fgets(a1.imeUlice,90,stdin);
  a1.imeUlice[strlen(a1.imeUlice) - 1] = '\0';
  char br[40];
  fgets(br, 40, stdin);
  br[strlen(br)-1] = '\0';
  a1.broj = atoi(br);

  s1.adr = a1;//kopiranje struktura

  printf("Ime i Prezime: %s %s\n", s1.ime, s1.prezime);
  printf("Adresa i Broj: %s %d", s1.adr.imeUlice, s1.adr.broj);//!!!!!!
}
///////////////////////////// Čitanje iz fajla //////////////////////////////////////////////////
/*
1.FILE* fopen(const char *ime_fajla, const char *mode);
-ime_fajla => fajl koji otvaramo
-mode => nacin na koji citamo fajl
-FILE* => ovo je rezultat(kao rezultat dobijem pokazivac na fajl)
2.Tipovi modova:
 a) r - otvara fajl za citanje, (ako varati NULL => znaci nema fajla)
 b) w - otvara fajl za pisanje (brise postojeci text)
 v) a - otvara fajl za pisanje na kraj (ne brise postojeci text)
 g) r+ - otvara faj za citanje i pisanje (ako ga nema ne pravi novi faj)
 d) w+ - otvara fajl za citanje i pisanje (ako ga nema pravi nov)(brise ppostojeci text)
 ð) a+ - otvara fajl za citanje i pisanje na kraju 

3.fclose(fajl) => zatvara faj koji smo pre otvorili
*/

/*12.Napisati program koji iz navedenog tekstualnog fajla iščitava ime, 
prezime i težinu osobe, a zatim te informacije ispisuje na konzolu.
*/

void zad12(){
  char naziv[90];//ovde cuvamo ime naseg fajla
  char red[90]; // ovde cuvamo jedan red koji procitamo
  char *token;

  printf("Unesite ime fajla:\n");
  fgets(naziv, 90, stdin);
  naziv[strlen(naziv) - 1]='\0';

  // fopen(char *fname, char *mode)

  FILE* fp = fopen(naziv,"r");//ovako pristupamo nekom fajlu

  if(fp == NULL){
    printf("Greska pri radu sa fajlom\n");
    fclose(fp);//zatvaramo fajl
    return;
  }

  //fgets(red, 90, fp);//ovako citamo fajl
  while (fgets(red,90,fp) == red)
  {
    char ime[90];
    char prezime[90];
    int tezina;

    token = strtok(red, " ");
    strcpy(ime,token);
    token = strtok(NULL, " ");//ovo znaci da od mesta gde si zavrsio nastavi dalje 
    strcpy(prezime, token);
    token = strtok(NULL," ");
    tezina = atoi(token);

    printf("%s %s %d\n", ime,prezime,tezina);
  }
  fclose(fp);
}
/*13.Napisati program koji iz željenog tekstualnog fajla učitava podatke 
o imenu, prezimenu i težini osobe i formira niz osoba. Potrebno je da se 
ovaj niz sortira u neopadajućem poretku po teżini osoba i tako sortiran upiše 
u novi tekstualni fajl.*/
#define MAX_NIZ 100

typedef struct{
  char ime[90];
  char prezime[90];
  int tezina;
}osoba;

void swap2(osoba *a, osoba *b){
  osoba tmp = *a;
  *a = *b;
  *b = tmp;
}
void zad13(){
  char naziv[90];//naziv fajla
  char red[90];//red u fajlu
  char *token;// deo od reda

  printf("Unesite ime fajla:\n");
  fgets(naziv,90,stdin);
  naziv[strlen(naziv) - 1] = '\0';

  FILE* fpI = fopen(naziv, "r");//otvaramo fajl i pripremamo ga za citanje

  if(fpI == NULL){
    printf("Greska pri otvaranje fajla.\n");
    fclose(fpI);
    return;
  }

  osoba niz[MAX_NIZ];//pravimo niz od osoba

  int pos = 0; //prati koliko sam osoba ucitao

  while (fgets(red, 90, fpI) == red)//ovde se vrsi ucitavanjer red-a (ucitavanje iz fajla po defaultu ide red po red)
  {
    token = strtok(red," ");
    strcpy(niz[pos].ime, token);//dodeljujemo vrednost polju iz struct-a
    token = strtok(NULL," ");
    strcpy(niz[pos].prezime, token);
    token = strtok(NULL," ");
    niz[pos++].tezina = atoi(token);//ovde povecavamo pos, ali tek u sledecoj liniji
  }

  int n = pos;

  //sad radimo sortiranje niza
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if(niz[i].tezina > niz[j].tezina){
        swap2(&niz[i], &niz[j]);
      }
    }
    
  }
  
  //ovde radimo ispisivanje u fajl

  printf("Unesite ime fajla za pisanje:\n");
  fgets(naziv, 90, stdin);
  naziv[strlen(naziv) - 1] = '\0';

  FILE* fpO = fopen(naziv, "w");//Priprema fajla za pisanje

  for (int i = 0; i < n; i++)
  {
  //fprintf() je funkcija u C-u koja služi za ispis formatiranog teksta u fajl
    fprintf(fpO,"%s %s %d", niz[i].ime,niz[i].prezime,niz[i].tezina);
  }
  
  fclose(fpI);
  fclose(fpO);
}
///////////////////////////// RAD SA LISTAMA //////////////////////////////////////////////////////
/*
-NIZ:
int niz[100] => niz je staticka struktura, kolko mesta stavim tolko ce i biti
niz[i] -> *(niz + i) => pristupanje elementu u nizu

-LISTA:
(To je struktura podataka gde su elementi povezani pokazivačima)
1.Dinamicka struktura podataka!(ako imam 10 elemenata u listi ja nju mogu veoma lako da prosirim na vise elemenata)
2.head -> e1 -> e2 -> ... -> en
3.Moramo da zauzmemo odredjenu kolicinu memorije za svaki od elemenata

4.malloc - zauzima prosledjenu kolicinu memorije
5.calloc - zauzima prosledjenu kolicinu memorije; resetuje vrednosti na tim lokacijama na podrazumevane(0)
6.realloc - zauzima memoriju; prosiruje/suzava blok memorije;
moze izmestiti lokaciju memorijskog bloka koji je zauzet
==> sve tri f-je vracaju pokazivac na pocetak memorijskog bloka, koji je zauzet
odmostno daju nam prvu memorisku adresu.

7. free - oslobadja memoriju i vraca je operativnom sistemu
*/

/*14.Deklarisati niz celih brojeva, dužine 10, pomoću dinamičke alokacije 
memorije. Zatim proširiti niz za još 10 elemenata. Na kraju osloboditi 
memoriju zauzetu nizom.
*/
void zad14(){
  //u ovom primeru zauzimamo 40 byte memorije
  int *array = malloc(10 * sizeof(int));//zauzmi mi 10 mesta za intidžere
  //int *array = calloc(10, sizeof(int));//calloc resetuje vrednosti na podrazumevane
  array[2] = 3;
  printf("%d", array[2]);
  
  realloc(array, 20 * sizeof(int));
  //argument 1. => koji niz sirimo
  //argument 2. => na koju ga vrednost sirimo

  free(array);//oslobadjam zauzet prostor
}
//15. Rad sa listama

int main(){
  zad12();
  return 0;
}