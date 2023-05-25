#include "lista.hpp"
#include <iostream>

int main(){
    Lista a;
   
    a.Add(5);
    std::cout<<"===================\nLIST:";
    a.Debug_print();
    a.Add(2);
    std::cout<<"===================\nLIST:";
    a.Debug_print();

    celltype* tmp;
    tmp = a.Locate(2);
    if(tmp == nullptr){
        std::cout<<"locate error\n";
        return 0;
    }
    a.Insert(1,tmp);
    std::cout<<"===================\nLIST:";
    a.Debug_print();
}