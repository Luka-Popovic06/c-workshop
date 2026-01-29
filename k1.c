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
/*
25/26
k1 g-4
6.

//pom(x , min, max)
1.Cifre koje su u intervalu min <= c <= max (stavlja na pocetak broja)
2.Ostale cifre idu odmah iza njih
[2, 4]
4 8 2 3 6 1 ====> 4 2 3 8 6 1
u = 423
i = 861
*/
void zad06(int x, int min, int max){
  int c_unutra = 0;
  int c_izvan = 0;
  int res = 0;
  int stepen1 = 0;
  int stepen2 = 0;
  int stepen = 0;
  int rezultat = 0;
  while (x > 0)
  {
    int c = x % 10;
    if((c >= min) && (c <= max)){
      c_unutra += c * pow(10,stepen1);
      stepen1++;
    }else{
      c_izvan += c * pow(10,stepen2);
      stepen2++;
    }
    x/=10;
  }
  printf("%d unutra\n", c_unutra);
  printf("%d izvan \n", c_izvan);
  
  while (c_izvan > 0)
  {
    rezultat += (c_izvan % 10) * pow(10,stepen);
    stepen++;
    c_izvan/=10;
  }
  while (c_unutra > 0)
  {
    rezultat +=(c_unutra % 10) * pow(10,stepen);
    stepen++;
    c_unutra/=10;
  }
  printf("%d \n", rezultat);
}
/*
25/26
k1 g-6
7.
1.Harmonijska srednina cifara broja x (razlicitih od 0):
n - broj koji korisnik unosi
a1...an === cifre broja
n / ((1 / a1) + ... + (1 / an));
 */
double harmonijska_sredina(int n){
  double brojilac = 0;// broji koliko cifara ima broj
  double imenilac = 0;

  while (n > 0)
  {
    int c = n % 10;
    if(c != 0){//nesme neki br da se deli sa nulom puca kod
      imenilac += 1.0 / c;
      brojilac++;
    }

    n /= 10;
  }

  if(brojilac == 0) return 0;//nesme neki br da se deli sa nulom puca kod

  return brojilac / imenilac;
}
int prirodan_br_n_je_poseban(int br){
    double h = harmonijska_sredina(br);

    int k = 0; //broj cifara
    int tmp = br; // kopija br-a

    while(tmp){// broji cifre
        k++;
        tmp /= 10;
    }

    int desno = (k + 1) / 2;// dobijanje desne strane
    int i = 0;

    while(br > 0){
        int c = br % 10;

        if(i < desno){
            // desna polovina
            if(c >= h) return 0;
        }else{
            // leva polovina
            if(c < h) return 0;
        }

        br /= 10;
        i++;
    }

    return 1;
}


void zad07(int a, int b){
  for (int i = a; i <= b; i++)
  {
    if(prirodan_br_n_je_poseban(i) == 1){
      printf("%.3f %d\n", harmonijska_sredina(i), i);
    }
  }
  
}
/////////////////////////////////////////////////////////////////////////////////////////////
/// Rad sa Karakterima: ///

// 'A' < 'a'
//('a' - 'A') = 32
/* 
===> RAD SA BROJEVIMA:

1.Da bi se dobijo neki broj:
char '0' - char 'br' ==> broj

2.Da se dobije char 'br':
char '0' + br = char 'br'

===> RAD SA SLOVIMA:

1.Prebacivanje iz Velikog u Malo slovo:
char 'slovo.Veliko' + ('a' - 'A') ==> slovo.Malo

2.Prebacivanje iz Malog u Veliko slovo:
char 'slovo.Malo' - ('a' - 'A') ==> slovo.Veliko

* char ch; ==> adresa na koju se sprema karakter
* getchar() ==> Uzima jedan karakter sa tastature
* putchar(ch) ==> ispisuje jedan karakter na ekran

*/
//TEST ZADATAK:
void testZad(){
  char ch;
  while ((ch = getchar()) != '\n')
  {
    if(ch == ' '){
      putchar('_');
    }else if(ch <= 'Z' && ch >= 'A'){
      putchar(ch + ('a' - 'A'));
    }else{
      putchar(ch);
    }
  }
  
}
/*
25/26
K1 G-1 ==> char zad = 1
8.

-Napisati funkciju char pom(char malo_slovo, int dodatak)
==>Povecava malo_slovo za dodatak sve dok rezultat ne izade iz opsega malih slova.
==>Vratiti poslednje malo slovo pre izlaska iz opsega.
=>Parametru (dodatak) nadje broj 0, vratiti karakter sa ASCII vrednoscu 0.

-Glavni program
1.Ucitavamo:
==> c - char
==> dva broja (a,b) ==> (a < b)
==> dav char-a (m, n)

-Plan:
==>Pom se poziva nad:
-char c == malo_slovo 
-int dodatak br. iz intervala [a,b]
===> Taj rezultat treba da se nalazi izmedju char [m,n]
=>Ako se nalazi ispisi ga
*/

char pom02(char malo_slovo, int dodatak){
  if(dodatak == 0) return 0;//karakter sa ascii vrednoscu 0 // vrednost nekog karaktera je dec. broj

  char poslednje_malo_slovo = ' ';
  while (malo_slovo<= 'z' && malo_slovo>='a')
  {
    poslednje_malo_slovo = malo_slovo;
    malo_slovo+= dodatak;
  }
  return poslednje_malo_slovo;
}

void zad08(){
  char c, m, n;
  int a, b;

  printf("Unesite malo slovo:\n");
  scanf(" %c", &c);//Razmak ispred %c preskače whitespace (\n, space, tab).

  printf("Unesite prvi karakter:\n");
  scanf(" %c", &m);//Razmak ispred %c preskače whitespace (\n, space, tab).

  printf("Unesite drugi karakter:\n");
  scanf(" %c", &n);//Razmak ispred %c preskače whitespace (\n, space, tab).

  printf("Unesite interval:\n");
  scanf("%d %d", &a, &b);

  for (int i = a; i <= b; i++)
  {
    if(m <= pom02(c,i) && n >= pom02(c,i)){
      printf("%c ", pom02(c,i));
    }
  }
  
}
/*
25/26
K1 G-5 ==> char zad = 2
9.

-Napisati program koji obraduje ulaznu sekvencu simbola na sledeci nacin:
-Uslove:
1.Kada naide na simbol ^, prvo naredno slovo pretvara u veliko.

2.Ako je odmah posle simbola ^ broj k, prvih narednih k slova (ili manje ako ih nema k) pretvara u
velika:
-Prekida se kad naidje na (sve sto nije slovo)

3.Analogno, ako naide na simbol _, prvo naredno ili prvih k narednih slova pretvara u mala.
-Prekida se kad naidje na (sve sto nije slovo)

4.Specijalni simboli ^ i _ i broj k se ne ispisuju.
5.Nova Operacija je jaca od Stare Operacije (stara se prekida)
6.Tekst se zavrsava praznim redom ('\n');

*/
void zad09(){
  char c;
  int veliko_slovo = 0;
  int malo_slovo = 0;
  int brojac_velikih_slova = 0;
  int brojac_malih_slova = 0;
  while ((c = getchar()) != '\n')
  {
    if(c == ' ' || c == ','){
      putchar(c);
    }
    if(c == '^'){//ako je simbol ^ setujem velicinu slova
      veliko_slovo = 1;
      malo_slovo = 0;
    }else if(veliko_slovo == 1){//ako je setovana velicina slova na veliko
      if(c <= '9' && c >= '0'){//ispitujem da li ima br posle simbola ^
        brojac_velikih_slova = (c -'0')-1;
      }else{
      putchar(c - ('a' - 'A'));
      veliko_slovo = 0;
      }
    }else if(c == '_'){
      malo_slovo = 1;
      veliko_slovo = 0;
    }else if(malo_slovo == 1){
      if(c <= '9' && c >= '0'){
        brojac_malih_slova = (c -'0') - 1;
        
      }else{
      putchar(c + ('a' - 'A'));
      malo_slovo = 0;
      }
    }else if(brojac_velikih_slova != 0){
      brojac_malih_slova = 0;
      if(c > '9' || c < '0'){//ovo je da se uverimo da smo ponovo na karakteru
       if(c >= 'a' && c<= 'z'){
         brojac_velikih_slova--;
         putchar(c - ('a' - 'A'));
        }
      }
    }else if(brojac_malih_slova != 0){
      brojac_velikih_slova = 0;
      if(c > '9' || c < '0'){
        if(c>= 'A' && c<= 'Z'){
          brojac_malih_slova--;
          putchar(c + ('a' - 'A'));
        }
      }
    }else{
      putchar(c);
    }
  }
}
/*
25/26
K1 G-6 ==> char zad = 2
10.

1.Svaki neparan red predstavlja modifikacije koje treba napraviti u narednom redu
2.U parnim redovima je tekst koji treba modifikovati

3. @ praceno br. predstavlja -redni broj reci- koju treba izmeniti
4. * pracen br. predstavlja -broj slova- od kog krece izmena
5. + pracen br. predstavlja (umnozavanje datog slova k. puta)
6. - pracen br. predstavlja (zamenu narednih k. slova sa ?)

7.Unos se zavrsava praznim neparnim redom.

Unosi se:
1.Simbol i broj(k)
2.Text


//////////////////////////////////////////////
Ovako se testira da li je prazan red:!!!!!!!

c = getchar();
if (c == '\n') break;

////////////////////////////////////////////
*/

void zad10() {
    char s, c;
    int broj_reda = 1;

    while (1) {//Ovo je beskonačna petlja, koja se prekida samo kad korisnik unese prazan neparan red
        int redni_broj_reci = 1;
        int redni_broj_slova = 1;
        int broj_umnozavanja = 0;
        int broj_zamena = 0;
        char op = 0;//operator

        /* ===== NEPARAN RED (komanda) ===== */
        s = getchar();
        if (s == '\n') break;  // prazan neparan red -> kraj

        while (s != '\n') {
            if (s == '@' || s == '*' || s == '+' || s == '-') {
                char type = s;
                int num = 0;

                // čitaj broj posle simbola
                s = getchar();
                while (s >= '0' && s <= '9') {//ide dok char != broju
                    num = num * 10 + (s - '0');
                    s = getchar();//dodajemo novi char (ako je br. petlja se nastavlja a ako nije prekida se)
                }
                if (num == 0) num = 1;//ako se num ne promeni setujemo ga na 1 po defaultu

                //u zavisnosti od type setujemo num
                if (type == '@') redni_broj_reci = num;
                else if (type == '*') redni_broj_slova = num;
                else {
                    op = type;
                    if (type == '+') broj_umnozavanja = num;
                    else broj_zamena = num;
                }
            } else {
              //ako nije nista samo spremi karakter
                s = getchar();
            }
        }

        /* ===== PARAN RED (tekst) ===== */
        int brojac_reci = 1;
        int brojac_slova = 0;
        int skip = 0;

        while ((c = getchar()) != '\n') {
            if (skip > 0) {
                putchar('?');
                skip--;
                continue;
            }

            if (c == ' ') {
                brojac_reci++;
                brojac_slova = 0;
                putchar(c);
                continue;
            }

            brojac_slova++;

            if (brojac_reci == redni_broj_reci && brojac_slova == redni_broj_slova) {
                if (op == '+') {
                    for (int i = 0; i < broj_umnozavanja; i++)
                        putchar(c);
                } else if (op == '-') {
                    putchar('?');
                    skip = broj_zamena - 1;
                } else {
                    putchar(c);
                }
            } else {
                putchar(c);
            }
        }

        putchar('\n');
        broj_reda++;
    }
}
/*
Imamo dva dela zad:

1.Prvi deo je bitan samo zbog komandi njega ne mozemo da sacuvamo pa zato 
komande smestamo u pomocne promenljive.(POSEBNA PETLJA)
2.Drugi deo je bitan i njega citamo karakter po karakter i u zavisnostio od  
komandi ga modifikujemo(POSEBNA PETLJA)
3.Najbitnije na papiru ispisati sve slucajeve

4.Ovo sve je stavljeno u veliku petlju koja je beskonacna dok ne dodje do
 if-a koji ima u sebi uslov ako je uslov ispunjen beskonacna petlja puca

5.Šema zadatka:

while(bitna zbog brojanja redova){
1.while(bitan zbog setovanja uslova)
2.while(bitan zbog primene uslova na tekstu)
}
*/

///////////////////////////////////////////////////////////////////////////////////////////////////////
/*
////////////////////////////// -  DOKAZIVANJE TEOREME - ////////////////////////////////////
25/26
K1 G-6 ==>  zad = 3
11.

1.Program ucitava m i n 
2.Pravim interval [m,n]
3.(a > b) (b > c) (a + b >= 2 * b)
4. a > b > c
5.Ukoliko teorema vazi, ispisujemo("Teorema vazi")
6.Ukoliko ne vazi:
-ispisujemo ("Teorema ne vazi")
-i ispisujemo sve trojke (a,b,c) za koje ne vazi
 */
int teorema(int a, int b, int c) {
    if (a > b && b > c && (a + c >= 2 * b))
        return 1;
    else
        return 0;
}
 void zad11(){
  int m,n;
  printf("Unesite m i n:\n");
  scanf("%d %d", &m,&n);
  int ne_vazi = 1;
  for (int a = m; a <= n; a++)// a <= n bitni su uslovi
  {
    for (int b = m; b < a; b++)// b < a
    {
      for (int c = m; c < b; c++)// c < b
      {
        if(teorema(a,b,c) == 0 && ne_vazi == 1){
          printf("Teorema NE vazi\n");
          ne_vazi = 0;
        }
        if(ne_vazi == 0 && teorema(a,b,c) == 0){
          printf("(%d,%d,%d)\n", a, b, c);
        }
      }
    }
  }
  if(ne_vazi == 1){
    printf("Teorema vazi\n");
  }
 }
 /*
 25/26
K1 G-5 ==>  zad = 3
12.

-Ucitavamo dva broja m i n
-Pravimo interval [m,n]
-(a < b) (a < c) (b <= c)    a < b <= c

====>Ako je a najvece (a > b > c) onda poredimo parametre u for-u redom kako je navedeno u zadatku
[m, parametar(b ili c)]
====>Ako je a najmanje (a < b < c) onda poredimo parametre u for-u sa 
[m,n]
-I u tom slucaju ubacujemo u poslednji for uslov if(prva dva uslova iz teoreme);
 */
int tester_teoreme(int a,int b, int c){
  if(a < b && a < c && b <= c) return 1;
  else return 0;
}


void zad12(){
  int m,n;
  scanf("%d %d", &m, &n);
  int t_tacna = 1;

  for (int c = m; c <= n; c++)
  {
    for (int b = m; b <= n; b++)
    {
      for (int a = m; a <= n; a++)
      {
        if(a < b && a < c){           // proveravamo samo relevantne trojke
            if(!tester_teoreme(a,b,c)){
                if(t_tacna){
                    printf("Teorema nije tacna\n");
                    t_tacna = 0;
                  }
                    printf("(%d,%d,%d)\n", a, b, c);
              }
      }
    }
  }
}
if(t_tacna){
    printf("Teorema je tacna\n");
  }
}
int main(){
  zad12();
  return 0;
}