class Lista

{protected :

  position l;//wskaźnik do głowy listy

public:

  void Insert(elementtype x, position p);

  void Delete(position p);

  elementtype Retrieve(position p);

  position Locate(elementtype x);

  position First();

  position Next(position p);

  position Previous(position p);

  position END();

};

int main(){
    Lista* s = new Lista;


    //TOP: 
    tmp = celltype*; 
    tmp = s.First;
    s.Retrive(tmp); 

    //POP: 
    s.Delete(l);

    //Push:   -umieść element x na wierzchołku stosu S
    s.Insert(x,l)


}