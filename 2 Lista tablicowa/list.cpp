#include <stdio.h>
#include <Windows.h>
#include <iostream>

#include <time.h>       /* time */



typedef int elementtype, position ;
//const int maxlength=10;
const int maxlength=50;
const int MIN=-1;

struct List {
	elementtype elements[maxlength];
     //indeks ostatniego elementu listy
	int last;          
};

position END(List l) { 
    return (l.last)+1;
}

position First(List l) {
    return 0;
}

position Next(position p,List l) {
    //zwraca index nastepnego elementu po p
    if(p>=0 && p<=l.last){
        return p+1;
    }
    else return -1;
}


position Previous(position p,List l) {
    if(p>0 && p<=l.last){
        return p-1;
    }
    else return -1;
}


//zwraca pozycje elementu x w l
position Locate(elementtype x, List l) { 
    for(int i=0; i<=l.last; i++){
        if(l.elements[i]==x){
            return i;
        }
    }
    return END(l);
}

//zwraca element znajdujący się w liście na pozycji p
elementtype Retrieve(position p, List l) {
    if (p>=0 && p<=l.last){
        return l.elements[p];
    }
    else return MIN;
}

bool Insert(int x, position p, List &l){
    if(maxlength == l.last-1) return false;
    if(p<=(l.last+1) && p>=0){
        ///przesun elementy
        for (int i=l.last; i>=p; i--){
            l.elements[i+1]=l.elements[i];
        }

        l.elements[p]=x;
        l.last++;
        return true;
    }
    else return false;
}

void InsertDuplicate(List &l){
    for (int i=0; i<=l.last; i++){
        Insert(l.elements[i*2], i*2+1, l);
    }
}

bool Delete(position p, List &l){
if (p>=0 && p<=l.last){
        for (int i=p; i<l.last; i++){
            l.elements[i]=l.elements[i+1];
        }
        l.last--;
        return 1;
    }
    else return false;
}

void DeleteDuplicate(List &l){
   for(int i=0; i<=l.last; i++){
       for(int j=i+1; j<=l.last; j++){
           if(l.elements[i]==l.elements[j]){
               Delete(j,l);
               j--;
           }
       }
   }
}

void print(List l) {
        position i=First(l);
        while (i!=END(l))
        {
            printf ("  %d,", Retrieve(i,l));
            i=Next(i,l);
        }
        printf("\n");
}

int main(){
    List l;
    l.last=-1;
    srand(time(NULL));
    for (int i=0; i<=20; i++){
        Insert(rand()%5, i, l);
    }
    print (l);
    //InsertDuplicate(l);
    //Insert(3, 4, l);
    //Insert(8, 5, l);

    DeleteDuplicate(l);
    std::cout << "usuwamy: ";
    print (l);

    //Sleep(200000);
}