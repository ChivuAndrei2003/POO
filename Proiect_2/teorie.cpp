#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
//* CERINTE *//
/*
Pentru clasele de la tema precedentă treceți atributele din zona publică a
        clasei în zona private
            .

    În cele trei clase trebuie să implementați destructorii astfel încât să
        ștergeți memoria alocată în HEAP.Implementati
            si constructorul de copiere pentru toate clasele

                Pentru toate atributele trecute acum în zona private a
                    clasei realizați metode de acces la acestea : get -
    eri și set -
    eri.

        Pentru atributele statice realizați funcții statice pentru a oferi acces
            la acestea.

        Realizați două funcții globale care să realizeze anumite prelucrări /
        procesări(la alegere) și să folosească obiecte de tipul claselor
        implementate.Cele două funcții vor fi prietene cu clasele ale căror
        obiecte sunt folosite,
    astfel încât să aibă acces la atributele private
            .

        În funcția main apelați toate metodele și funcțiile
        implementate pentru a le testa.Cu ajutorul get
        -
        erilor să și afișați valorile atributelor.



        important : Inițializarea atributelor constante se
                    realizează doar prin lista de inițializări a

                    atributele statistice se definesc cu "::" in zona globala

                    fct
        -
        iile statice au acces doar la atributele statice ale clasei Apelarea
            funcțiilor statice se face prin numele funcției și operatorul de
            rezoluție : “::”:

    destructorul are ca rol eliberarea de memorie
    /
    dezalocari din heap destructor : ~Laptop() {}

Metode accesor : get()-- permite acces pt citire si set() pt scriere /
                 modificare si sunt declarati in zona publica a clasei pentru a
                 permite accesul din afara clasei la atributele private.

                 Constructor de copiere :

class Clasa {
public:
  char *pointer;
  int atribut;
};

void main(){
  Clasa c1;
  c1.pointer =
      new char[strlen("text") + 1]; // alocă dinamic în memorie un array de 5
                                    // caractere(ultimul e "\0")
  strcpy(c1.pointer,
         "text"); // copiem in c1.pointer string-ul "text" dupa alocare
  c1.atribut = 10;

  Clasa c2 = c1;
  strcpy(c2.pointer, "newT");

  cout << c1.pointer;
}
/*
##Supraîncărcare operator=

    Rolul operatorului = este să copieze un obiect sursă într -
    un obiect destinație.

    Operatorul = nu construiește un obiect nou,
                 doar îl modifică pe cel existent
                     .

                 se realizeaza prin intermed.unei metod.in zona publica a clasei
*/
/*
Class operator=(const Clasa &c) {
  if (this->pointer != nullptr) {
    delete[] this->pointer;
  }
  this->pointer = new char[strlen(c.pointer) + 1];
  strcpy(this->pointer, c.pointer);
  this->atribut = c.atribut;
  return *this;
}

Clasa c2;
c2 = c1;
*/
/*
Clasele
incluse(nested classes) sunt clasele care sunt declarate în interiorul altor
    clase(outter classes)
        .

    Pentru a utiliza clasa inclusă trebuie să folosim operatorul de rezoluție
    : ”::” și să specificăm și clasa părinte.
    */
/*
Atributul friend :

    Poate fi folosit pentru clase sau funcții exterioare clasei,
    astfel avem :
• Funcții prietene;
• Clase prietene
        .

    permite accesul din afara clasei la zona privata a clasei deoarece se
        realizeaza o leg.de prietenie intre functia /
    clasa declarata si clasa care declara 

class Laptop {
private:
  int RAM;
  string tipCPU;
  float rezolutieEcran;
  bool cameraWeb;
  int nrTaste;
  int*nrApasaritaste;

public:
  Laptop() {
    RAM = 16;
    tipCPU = "AMD";
    rezolutieEcran = 13.3;
    this->cameraWeb = true;
    nrTaste = 0;
    //nrApasaritaste = NULL;

    

 }
  
  //friend int getRAM()(Laptop l);
  friend class Programator;
  friend ostream& operator<<(ostream &oStream, Laptop laptop);
  friend istream &operator>>(istream &iStream, Laptop &laptop);
};

class Programator {
private:
  string nume;
  Laptop laptop;

public:
  bool poateIntraInConferintaVideo() { return this->laptop.cameraWeb; }

  friend void main();
};

void main()
{

  Programator programator;
  cout << (programator.poateIntraInConferintaVideo() ? "Are video" : "Nu are video");

  // Relația de prietenie nu este tranzitivă(prietenul prietenului nu ti-e
  // prieten)

  programator.nume = "Popescu";
 // programator.laptop.cameraWeb; // EROARE - laptop.cameraWeb e inaccesibil

  // relatia de prietenie nu se mosteneste
}
/*
Supraincarcare operatori :

    Operatorii sunt funcții normale care au numele compus din cuvântul cheie
”operator” și simbolul operatorului respectiv.

      Exemple : operator+,
  operator=, operator<<,
      etc.

      Operatorii pot fi supraîncărcați prin funcții globale sau prin funcții
      membre(metode)
          .
  • Obligatoriu prin funcții globale : new și delete.
  • Obligatoriu prin funcții membre : (),
      [], -> , =
  • Pentru restul operatorilor alegerea aparține programatorului.
  */

/*Capitolul 06 -
OPERATORI */
/*
-Pentru fiecare operator pot exista mai multe forme (POLIMORFISM).
• cin este un obiect de tipul istream&
• cout este un obiect de tipul ostream&

//operatori << si >>


 ostream& operator<<(ostream& oStream, Laptop laptop){
  oStream << laptop.getID() << " " << laptop.getRAM() << " " << laptop.getTipCPU() << " ";
  oStream << laptop.getNrTaste() << " " << laptop.getRezolutieEcran() << " " << "cu nr de apasari: ";
  for (int i = 0;i<laptop.nrTaste();i++){
    oStream << laptop.getNrApasariTaste()[i];
  }
}

friend istream& operator>>(istream& iStream, Laptop& laptop) {
    cout << "RAM:";
    iStream >> laptop.RAM;
    cout << "Tip CPU:";
    iStream >> laptop.tipCPU;
    cout << "Rezolutie:";
    iStream >> laptop.rezolutieEcran;
    cout << "Numar taste:";
    iStream >> laptop.nrTaste;
    if (laptop.nrApasariTasta != NULL) {
        delete[] laptop.nrApasariTasta;
    }
    laptop.nrApasariTasta = new int[laptop.nrTaste];
    for (int i = 0; i < laptop.nrTaste; i++) {
        cout << "Numarul de apasari pentru tasta " << (i + 1) << ":";
        iStream >> laptop.nrApasariTasta[i];
    }
    return iStream;
};
/*
Deoarece cei doi operatori se află în afara clasei, nu avem acces la zona
privată a clasei.
• Pentru a putea afișa valorile atributelor din zona privată, ne folosim de
get-eri, iar pentru a modifica ne folosim de set-eri.
• O altă posibilitate este să declarăm aceste funcții ca funcții prietene, și în
acest mod avem acces la zona privată.*/