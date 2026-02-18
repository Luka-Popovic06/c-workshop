#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
///////////////////////// BINARNO STABLO PRETRAGE ///////////////////////////////
//1.PRVI ELEMENT NIJE VISE HEAD => ROOT;
//2.Čvorovi koji neamju ni levog ni desnog potomka nazivaju se listovi;
//3. LEVA str. => MANJI ; DESNA str. => VĆI el.
//4.Dvostruki pokazivac je ==> adresa adrese
//kad koristimo ovo povratni tip je VOID
//i tamo gde pozivamo f-ju nam nije potrebno bst = f-ja

//DVOSTRUKI POKAZIVAC IDE KAD SE RADI DIREKTNO SA ADRESOM (NE VRACAMO NISTA)
//Jednostruki ide kada vracamo nesto ne radimo direktno sa stablom

//1.Pravimo strukturu cvora(Node-a)
//struct Node* ==> je deklaracija
typedef struct Node{
  int data;
  struct Node* left;
  struct Node* right;
}Node;

//2.Pravimo f-ju za pravljenje cvora:
Node* createNode(int data){

  Node* new = calloc(1,sizeof(Node));

  new->data = data;

  return new;
}

//KRECE REKURZIJA:
//Rekurzija mora da ima trivijalan slucaj
//3.Ubacivanje elementa(Node) u stablo

Node* insertNodeR(Node* root, int data){

  if(root == NULL){
    return createNode(data);//posto je rekurzija ovde se poziva createNode
  }else if(root->data > data){//left side
    root->left = insertNodeR(root->left,data);
  }else{//right side
    root->right = insertNodeR(root->right, data);
  }

  return root;
}

void inserNodeDPR(Node** root, int data){
  if(*root == NULL){
    *root = createNode(data);//UMESTO returna ==> *root
    return;
  }
  if((*root)->data > data){//left side
    inserNodeDPR(&(*root)->left,data);
  }else{//right side
    inserNodeDPR(&(*root)->right,data);
  }
}
//4.Ispisivanje stabla (Prolazak kroz stablo):
//a)Inorder prolazak (sortira elemente od najmanjeg ka najvecem);LPS->ROOT->DPS
void inorder(Node** root){
  if(*root == NULL) return;

  inorder(&(*root)->left);
  printf("%d ", (*root)->data);
  inorder(&(*root)->right);

}
//b)Preorder prolazak (koren na pocetku)==> vrednost korena na pocetku
void preorder(Node** root){
  if(*root == NULL) return;

  printf("%d ", (*root)->data);
  preorder(&(*root)->left);
  preorder(&(*root)->right);
}
//v)Postorder prolazak (koren na kraju)==>vrednost od root-a na kraju
void postorder(Node** root){
  if(root == NULL) return;
  postorder(&(*root)->left);
  postorder(&(*root)->right);
  printf("%d ", (*root)->data);
}
//5.Trazenje cvora(Node-a):
Node* findNodeR(Node* root, int data){
  if (root == NULL){
    return NULL;
  }
  
  if(root->data == data){
    return root;
  }

  if(root->data > data){
    return findNodeR(root->left,data);
  }else{
    return findNodeR(root->right,data);
  }

}
//6.Trazenje MIN-a i MAX-a
//Trazenje MIN-a:
Node* findMin(Node* root){
  while (root->left != NULL)
  {
    root = root->left;
  }
  return root;
}
//TRAZIMO MAX-a:
Node* findMax(Node* root){
  while (root->right != NULL)
  {
    root = root->right;
  }
  return root;
}
//7.Brisanje cvora(Node-a):

void deleteNodeDPR(Node** root, int data){
  //1.Prvi slucaj(opšti slucaj) ako je stablo prazno:
  if(*root == NULL) return;

  //2.Slucaj(trazimo cvor, koji zelimo da obrisemo):

  if(data < (*root)->data){//left side
    deleteNodeDPR(&(*root)->left,data);
  }else if(data > (*root)->data){//right side
    deleteNodeDPR((*root)->right, data);
  }else{//3.Slucaj: kad se nadje cvor(Node); // root->data == data
    //Imaju 3 situacije;
    //U prva dva slucaja vrsimo samo prekacivanje
    Node* tmp;//da pamti root; // i da pomeramo node
    if((*root)->left == NULL){//1.Situacija je kad nemamo levi sledbenik, ali imamo desni
      tmp = (*root)->right;
      free(*root);
      *root = tmp;
    }else if((*root)->right == NULL){//2.Situacija je kad nemamo desni, ali imamo levi sledbenik
      tmp = (*root)->left;
      free(*root);
      *root = tmp;
    }else{//3.Slucaj: (Ima i levog i desnog potomka)
      //simulacija brisanja cvora
      tmp = findMin(&(*root)->right);//spustamo se na prvog desnog pa idemo skroz levo
      //Kopiram vrednost:
      (*root)->data = tmp->data;
      deleteNodeDPR(&(*root)->right, tmp->data);
    }
  }
}
void test(){
  Node* bst = NULL;//root
  int n;
  printf("Unesite broj el. u stablu:\n ");
  scanf("%d", &n);
  int data;
  for (int i = 0; i < n; i++)
  {
    printf("Unesite %d. el.", i);
    scanf("%d", &data);//ne sme da ide "%d "(razmak) => dobijem gresku u kodu
    bst = insertNodeR(bst, data);
  }
  Node* tmp = findNodeR(bst,2);
  if(tmp){//ako je tmp != NULL
  printf("%d \n", tmp->data);
  }
  Node* min = findMin(bst);
  if(min){
    printf("%d\n", min->data);
  }
  inorder(&bst);
}
int main(){
  test();
  return 0;
}