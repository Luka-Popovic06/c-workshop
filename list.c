#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
//rad sa listama
//Uvek se vraca head i uvek ide head = f-ja

//1.pravimo Node(struct);kao strukturu podataka
typedef struct Node{
  int data;
  struct Node* next;
}Node;


//2.Pravimo f-ju za kreiranje Nodea;
Node* createNode(int data){

  Node* new = malloc(sizeof(Node));//ovde zauzimamo memoriju za NEW Node

  new->data=data;//Ovde deklarisemo data za Node
  new->next=NULL;//ovde deklarisemo njegovog sledbenika

  return new;//I na kraju ga vratimo
}


//3.Dodavanje Elemenata u listu:

// a) Ubacujemo Node na pocetak liste (obrnut redosled od onog u fajlu):

Node* insertFront(Node* head, int data){
  Node* newNode = createNode(data);//ovde kreiramo cvor

  newNode->next = head;

  return newNode;
}
// b) Ubacujemo Node na kraj liste (redosled kao u fajlu):(!!!!)

Node* insertBack(Node* head, int data){
  Node* newNode = createNode(data);

  if(head == NULL){
    return newNode;
  }

  Node* tmp = head;

  while (tmp->next != NULL)
  {
    tmp = tmp->next;
  }
  tmp->next = newNode;
   
  return head;
}

// v)Sortiranje liste: (ubacivanje el. tako da budu sortirani)
Node* insertSorted(Node* head, int data){
  Node* newNode = createNode(data);

  if(head == NULL){
    return newNode;
  }else if(head->data >= newNode->data){
    newNode->next = head;
    head = newNode;
  }else if(head->data <= newNode->data){
    Node* tmp = head;
                                        //ovo zbog NULL slucaja
     while (newNode->data >= tmp->next->data && tmp->next)
     {
       tmp = tmp->next;//petlja puca na 4
       //4 -> 5
       //5 -> 11
     }
     //2 -> 4 -> 11
     //5
     //prvo prekacinjem 5 da mu je sledbenik 11, a potom ga pozicioniram na lokaciju
     newNode->next = tmp->next;//ovde dodajem sledbenika
     tmp->next = newNode;//ovde ubacujem taj element
  }

  return head;
}


//4.Brisanje iz liste:

 Node* deleteElementInList(Node* head, int data){
  Node* prev = NULL;
  Node* curr = head;

  if(curr->data == data){
    head=curr->next;
    free(curr);
    return head;
  }

  prev = curr;
  curr = curr->next;

  while (curr && curr->data != data)
  {
    prev = curr;
    curr = curr->next;
  }
  
  if(curr){//ako je curr razlicit od NULL, brisemo ga
  prev->next = curr->next;
  free(curr);
  }

  return head;
 }

//5.Brisanje cele liste:
Node* deleteAllList(Node* head){
  while (head)
  {
    Node* tmp = head->next;
    free(head);
    head = tmp;
  }
  return head;
}


//6.Printovanje liste:
void printList(Node* head){
  while (head)//kad dodjemo do NULL petlja puca
  {
    
    printf("%d ", head->data);//iz trenutnog pokazivaca printujemo data-u
    head = head->next;//idemo na sledeci el. u listi
  }
  printf("\n");
}



//Tester programa
void tester(){
  Node* head = NULL;//na pocetku pokazivac je jenak NULL 

  FILE* fp = fopen("ulaz.txt", "r");

  if(fp == NULL){
    printf("Greska pri ucitavanju iz fajla.\n");
    fclose(fp);
    return;
  }
  int data;
  while (fscanf(fp, "%d", &data) > 0)
  {
    head = insertBack(head, data);
  }
  head = deleteAllList(head);
  printList(head);
}
int main(){
  tester();
  return 0;
}