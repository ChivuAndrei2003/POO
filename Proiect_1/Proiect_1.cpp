#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

// Chivu Evelyn Andrei
/// domeniu - cafenea
class Cafea {
public:
  string origine;
  static int totalSortimente;
  const int codProdus;
  float *scorAromatica;

  // init. parametru default
  Cafea() : origine("Etiopia") {
    cout << "Cafeaua isi are originea in : " << origine << endl;
  }
  Cafea(  int totalSortimente,int codProdus) {
    
  }
  static void Cafea(*scorAromatica) {
    
  }
};

class Angajat {
public:
  string nume;
  static int salariuMinim;
  const int idAngajat;
  double *orePeSaptamana;

  Angajat(string nume ) {}
  Angajat() {}
  Angajat() {}
};

class Espressor {
public:
  string marca;
  static int totalEspresoareActive;
  const int tensiuneStandard;
  int *cicluriService;

  Espressor() {}
  Espressor() {}
  Espressor() {}
};

int main() {}

/*


int main(){

    Book firstBook;
    firstBook.title = "Matilda";
    firstBook.author = "Roald Dahl";
    firstBook.year = 1988;

    Book secondBook;
    secondBook.title = "The Giving Tree";
    secondBook.author = "Shel Silverstein";
    secondBook.year = 1964;

    cout << firstBook.title << " " << firstBook.author << " " <<
firstBook.year<<"\n"; cout << secondBook.title << " " << secondBook.author << "
" << secondBook.year<<"\n";
} */