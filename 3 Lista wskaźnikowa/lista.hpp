
struct celltype {
int element = -1;
celltype * next = nullptr;
};

class Lista
{
private:
    void Dealocate(celltype* p);

protected :
celltype * head; // wskaźnik do głowy listy
public:
Lista(); //konstruktor
~Lista(); //destruktor
void Insert(int x, celltype * p);
void Add(int x);
void Delete(celltype * p);
int Retrieve(celltype * p);
celltype* Locate(int x);
celltype* First();
celltype* Next(celltype * p);
celltype* Previous(celltype * p);
celltype* END();

void Debug_print();
};
