#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

//* C , E , A  *//

// Domeniu ales: Cafenea => cafea,espressor,angajat
class Cafea {
public:
  

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

  //constructor copiere
  Cafea(const Cafea& cafea) : brand(cafea.brand) {
    this->origine = cafea.origine;
    this->codProdus = cafea.codProdus;
    
    if (cafea.scorAromatica != nullptr) {
        this->scorAromatica = new float(*cafea.scorAromatica);
    } else {
        this->scorAromatica = nullptr;
    }
    
    totalSortimente++;
}

  ~Cafea() {
    if (scorAromatica != nullptr) {
      delete scorAromatica;
    }
    totalSortimente--;
  }
  
  //TODO :

  // Getteri
  string getOrigine() {}
  int getCodProdus() {}
  float getScorAromatica() {}
  string getBrand() {}

  // Setteri
  void setOrigine(string origine) {}
  void setCodProdus(int cod) {}
  void setScorAromatica(float scor) {}

  // Functii statice
  static int getTotalSortimente() {}
  static void setTotalSortimente(int total) {}

private:
  string origine;
  static int totalSortimente;
  const string brand = "Cafenea Aroma";
  float *scorAromatica;
  int codProdus;


};

int Cafea::totalSortimente = 0;

class Angajat {
public:
  

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

  //constructor copiere
  Angajat(const Angajat& angajat) : locatie(angajat.locatie) {
    this->nume = angajat.nume;
    this->idAngajat = angajat.idAngajat;
    
    if (angajat.orePeSaptamana != nullptr) {
        this->orePeSaptamana = new double(*angajat.orePeSaptamana);
    } else {
        this->orePeSaptamana = nullptr;
    }
}

  ~Angajat() {
    if (orePeSaptamana != nullptr) {
      delete orePeSaptamana;
    }
  }
  //TODO :
  // getteri
  string getNume() {}
  int getIdAngajat() {}
  double getOrePeSaptamana() {}
  string getLocatie() {}

  // setteri
  void setNume(string nume) {}
  void setIdAngajat(int id) {}
  void setOrePeSaptamana(double ore) {}

  // Fct statice
  static int getSalariuMinim() {}
  static void setSalariuMinim(int salariu) {}

private:

  string nume;
  static int salariuMinim;
  const string locatie = "Bucuresti";
  double *orePeSaptamana;
  int idAngajat;

};

int Angajat::salariuMinim = 3000;

class Espressor {
public:
  
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

  //constructor copiere
  Espressor(const Espressor& espressor) : tip(espressor.tip) {
    this->marca = espressor.marca;
    this->tensiuneStandard = espressor.tensiuneStandard;
    
    if (espressor.cicluriService != nullptr) {
        this->cicluriService = new int(*espressor.cicluriService);
    } else {
        this->cicluriService = nullptr;
    }
    
    totalEspresoareActive++;
}

  ~Espressor() {
    if (cicluriService != nullptr) {
      delete cicluriService;
    }
    totalEspresoareActive--;
  }

  //todo :
  
  // Getteri
  string getMarca() {};
  int getTensiuneStandard() {}
  int getCicluriService() {}
  string getTip() {}

  // Setteri
  void setMarca(string marca) {}
  void setTensiuneStandard(int tensiune) {}
  void setCicluriService(int cicluri) {}

  // Functii statice
  static int getTotalEspresoareActive() {}
  static void setTotalEspresoareActive(int total) {}

private:

  string marca;
  static int totalEspresoareActive;
  const string tip = "Espressor profesional";
  int *cicluriService;
  int tensiuneStandard;
};

int Espressor::totalEspresoareActive = 0;



int main(){
    


}