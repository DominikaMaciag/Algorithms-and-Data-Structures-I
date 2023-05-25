#include <iostream>
int A[]={5, 4, 1, 2}; // 5 + 4x + x^2 + 2x^3
int B[]={3, 2, 0, 5}; // 3 + 2x + 0 + 5x^3

//int A[]={5, 0, 1}; // 5 + 0 + x^2 
//int B[]={3, 2}; // 3 + 2x 
int n = sizeof(A)/sizeof(A[0]); //3 ilosc elementow w tablicy A
int m = sizeof(B)/sizeof(B[0]); //2 ilosc elementow w tablicy B

class Wielomian{     
    public:
    int *Dodawanie(int A[], int B[],int n, int m);
    int *Odejmowanie(int A[], int B[],int n, int m);
    int *Mnozenie(int A[], int B[], int n, int m);
    int Horner(int wielomian[], int n, int x);
    void Wypisz_wmian(int wielomian[], int n);
};

//// funkcja zwracająca max z dwóch integerów
int max(int n, int m) {
    if(n>m){
        return n;
    }
    else{
        return m;
    }
}

////    FUNKCJA DODAJĄCA DWA WIELOMIANY    ////
int *Wielomian::Dodawanie(int A[], int B[], int n, int m){ //pamietajmy nie mozna bezposrednio zwrocic w c++ tablizy w f-cji dlatego tworzymy wskaźnik do tablicy
    int maxlength = max(n,m);
    int* suma = new int[maxlength];

    for(int i=0; i<n; i++){
        suma[i]=A[i];
    } 

    //dodajemy do elementów pierwszego wielomianu po kolei elementy drugiego
    for(int i=0; i<m; i++){
        suma[i]+=B[i];
    }
    return suma;
}


////    FUNKCJA ODEJMUJĄCA DWA WIELOMIANY    ////
int *Wielomian::Odejmowanie(int A[], int B[], int n, int m){ 
    int maxlength = max(n,m);
    int* roznica = new int[maxlength];
    
    for(int i=0; i<n; i++){
        roznica[i]=A[i];
    }

    //odejmujemy od elementów pierwszego wielomianu po kolei elementy drugiego
    for(int i=0; i<m; i++){
        roznica[i]-=B[i];
    }
    return roznica;
}


////    FUNKCJA MNOŻĄCA DWA WIELOMIANY    ////
int *Wielomian::Mnozenie(int A[], int B[], int n, int m){
    int* iloczyn = new int[n+m-1];

    for(int i = 0 ; i<=n+m-1; i++){
        iloczyn[i] = 0; //aby w tablicy nie były losowe liczby
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            iloczyn[i+j]+=A[i]*B[j];
        }
    }
    return iloczyn;
}


////    ALGORYTM HORNERA    ////
int Wielomian::Horner(int wielomian[], int n, int x){
    int wynik = wielomian[n];

    //obliczamy wartość wielomiany algorytmem Hornera dla podanego x 
    for(int i=n-1; i>=0; i--){
        wynik=wynik*x+wielomian[i];
    }
    return wynik;
}


////    FUNKCJA WYPISUJĄCA WIELOMIAN    ////
void Wielomian::Wypisz_wmian(int wielomian[], int n) {
    
    for (int i=0; i<n; i++) {
       std::cout << wielomian[i];
       if (i != 0)
        std::cout << "x^" << i ;
       if (i != n-1)
       std::cout << " + ";
    }
}

int main(){
    Wielomian w; 

    int *suma = w.Dodawanie(A,B,n,m);
    int *roznica = w.Odejmowanie(A,B,n,m);
    int *iloczyn = w.Mnozenie(A,B, n, m);
    int wynik = w.Horner(A,2,2); //podajemy: wielomian, stopień wielomianu, wartość x

    int maxlength = max(n, m);
    std::cout<<"Dodawanie podanych wielomianow: ";
    w.Wypisz_wmian(suma, maxlength);
    std::cout<<std::endl;

    std::cout<<"Odejmowanie podanych wielomianow: ";
    w.Wypisz_wmian(roznica, maxlength);
    std::cout<<std::endl;


    std::cout<<"Mnozenie podanych wielomianow: ";
    w.Wypisz_wmian(iloczyn, m+n-1);
    std::cout<<std::endl;

    std::cout<<"Wartosc wielomianu: " << wynik <<std::endl;
}