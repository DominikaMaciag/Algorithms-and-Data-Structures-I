#include <stdio.h>
#include <Windows.h>
#include <iostream>
typedef int Telement; 

struct Node {
    Telement info; 
    Node * left; //wskaźnik do lewego dziecka
    Node * right;
};
typedef Node *PNode; //PNode to wskaźnik na node	

class BinaryTree {
    protected:
    PNode T;
    public:
    BinaryTree();
    ~BinaryTree();
    PNode PARENT(PNode n);
    PNode PARENT1(PNode n,PNode T);
    PNode LEFT_CHILD(PNode n); //
    PNode RIGHT_CHILD(PNode n); //
    Telement GetLabel(PNode n); //
    PNode BuildTree1(int m); //m- ilość węzłów
    void BuildTree(int m); //
    PNode ROOT(); //
    void MAKENULL(PNode p);
    void PreOrder(PNode t); //
    void InOrder(PNode t); //
    void PostOrder(PNode t); //
};

//konstruktor tworzy puste drzewo
BinaryTree::BinaryTree(){
    T=NULL;
}

//Chcemy stworzyć drzewo: 1,2,3,4,5,6,7,8,9
void BinaryTree::BuildTree(int m){
    T=BuildTree1(m);
}

//tworzymy nowy węzeł-korzeń podajemy wartość, rekurencyjnie lewe prawe dziecko
PNode BinaryTree::BuildTree1(int m){
    if(m==0) return NULL;
    else {
        PNode k = new Node;//tworzymy korzeń czyli po prostu pierwszy node
        k->left = BuildTree1(m/2); //zbuduj lewe poddrzewo z m/2 węzłami
        k->right = BuildTree1(m-(m/2)-1); //zbuduj lewe poddrzewo z m-(m/2)-1 węzłami
        return k;

    }
    
}

void BinaryTree::PreOrder(PNode n){   
	if(n!= NULL){
		std::cout<<n->info<< ", ";
		PreOrder(n->left);
		PreOrder(n->right);
	}
}

void BinaryTree::InOrder(PNode n){
	if(n!= NULL){
		InOrder(n->left);
		std::cout<<n->info<< ", ";
		InOrder(n->right);
	}
}

void BinaryTree::PostOrder(PNode n){
	if(n!= NULL){
		PostOrder(n->left);
		PostOrder(n->right);
		std::cout<<n->info<<  ", ";	
	}
}

//zwraca etykietę węzła n
Telement BinaryTree::GetLabel(PNode n){
    std::cout<<n->info<< std::endl;
    return n->info;
}

//zwraca węzeł, który jest korzeniem lub NULL jeśli drzewo jest puste
PNode BinaryTree::ROOT(){
        return T; //zwraca korzeń ???
}

//zwraca lewe dziecko węzła n
PNode BinaryTree::LEFT_CHILD(PNode n){
    return n->left;
}

//zwraca prawe dziecko węzła n
PNode BinaryTree::RIGHT_CHILD(PNode n){
    return n->right;
}

PNode BinaryTree::PARENT(PNode n){
    if(n==T){ //jeśli n jest korzeniem
        return NULL;
    }
    else{
        return PARENT1(n,T);
    }
}

//szuka rodzica węzła n w poddrzewie T, sprawdza czy n jest lewym lub prawym dzieckiem T
PNode BinaryTree::PARENT1(PNode n, PNode T){
    if(T==NULL){
        return NULL;
    }

    if(T->left==n || T->right==n){
        return T;
    }

    else{
        PNode tmp = PARENT1(n,T->left);
        if(tmp!=NULL){
            return tmp;
        }
        else{
            tmp = PARENT1(n,T->right);
            if(tmp!=NULL){
                return tmp;
            }
            else { 
                return NULL;
            }
        }
        return NULL;
    }
}

//zwalnia pamięć zajętą przez poddrzewo o korzeniu p
void BinaryTree::MAKENULL(PNode p){
    if(p!= NULL){
		MAKENULL(p->left);
		MAKENULL(p->right);
		delete p;		
	}
}

//destruktor wywołuje makenull od T
BinaryTree::~BinaryTree(){
    MAKENULL(T);
}

int main(){
    BinaryTree t;
    t.BuildTree(9);
    t.ROOT()->info=1;
    t.ROOT()->left->info=2;
    t.ROOT()->right->info=6;
    t.ROOT()->left->left->info=3;
    t.ROOT()->left->left->left->info=4;
    t.ROOT()->left->right->info=5;
    t.ROOT()->right->left->info=7;
    t.ROOT()->right->left->left->info=8;
    t.ROOT()->right->right->info=9;

    std::cout<<"root: " << t.ROOT()->info<<std::endl;
    std::cout<<"prawe dziecko korzenia: " << t.ROOT()->right->info<<std::endl;
    std::cout<<"lewe dziecko korzenia: " << t.ROOT()->left->info<<std::endl;
    //Wypisać wartość węzła, który jest rodzicem węzła będącego prawym dzieckiem korzenia
    std::cout<<"rodzic noda bedacego prawym dzieckiem korzenia ma wartosc:" << t.PARENT(t.ROOT()->right)->info<<std::endl;
    //Wypisać wartość węzła, który jest rodzicem węzła będącego prawym dzieckiem lewego dziecka korzenia
    std::cout<<"rodzic noda bedacego prawym dzieckiem lewego dziecka korzenia ma wartosc:" << (t.PARENT(t.RIGHT_CHILD(t.ROOT()->left)))->info<<std::endl;

    std::cout<< "PreOrder: " << std::endl;
    t.PreOrder(t.ROOT());
    std::cout<<std::endl;
    std::cout<< "InOrder: " << std::endl;
    t.InOrder(t.ROOT());
    std::cout<<std::endl;
    std::cout<< "PostOrder: " << std::endl;
    t.PostOrder(t.ROOT());
    std::cout<<std::endl;

    
}

