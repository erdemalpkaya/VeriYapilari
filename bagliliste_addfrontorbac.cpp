
# include <iostream>
using namespace std;

// Biri integer ve digeri float olmak uzere iki data bulunuyor her node' da 

struct Node{
 int accnumber;
 float balance;
 Node *next;
};


/* 
addnode1 fonksiyonu eklemis oldugunuz her datayi linked-list'in onune ekler
Burada dezavantaj olarak siz print yaptiginizda son elemaniniz en onde gorunsede avantaj
olarak buyuk datalarda zaman kazanci saglar cunku linked-list de sona eklediginiz her 
data butun linked list'i bastan sona dolasarak gecer.
sadece addnode1 kullanildiginda listenizi reverse yapacak yani tersine cevirecek bir fonksiyon dada 
bulundurmaniz
*/


void addnode1(Node *& listpointer, int a, float b){

    Node * temp = new Node;
    temp ->accnumber =a;
    temp ->balance =b;
    temp ->next = listpointer;
    listpointer = temp;
}


/* 
addnode2 her eklemeyi listenin sonuna ekler burada yapmaniz gereken sadece 
print fonsiyonu yazip listenizi gormek
*/

void addnode2(Node *& listpointer, int a, float b){
  Node * current= listpointer;
  if(current != NULL){
   while(current->next != NULL){
    current = current-> next;
  }
}

 Node * temp = new Node;
 temp->accnumber =a;
 temp ->balance =b;
 temp ->next = NULL;
  if(current != NULL){ current ->next = temp;
   }else{
    listpointer =temp;
  }
}

// searchnode fonksiyonu ile listede arama yapabilirsiniz
void searchnode(Node *lispointer, int x){
   Node * current = lispointer;
   while(1){
       if(current == NULL){break ;}
       if(current-> accnumber == x){
           cout<<"Find number is"<<" "<< current->balance<<endl;

       }
       current = current->next;
   }

}

/* removenode fonsiyonu birbirini takip eden iterator den olusuyor
birbirlerini takip ederk ilerliyorlar, silinecek deger bulundugunda gerideki(prev)
ondekinin(current) nextine  esitlendikten sonra veri siliniyor
*/

void removenode(Node *& listpointer, int x){
    Node * current = listpointer;
    Node * prev = NULL;
    while(current != NULL){
        if(current->accnumber == x){break;}
        prev = current;
        current = current ->next;
    }
    prev -> next = current ->next;
    cout<< "Deleted number "<< " "<< current->balance<<endl;
     delete current;

}

/*
eger addnode1 kullaniyorsaniz reverse1 fonsiyonuna listeyi basta eklediginiizi once gormek
icin ihtiyaciniz olacak
*/

void reverse1(Node *& listpointer){
    Node *R = NULL;
    Node * current = listpointer;
    while(current != NULL){
        addnode1(R, current->accnumber, current->balance);
        current = current->next;
    }
    delete listpointer;
    listpointer = R;
}



void printnode(Node * listpointer){

    Node * current = listpointer;
    while(1){
        if(current == NULL){ break ;}
        cout<< current->accnumber << "  "<< current->balance<<endl;
        current = current->next;
    }
}


int main (){
    Node * A = NULL;

// Node A da ilk veri integer deger olan accnumber ikinci deger ise float deger olan balance
  addnode1(A, 1, 1.1);   
  addnode1(A,2, 2.2);
  addnode1(A,3, 3.3);
  addnode1(A,4, 4.4);
  addnode1(A,5, 5.5);
  reverse1(A);

  printnode(A);


}
