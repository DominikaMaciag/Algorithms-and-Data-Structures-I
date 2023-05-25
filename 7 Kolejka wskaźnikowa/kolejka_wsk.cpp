#include <stdio.h>
#include <Windows.h>
#include <iostream>

typedef int elementtype;

struct celltype {
 elementtype element;
 celltype * next;
};

typedef celltype * position;

class Queue {
protected:
 position Front; // wskaźnik do głowy listy
 position Rear; // wskaźnik do ostatniego elementu
public:
 Queue(); //konstruktor
 ~Queue(); //destruktor
 void Enqueue(elementtype x);
 void Dequeue();
 elementtype FrontElem();
 bool Empty();
 };

 //konstruktor - tworzy obiekt oraz głowę, aktualizuje front i rear
 Queue::Queue(){
    celltype* c = new celltype; //tworzymy nową komórkę
    Front=c;
    Rear=c;
    Front->next = nullptr;
 }

 //destruktor - czyni kolejkę pustą
 Queue::~Queue(){
     position tmp=Front;
     while(Front!=Rear){
         tmp = tmp->next;
         //delete Front;
         Dequeue();
     }
 }

 //Enqueue - tworzy nową komórkę, wstawia ją na koniec, uaktualnia rear wskazujący na nową komórkę
 void Queue::Enqueue(elementtype x){
    celltype* c = new celltype; //tworzymy komórkę
    Rear->next=c; // zmieniamy to na co wskazuje ostatni
    c->element=x; //wstawiamy do komórki x
    c->next=nullptr;
    Rear=c; //uaktualniamy rear
 }

 //Dequeue - sprawdza czy kolejka jest pusta, jeśli nie to zapamiętujemy głowę w zamiennej tmp, aktualizujęmy front.., usuwamy z pamięci
 void Queue::Dequeue(){
    position tmp=Front;

    if(Front!=Rear){ //czyli jeśli kolejka nie jest pusta 
        Front = tmp->next; //aktualizujemy front
        delete tmp;
    }
 }

//FrontElem - zwraca pierwszy element z kolejki
elementtype Queue::FrontElem(){
    if(Front!=Rear){
        std::cout<< Front->next->element<< std::endl;
        return Front->next->element;
    }
}

//Empty - zwraca true jeśli pusta, false jeśli nie pusta
bool Queue::Empty(){
    if(Front==Rear){
        printf("true\n");
        return true;
    }
    else {
        printf("false\n");
        return false;
    }
}

int main(){
    Queue q;
    q.Empty();
    q.Enqueue(5);
    q.Empty();
    q.FrontElem();
    q.Dequeue();
    q.Empty(); 
    q.Enqueue(4);
    q.Enqueue(3);
    q.Enqueue(2);
    q.FrontElem();
    q.Enqueue(1);
    q.FrontElem();
    q.Dequeue();
    q.FrontElem();
    q.Enqueue(6);
    q.FrontElem();
    q.Dequeue();
    q.Dequeue();
    q.FrontElem();
    q.Empty();
}

