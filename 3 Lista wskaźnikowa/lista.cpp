#include <iostream>
#include "lista.hpp"

Lista::Lista(){
    head = nullptr;
}

Lista::~Lista(){
    if(head != nullptr){
        Dealocate(head);
    }
}

void Lista::Debug_print(){
    celltype* chead = head;
    while (chead != nullptr)
    {
        std::cout<<chead->element<<" ";
        chead = chead->next;
    }
    std::cout<<"\n";
}

void Lista::Add(int x){
    celltype* c = new celltype;
    c->element = x;
    if(head == nullptr) {
        head = c;
        return;
    }

    c->next=head;
    head = c;
}

void Lista::Dealocate(celltype* p) {
    if(p->next == nullptr)
    {
        delete p;
        return;
    }
    Dealocate(p->next);    
    delete p;
    return;
}

int Lista::Retrieve(celltype* p) {
    if(p = nullptr){
        return -1;
    }
    return p->element;
}

void Lista::Delete(celltype* p){
    celltype* prevcell = Previous(p);
    if(prevcell!=nullptr){
        prevcell->next=p->next;
    }
    else{
        head=head->next;
    }
    delete p;
}

void Lista::Insert(int x, celltype* p){
    celltype* c = new celltype;
    c->element = x;
    celltype* foundcell = Locate(p->element);
    if(foundcell==nullptr){
        return;
    }
    celltype* tmp = foundcell->next;
    foundcell->next = c;
    c->next=tmp;
}

celltype* Lista::END(){
    celltype* c;
    c = head;
    if(head==nullptr){
        return nullptr;
    }
    while (c->next!=nullptr){
        c=c->next;
    }
    return c;
}

celltype* Lista::Previous(celltype* p){
    celltype* c;
    c = head;

    if(head==nullptr){
        return nullptr;
    }

    while (c->next != nullptr){
        if(c->next==p){
            return c;
        }
        c=c->next;
    }
    return nullptr;
}

celltype* Lista::First(){
    return head;
}

celltype* Lista::Next(celltype* p)
{
    if(p = nullptr){
        return nullptr;
    }
    return p->next;
}

celltype* Lista::Locate(int x){

    celltype* c;
    c = head;
    if(head == nullptr){
        return nullptr;
    }

    while(c->next!=nullptr) {
        if (c->element == x ){
            return c;
        }
        else {
           c=c->next;
        }
    }
    return nullptr;

}