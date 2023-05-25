#include <stdio.h>
#include <Windows.h>
#include <iostream>

const int maxlegth=20;
typedef int elementtype;
typedef int position;


class Stos {
    protected:
    int S[maxlegth] ;
    position Top;//szczyt stosu
    public:
    Stos();
    void Push(elementtype x);
    void Pop();
    bool Empty();
    elementtype TopElem();
    void Makenul();
}; 

//konstruktor ustawia top na -1
Stos::Stos(){
    Top = -1;
}

//Push - Umieść element x na wierzchołku stosu S
//PUSH – sprawdzamy, czy jest miejsce w tablicy, jeśli jest, wstawiamy element na szczyt stosu, uaktualniając pole TOP
void Stos::Push(elementtype x){
    if(Top<maxlegth-1){
        Top++;
        S[Top]=x;
    }
}

//Pop – Usuń element znajdujący się na wierzchołku stosu
void Stos::Pop(){
    if(Top>=0 && Top<=maxlegth-1){
        Top--;
    }
}

//Empty - zwraca true, jeśli S jest stosem pustym, w przeciwnym razie zwraca false
bool Stos::Empty(){
    if(Top==-1){
        return true;
    }
    else return false;
}

//TopElem - zwróć element znajdujący się na wierzchołku stosu
elementtype Stos::TopElem(){
    return S[Top];
}

//Makenul - uczyń stos pustym
void Stos::Makenul(){
    /*
    for(int i=0; i<=maxlegth; i++){
        Pop();
    } */
    Top=-1;
}


int main(){    
    Stos s;
    s.Empty();
    s.Push(5);
    s.TopElem();
}