#include <stdio.h>
#include <Windows.h>
#include <iostream>

const int maxlength=50;
typedef int elementtype;
typedef int position;

class Kolejka {
protected :
elementtype Queue[maxlength];
position Front; // Indeks elementu czołowego
position Rear; // Indeks ostatniego elementu
public:
Kolejka(); //
int AddOne(int i); //
void Enqueue(elementtype x); //
void Dequeue(); //
elementtype FrontElem(); //
void Makenull();
bool Empty(); //
};

//konstruktor 
Kolejka::Kolejka(){
    Front = 0;
    Rear = maxlength-1;
}

//zwiększa o jeden zgodnie z relacją modulo
int Kolejka::AddOne(int i){
 i=(i+1)%maxlength;
 return i;
}

//zwraca true, gdy kolejka jest pusta, w przeciwnym wypadku zwraca false
bool Kolejka::Empty(){
 if((Rear+1)%maxlength==Front){
     printf("%d\n", 1);
     return true;
 }
 
 else {
     printf("%d\n", 0);
     return false;
 }
}

//wstawia element do kolejki na koniec
void Kolejka::Enqueue(elementtype x){
    if(( AddOne(AddOne(Rear)) == Front)){
        printf("Nie ma miejsca!");
    }
    else{
        Queue[(Rear+1)%maxlength]=x;
        Rear=(Rear+1)%maxlength;
    }    
}

//zwraca pierwszy element z kolejki (ten co wyjdzie pierwszy)
elementtype Kolejka::FrontElem(){
    if( (Rear+1)%maxlength!=Front ){
         printf("%d\n", Queue[Front]);
         return Queue[Front];
    }
    
    else {
        printf("%d\n", (elementtype) -1);
        return (elementtype) -1;
    }
}

//usuwa element z początku kolejki
void Kolejka::Dequeue(){
    if( (Rear+1)%maxlength!=Front ){
        Front=(Front+1)%maxlength;
    }
}

// czyni kolejkę pustą
void Kolejka::Makenull(){
    Front=(Rear+1)%maxlength;
}

int main(){
    Kolejka k;
    k.Empty();
    k.Enqueue(5);
    k.Empty();
    k.FrontElem();
    k.Dequeue();
    k.Empty();
    k.Enqueue(4);
    k.Enqueue(3);
    k.Enqueue(2);
    k.FrontElem();
    k.Enqueue(1);
    k.FrontElem();
    k.Dequeue();
    k.FrontElem();
    k.Enqueue(6);
    k.FrontElem();
    k.Dequeue();
    k.Dequeue();
    k.FrontElem();
    k.Makenull();
    k.Empty();
}