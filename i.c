#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
//1.zadatak
//1.Pravimo prvo strukturu za CVET:
typedef struct Cvet{

  char imeCveta[90];
  int kolicina;
  int cena;

}Cvet;
//2.Pravimo strukturu za Node:
typedef struct Node{

  Cvet data;
  struct Node* left;
  struct Node* right;

}Node;
//3.Pravimo f-ju za kreiranje Node-a
Node* createNode(char* ime, int cena, int kolicina){
  Node* new = calloc(1, sizeof(Node));
  new->data.cena = cena;
  new->data.kolicina = kolicina;
  strcpy(new->data.imeCveta, ime);

  return new;
}
//4.pravimo f-ju za ubacivanje Node-a u stablo
Node* insertNodeR(Node* root, int cena, char *ime,int kolicina){
                                  //ovde ucitavamo string *ime
  Node* new = createNode(ime, cena, kolicina);

  if(root == NULL){
    return new;
  }

  if(cena < root->data.cena){
    root->left = insertNodeR(root->left, cena, ime, kolicina);
  }else{
    root->right = insertNodeR(root->right, cena, ime, kolicina);
  }

  return root;
}
//5.Pravimo f-ju za ispisivanje Node-a u konzolu selektovano po ceni
void inorder(Node** root){
  if(*root == NULL) return;
  
  inorder(&(*root)->left);
  printf("Ime: %s cena: %d  Kolicina: %d\n", (*root)->data.imeCveta,(*root)->data.cena, (*root)->data.kolicina);
  inorder(&(*root)->right);
}
//6.F-ja za ispis ukupnog broja cvetova u cvecari
void totalNumberOfFlowersR(Node** root, int* totalFlowers){
  if(*root == NULL) return;

  totalNumberOfFlowersR(&(*root)->left, totalFlowers);
  *totalFlowers += (*root)->data.kolicina;
  totalNumberOfFlowersR(&(*root)->right, totalFlowers);

}
//7.Brisanje cveta:
//a)Prvo mi treba f-ja za trazenje MINIMUMA:
Node* findMin(Node* root){
  while (root->left)
  {
    root= root->left;
  }
  return root;
}

//b)Drugo sto mi treba je f-ja za brisanje:
void deleteFlower(Node** root, int cena){
  if(*root == NULL) return;

  if(cena < (*root)->data.cena){
    deleteFlower(&(*root)->left,cena);
  }else if(cena > (*root)->data.cena){
    deleteFlower(&(*root)->right, cena);
  }else{//cena == cena
    Node* tmp;

    if((*root)->left == NULL){
      tmp = (*root)->right;
      free(*root);
      *root = tmp;
    }else if((*root)->right == NULL){
      tmp = (*root)->left;
      free(*root);
      *root = tmp;
    }else{
      tmp = findMin((*root)->right);
      (*root)->data = tmp->data;
      deleteFlower(&(*root)->right,tmp->data.cena);
    }
  }
}
//8.BRISANJE CELOG STABLA:

void deleteTreeR(Node* root){
  //ispravan redosled LPS -> DPS -> ROOT
  
  if(root){
  deleteTreeR(root->left);
  deleteTreeR(root->right);
  free(root);
  }
  //*root = Null
}
void zad01(){
  char imeFajla[90];
  printf("Unesite ime fajla:\n");
  fgets(imeFajla, 90, stdin);
  imeFajla[strlen(imeFajla) - 1] = '\0';

  FILE* fp = fopen(imeFajla, "r");

  if(fp == NULL){
    printf("Greska pri radu sa fajlom!!!\n");
    fclose(fp);
    return;
  }
  Node* bst = NULL;
  char red[90];
  char *token;

  while (fgets(red, 90, fp) == red)
  {
    char ime[90];
    int cena;
    int kolicina;

    token = strtok(red, ",");
    strcpy(ime,token);

    token = strtok(NULL,",");
    kolicina = atoi(token);

    token = strtok(NULL,",");
    cena = atoi(token);

    bst = insertNodeR(bst, cena, ime, kolicina);
    //kad prosledjujemo string samo mu stavimo ime, a tamo gde ga ocitavamo stavimo *ime
  }

  inorder(&bst);

  printf("\n");

  int total = 0;
  totalNumberOfFlowersR(&bst,&total);
  printf("Ukupan broj cvetova je: %d\n", total);

  int cena_za_brisanje;
  printf("Unesite cenu koju hocete da obrisem:\n");
  scanf("%d", &cena_za_brisanje);
  deleteFlower(&bst, cena_za_brisanje);

  inorder(&bst);
  printf("\n");
  deleteTreeR(bst);

  fclose(fp);
}
///////////////////////////////////////////////////////////////////////////////////////
//2.zadatak
//kolicnik = deljenje

//1.Praviomo Node
typedef struct Rec{
  char rec[90];
  int brojPojavljivanja;
  float frekvencija;//brojPojavljivanja reci / ukupan br reci
  struct Rec* next;
}Rec;

//2.Pravimo konzolu:
int ispisiMeniPom(){
  int opcija = 0;

  printf("Meni:\n");
  printf("1. Ucitaj datoteku (sortirano alfabetski)\n");
  printf("2. Ispisi sve reci, njihov broj pojavljivanja i frekvenciju.\n");
  printf("3. Ispisi reci po broju pojavljivanja (opadajuce)\n");
  printf("4. Izadji iz programa\n");
  while (opcija < 1 || opcija > 5)
  {
    printf("Izaberite opciju:\n");
    scanf("%d", &opcija);
  }
  
  return opcija;
}

//Sortiranje reci:
/* strcmp => poredi stringove
int strcmp(s1 , s2) > 0 ; s1 > s2
int strcmp(s1 , s2) == 0; s1 == s2
int strcmp(s1, s2) < 0; s1 < s2
*/
/////////////////////////////////Ovogodisnji ispit//////////////////////////////////////////////////
//1.zad MATRICE
//Program treba da formira matricu B istih dimenzija
//za svaki B[i][j] => izraccunava ZBIR SVIH PRANIH brojeva iz vrste i i kolone j
// iz matrice A pri cemu se element A[i][j] ne racuna
//ispisujemo mat B
int parniBr(int br){
  if(br % 2 == 0) return 1;
  else return 0;
}
int formiranjeElementa(int element,int vrsta, int kolona, int n,int a[n][n]){
  int rezultat = 0;
  for (int i = 0; i < n; i++)
  {
    if(parniBr(a[vrsta][i]))
      if(a[vrsta][i] != element)
        rezultat += a[vrsta][i];
  }
  for(int j = 0; j < n; j++){
    if(parniBr(a[j][kolona])){
      if(a[j][kolona] != element){
        rezultat += a[j][kolona];
      }
    }
  }

  return rezultat;
}
void zad03(){
  int N;
  printf("Unesite prirodan br. N\n");
  scanf("%d", &N);
  int a[N][N];
  int b[N][N];
  for (int i = 0; i < N; i++){
    for (int j = 0; j < N; j++){
      printf("Unesite (%d, %d) el. u mat\n", i,j);
      scanf("%d", &a[i][j]);
    }
  }
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      b[i][j] = formiranjeElementa(a[i][j], i, j,N,a);
    }
  }

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      printf("%d ", b[i][j]);
    }
    printf("\n");
  }
  
}
//////stabla
///bitan zadatak 
///Rad sa duplikatima

//1.Pravimo strukturu:
typedef struct Node2{
  char tim[90];
  int domacin;
  int gost;
  struct Node2* left;
  struct Node2* right;
}Node2;

//2.Create node
Node2* createNode2(char *tim,int domacin, int gost){
  Node2 *new = calloc(1, sizeof(Node2));

  strcpy(new->tim,tim);
  new->domacin = domacin;
  new->gost = gost;
  return new;
}
//3.Ubacujemo gosta i domacina
//Node2* ubaciDomacina(Node2* root, )
//3.Ucitavanje fajla:

Node2* ucitaj_fajl(){
  Node2* root = NULL;
  printf("Unesite ime fajla\n");
  char ime[90];
  fgets(ime, 90, stdin);
  FILE* f = fopen(ime, "r");
  if(!f){
    printf("File mistake\n");
    fclose(f);
    return;
  }
  char red[90];
  char tim1[90];
  char tim2[90];
  int gol1;
  int gol2;
  char* token;
  while (fgets(red, sizeof(red), f) == red)
  {
    token = strtok(red,",");
    strcpy(tim1,token);
    token = strtok(NULL,":");
    gol1 = atoi(token);
    token = strtok(NULL,",");
    gol2 = atoi(token);
    token = strtok(NULL,"\n");
    strcpy(tim2, token);
  }
  fclose(f);
  return root;
}

void zad04(){
  int option;
  Node2* root =NULL;
  while (1)
  {
    scanf("%d", &option);
    if(option == 1){
      root = ucitajFajl();
    }else if(option == 2){

    }else if(option == 3){

    }else if(option == 4){

    }else {
      return;
    }
  }
  
}
int main(){
  zad04();
  return 0;
}