#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

//* C , E , A  *//

// Domeniu ales: Cafenea => cafea,espressor,angajat
class Cafea {
public:
  string origine;
  static int totalSortimente;
  const string brand = "Cafenea Aroma";
  float *scorAromatica;
  int codProdus;

  Cafea() : scorAromatica(nullptr) {
    origine = "Etiopia";
    codProdus = 100;
    scorAromatica = new float(8.5f);
    totalSortimente++;
  }

  Cafea(const string &origineNoua, int codNou) {
    origine = origineNoua;
    codProdus = codNou;
    scorAromatica = new float(7.0f);
    totalSortimente++;
  }

  Cafea(const string &origineNoua, int codNou, float scor) {
    origine = origineNoua;
    codProdus = codNou;
    scorAromatica = new float(scor);
    totalSortimente++;
  }

  static float PretPerGram(float pret, float grame) {
    if (grame <= 0) {
      return 0;
    }
    return pret / grame;
  }

  ~Cafea() {
    if (scorAromatica != nullptr) {
      delete scorAromatica;
    }
    totalSortimente--;
  }
};

int Cafea::totalSortimente = 0;

class Angajat {
public:
  string nume;
  static int salariuMinim;
  const string locatie = "Bucuresti";
  double *orePeSaptamana;
  int idAngajat;

  Angajat() : orePeSaptamana(nullptr) {
    nume = "Anonim";
    idAngajat = 200;
    orePeSaptamana = new double(40.0);
  }

  Angajat(const string &numeNou, int idNou) {
    nume = numeNou;
    idAngajat = idNou;
    orePeSaptamana = new double(38.0);
  }

  Angajat(const string &numeNou, int idNou, double ore) {
    nume = numeNou;
    idAngajat = idNou;
    orePeSaptamana = new double(ore);
  }

  static double OreSuplimentare(double oreSaptamanale) {
    if (oreSaptamanale <= 40.0) {
      return 0.0;
    }
    return oreSaptamanale - 40.0;
  }
  ~Angajat() {
    if (orePeSaptamana != nullptr) {
      delete orePeSaptamana;
    }
  }
};

int Angajat::salariuMinim = 3000;

class Espressor {
public:
  string marca;
  static int totalEspresoareActive;
  const string tip = "Espressor profesional";
  int *cicluriService;
  int tensiuneStandard;

  Espressor() : cicluriService(nullptr) {
    marca = "Classic";
    tensiuneStandard = 220;
    cicluriService = new int(0);
    totalEspresoareActive++;
  }

  Espressor(const string &marcaNoua, int tensiune) {
    marca = marcaNoua;
    tensiuneStandard = tensiune;
    cicluriService = new int(10);
    totalEspresoareActive++;
  }

  Espressor(const string &marcaNoua, int tensiune, int cicluri) {
    marca = marcaNoua;
    tensiuneStandard = tensiune;
    cicluriService = new int(cicluri);
    totalEspresoareActive++;
  }

  static int ShoturiPosibile(int grameCafea, int gramePerShot) {
    if (gramePerShot <= 0) {
      return 0;
    }
    return grameCafea / gramePerShot;
  }

  ~Espressor() {
    if (cicluriService != nullptr) {
      delete cicluriService;
    }
    cicluriService--;
  }
};

int Espressor::totalEspresoareActive = 0;

int main() {
  Cafea cafea1;
  Cafea cafea2("Columbia", 101);
  Cafea cafea3("Brazilia", 102, 9.3f);

  cout << "Cafea 1: origine=" << cafea1.origine << ", cod=" << cafea1.codProdus
       << ", scor=" << *cafea1.scorAromatica << endl;
  cout << "Cafea 2: origine=" << cafea2.origine << ", cod=" << cafea2.codProdus
       << ", scor=" << *cafea2.scorAromatica << endl;
  cout << "Cafea 3: origine=" << cafea3.origine << ", cod=" << cafea3.codProdus
       << ", scor=" << *cafea3.scorAromatica << endl;
  cout << "Pret pe gram pentru 30 lei si 250 grame: "
       << cafea1.PretPerGram(30.0f, 250.0f) << endl;
  cout << "Total sortimente cafea: " << cafea1.totalSortimente << endl;
  cout << "Brand cafenea pentru cafea 1: " << cafea1.brand << endl;

  Angajat angajat1;
  Angajat angajat2("Irina", 301);
  Angajat angajat3("Vlad", 302, 45.5);

  cout << "Angajat 1: nume=" << angajat1.nume << ", id=" << angajat1.idAngajat
       << ", ore=" << *angajat1.orePeSaptamana << endl;
  cout << "Angajat 2: nume=" << angajat2.nume << ", id=" << angajat2.idAngajat
       << ", ore=" << *angajat2.orePeSaptamana << endl;
  cout << "Angajat 3: nume=" << angajat3.nume << ", id=" << angajat3.idAngajat
       << ", ore=" << *angajat3.orePeSaptamana << endl;
  cout << "Ore suplimentare angajat 3: "
       << angajat3.OreSuplimentare(*angajat3.orePeSaptamana) << endl;
  cout << "Salariu minim in cafenea: " << angajat1.salariuMinim << endl;
  cout << "Locatie standard pentru angajati: " << angajat1.locatie << endl;

  Espressor espressor1;
  Espressor espressor2("AromaPro", 230);
  Espressor espressor3("CafeArt", 230, 120);

  cout << "Espressor 1: marca=" << espressor1.marca
       << ", tensiune=" << espressor1.tensiuneStandard
       << ", cicluri=" << *espressor1.cicluriService << endl;
  cout << "Espressor 2: marca=" << espressor2.marca
       << ", tensiune=" << espressor2.tensiuneStandard
       << ", cicluri=" << *espressor2.cicluriService << endl;
  cout << "Espressor 3: marca=" << espressor3.marca
       << ", tensiune=" << espressor3.tensiuneStandard
       << ", cicluri=" << *espressor3.cicluriService << endl;
  cout << "Shoturi posibile din 500 grame cu 7 grame per shot: "
       << espressor1.ShoturiPosibile(500, 7) << endl;
  cout << "Total espresoare active: " << espressor1.totalEspresoareActive
       << endl;
  cout << "Tip espressor standard: " << espressor1.tip << endl;

  return 0;
}
