#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

//* C , E , A  *//

// Domeniu ales: Cafenea => cafea,espressor,angajat

// Forward declarations
class Cafea;
class Angajat;
class Espressor;
class Cafenea;
class Cafea
{

private:
    string origine;
    static int totalSortimente;
    const string brand = "Cafenea Aroma";
    float *scorIntensitate;
    int codProdus;

public:
    Cafea() : scorIntensitate(nullptr)
    {
        origine = "Etiopia";
        codProdus = 100;
        scorIntensitate = new float(8.5f);
        totalSortimente++;
    }

    Cafea(const string &origineNoua, int codNou)
    {
        origine = origineNoua;
        codProdus = codNou;
        scorIntensitate = new float(7.0f);
        totalSortimente++;
    }

    Cafea(const string &origineNoua, int codNou, float scor)
    {
        origine = origineNoua;
        codProdus = codNou;
        scorIntensitate = new float(scor);
        totalSortimente++;
    }

    static float PretPerGram(float pret, float grame)
    {
        if (grame <= 0)
        {
            return 0;
        }
        return pret / grame;
    }

    // constructor copiere
    Cafea(const Cafea &cafea) : brand(cafea.brand)
    {
        this->origine = cafea.origine;
        this->codProdus = cafea.codProdus;

        if (cafea.scorIntensitate != nullptr)
        {
            this->scorIntensitate = new float(*cafea.scorIntensitate);
        }
        else
        {
            this->scorIntensitate = nullptr;
        }

        totalSortimente++;
    }

    ~Cafea()
    {
        if (scorIntensitate != nullptr)
        {
            delete scorIntensitate;
        }
        totalSortimente--;
    }

    // Getteri
    string getOrigine() const
    {
        return this->origine;
    }
    int getCodProdus()
    {
        return this->codProdus;
    }

    float getScorIntensitate() const
    {
        if (this->scorIntensitate != nullptr)
        {
            return *this->scorIntensitate;
        }
        return 0.0f;
    }

    string getBrand()
    {
        return this->brand;
    }

    // Setteri
    void setOrigine(string origine)
    {
        if (origine.length() > 0)
        {
            this->origine = origine;
        }
    }

    void setCodProdus(int cod)
    {
        this->codProdus = cod;
    }

    void setScorIntensitate(float scor)
    {
        if (scor > 0)
        {
            if (this->scorIntensitate != nullptr)
            {
                *this->scorIntensitate = scor;
            }
            else
            {
                this->scorIntensitate = new float(scor);
            }
        }
    }

    static int getTotalSortimente()
    {
        return totalSortimente;
    }

    static void setTotalSortimente(int total)
    {
        totalSortimente = total;
    }

    friend float calculeazaCostComanda(const Cafea &cafea, const Angajat &angajat, int grame);
    friend bool verificaCompatibilitateEspressor(const Espressor &espressor, const Cafea &cafea);

    Cafea operator=(const Cafea &cafea)
    {

        if (this != &cafea)
        {
            this->origine = cafea.origine;
            this->codProdus = cafea.codProdus;
        }
        if (this->scorIntensitate != nullptr)
        {
            delete this->scorIntensitate;
        }
        else if (cafea.scorIntensitate != nullptr)
        {
            this->scorIntensitate = new float(*cafea.scorIntensitate);
        }
        else
        {
            this->scorIntensitate = nullptr;
        }
        return *this;
    }

    friend ostream &operator<<(ostream &afiseaza, const Cafea &c)
    {
        return afiseaza << "Cafeaua provine din " << c.getOrigine() << " , " << "are "
                        << c.getTotalSortimente() << " sortimente " << " si un scor de intesitate de " << c.getScorIntensitate();
    }

    friend istream &operator>>(istream &citeste, Cafea &cafea)
    {
        cout << "Origine cafea: ";
        citeste >> cafea.origine;
        cout << "Cod produs :";
        citeste >> cafea.codProdus;

        float scor;
        cout << "Scor intensitate: ";
        citeste >> scor;

        if (cafea.scorIntensitate != nullptr)
        {
            *cafea.scorIntensitate = scor;
        }
        else
        {
            cafea.scorIntensitate = new float(scor);
        }

        return citeste;
    }

    Cafea &operator++()
    {
        this->totalSortimente++;

        return *this;
    }
};

int Cafea::totalSortimente = 0;

class Angajat
{

private:
    string nume;
    static int salariu;
    const string locatie = "Bucuresti";
    double *orePeSaptamana;
    int idAngajat;

public:
    Angajat() : orePeSaptamana(nullptr)
    {
        nume = "Anonim";
        idAngajat = 200;
        orePeSaptamana = new double(40.0);
    }

    Angajat(const string &numeNou, int idNou)
    {
        nume = numeNou;
        idAngajat = idNou;
        orePeSaptamana = new double(38.0);
    }

    Angajat(const string &numeNou, int idNou, double ore)
    {
        nume = numeNou;
        idAngajat = idNou;
        orePeSaptamana = new double(ore);
    }

    static double OreSuplimentare(double oreSaptamanale)
    {
        if (oreSaptamanale <= 40.0)
        {
            return 0.0;
        }
        return oreSaptamanale - 40.0;
    }

    // constructor copiere
    Angajat(const Angajat &angajat) : locatie(angajat.locatie)
    {
        this->nume = angajat.nume;
        this->idAngajat = angajat.idAngajat;

        if (angajat.orePeSaptamana != nullptr)
        {
            this->orePeSaptamana = new double(*angajat.orePeSaptamana);
        }
        else
        {
            this->orePeSaptamana = nullptr;
        }
    }

    ~Angajat()
    {
        if (orePeSaptamana != nullptr)
        {
            delete orePeSaptamana;
        }
    }

    //  getteri
    string getNume() const
    {
        return this->nume;
    }

    int getIdAngajat() const
    {
        return this->idAngajat;
    }

    double *getOrePeSaptamana() const
    {
        return this->orePeSaptamana;
    }

    string getLocatie()
    {
        return this->locatie;
    }

    // setteri
    void setNume(string nume)
    {
        if (nume.length() > 0)
        {
            this->nume = nume;
        }
    }

    void setIdAngajat(int id)
    {
        idAngajat = id;
    }

    void setOrePeSaptamana(double ore)
    {
        if (ore > 0)
        {
            if (this->orePeSaptamana != nullptr)
            {
                *this->orePeSaptamana = ore;
            }
            else
            {
                this->orePeSaptamana = new double(ore);
            }
        }
    }

    // Fct statice
    static int getSalariu()
    {
        return salariu;
    }

    static void setSalariu(int Salariu)
    {
        salariu = Salariu;
    }
    // Operator de atribuire
    Angajat &operator=(const Angajat &copie)
    {
        if (this != &copie)
        {
            this->nume = copie.nume;
            this->idAngajat = copie.idAngajat;

            if (this->orePeSaptamana != nullptr)
            {
                delete this->orePeSaptamana;
            }

            if (copie.orePeSaptamana != nullptr)
            {
                this->orePeSaptamana = new double(*copie.orePeSaptamana);
            }
            else
            {
                this->orePeSaptamana = nullptr;
            }
        }
        return *this;
    }

    friend float calculeazaPlataPeOra(const Angajat &angajat);
    friend float calculeazaCostComanda(const Cafea &cafea, const Angajat &angajat, int grame);
    /*string nume;
    static int salariu;
    const string locatie = "Bucuresti";
    double *orePeSaptamana;
    int idAngajat;*/
    Angajat operator+(int increment)
    {
        Angajat copie = *this;
        copie.idAngajat += increment; // creste salariul
        return copie;
    }

    Angajat operator!()
    {
        Angajat copie = *this;
        copie.idAngajat = -copie.idAngajat;
        return copie;
    }
    // operator dereferentiere :
    Angajat &operator*()
    {

        return *this;
    }

    friend ostream &operator<<(ostream &afiseaza, const Angajat &a)
    {
        return afiseaza << "Angajatul cu numele " << a.getNume()
                        << " si id-ul " << a.getIdAngajat() << " lucreaza "
                        << *a.getOrePeSaptamana() << " ore pe saptamana pe un salariu de"
                        << a.getSalariu() << " ron" << endl;
    }

    friend istream &operator>>(istream &citeste, Angajat &angajat)
    {
        cout << "Nume angajat:";
        citeste >> angajat.nume;
        cout << "Id angajat :";
        citeste >> angajat.idAngajat;

        double ore;
        cout << "Ore pe saptamana :";
        citeste >> ore;

        if (angajat.orePeSaptamana != nullptr)
        {
            *angajat.orePeSaptamana = ore;
        }
        else
        {
            angajat.orePeSaptamana = new double(ore);
        }
        return citeste;
    }
};

int Angajat::salariu = 3000;

class Espressor
{

private:
    string marca;
    static int totalEspresoareActive;
    const string tip = "Espressor profesional";
    int *cicluriService;
    int tensiuneStandard;

public:
    Espressor() : cicluriService(nullptr)
    {
        marca = "Classic";
        tensiuneStandard = 220;
        cicluriService = new int(0);
        totalEspresoareActive++;
    }

    Espressor(const string &marcaNoua, int tensiune)
    {
        marca = marcaNoua;
        tensiuneStandard = tensiune;
        cicluriService = new int(10);
        totalEspresoareActive++;
    }

    Espressor(const string &marcaNoua, int tensiune, int cicluri)
    {
        marca = marcaNoua;
        tensiuneStandard = tensiune;
        cicluriService = new int(cicluri);
        totalEspresoareActive++;
    }

    static int ShoturiPosibile(int grameCafea, int gramePerShot)
    {
        if (gramePerShot <= 0)
        {
            return 0;
        }
        return grameCafea / gramePerShot;
    }

    // constructor copiere
    Espressor(const Espressor &espressor) : tip(espressor.tip)
    {
        this->marca = espressor.marca;
        this->tensiuneStandard = espressor.tensiuneStandard;

        if (espressor.cicluriService != nullptr)
        {
            this->cicluriService = new int(*espressor.cicluriService);
        }
        else
        {
            this->cicluriService = nullptr;
        }

        totalEspresoareActive++;
    }

    ~Espressor()
    {
        if (cicluriService != nullptr)
        {
            delete cicluriService;
        }
        totalEspresoareActive--;
    }

    string getMarca() const
    {
        return this->marca;
    }

    int getTensiuneStandard()
    {
        return this->tensiuneStandard;
    }

    int getCicluriService() const
    {
        if (this->cicluriService != nullptr)
        {
            return *this->cicluriService;
        }
        return 0;
    }

    string getTip()
    {
        return this->tip;
    }

    void setMarca(string marca)
    {
        if (marca.length() > 0)
        {
            this->marca = marca;
        }
    }

    void setTensiuneStandard(int tensiune)
    {
        if (tensiune > 0)
        {
            this->tensiuneStandard = tensiune;
        }
    }

    void setCicluriService(int cicluri)
    {
        if (cicluri >= 0)
        {
            if (this->cicluriService != nullptr)
            {
                *this->cicluriService = cicluri;
            }
            else
            {
                this->cicluriService = new int(cicluri);
            }
        }
    }

    // Functii statice
    static int getTotalEspresoareActive()
    {
        return totalEspresoareActive;
    }

    static void setTotalEspresoareActive(int total)
    {
        totalEspresoareActive = total;
    }

    friend bool verificaCompatibilitateEspressor(const Espressor &espressor, const Cafea &cafea);

    Espressor &operator=(const Espressor &copie)
    {
        if (this != &copie)
        {
            this->marca = copie.marca;
            this->tensiuneStandard = copie.tensiuneStandard;
            if (this->cicluriService != nullptr)
            {
                delete this->cicluriService;
            }
            if (copie.cicluriService != nullptr)
            {
                this->cicluriService = new int(*copie.cicluriService);
            }
            else
            {
                this->cicluriService = nullptr;
            }
        }
        return *this;
    }

    Espressor &operator*=(int factor)
    {
        if (this->cicluriService != nullptr)
        {
            *this->cicluriService *= factor;
        }
        return *this;
    }

    Espressor &operator+=(int cicluri)
    {
        if (this->cicluriService != nullptr)
        {
            *this->cicluriService += cicluri;
        }
        return *this;
    }

    Espressor &operator--()
    {
        if (this->cicluriService != nullptr && *this->cicluriService > 0)
        {
            (*this->cicluriService)--;
        }
        return *this;
    }

    friend ostream &operator<<(ostream &afiseaza, const Espressor &e)
    {
        return afiseaza << "Am  " << e.getTotalEspresoareActive() << " espressoare active"
                        << " ,toate-s marca  " << e.getMarca() << " si au " << e.getCicluriService() << " cicluri service" << endl;
    }

    friend istream &operator>>(istream &citeste, Espressor &espressor)
    {
        cout << "Marca espressor : ";
        citeste >> espressor.marca;
        cout << "Tensiune standard :";
        citeste >> espressor.tensiuneStandard;

        int cicluri;
        cout << "Cicluri service:";
        citeste >> cicluri;

        if (espressor.cicluriService != nullptr)
        {
            *espressor.cicluriService = cicluri;
        }
        else
        {
            espressor.cicluriService = new int(cicluri);
        }
        return citeste;
    }
};
int Espressor::totalEspresoareActive = 0;

/*==FUNCTII FRIEND ==*/

float calculeazaPlataPeOra(const Angajat &angajat)
{
    if (angajat.orePeSaptamana == nullptr || *angajat.orePeSaptamana <= 0)
    {
        return 0.0f;
    }

    double plataPeOra = Angajat::salariu / *angajat.orePeSaptamana;

    // bonus ore suplimentare
    if (*angajat.orePeSaptamana > 40)
    {
        plataPeOra *= 1.5; // 50% bonus
        cout << "Bonus aplicat pentru " << angajat.nume << "!" << endl;
    }
    cout << angajat.nume << " - Plata: " << plataPeOra << " lei/ora" << endl;
    return plataPeOra;
}

float calculeazaCostComanda(const Cafea &cafea, const Angajat &angajat, int grame)
{
    if (cafea.scorIntensitate == nullptr || grame <= 0)
    {
        return 0.0f;
    }

    float pretCafea = *cafea.scorIntensitate * grame * 0.5;
    float comision = *angajat.orePeSaptamana * 0.1;

    cout << "Comanda procesata de: " << angajat.nume << endl;
    cout << "Cafea din: " << cafea.origine << " (cod: " << cafea.codProdus << ")" << endl;
    cout << "Cost total: " << (pretCafea + comision) << " lei" << endl;

    return pretCafea + comision;
}

bool verificaCompatibilitateEspressor(const Espressor &espressor, const Cafea &cafea)
{
    if (cafea.scorIntensitate == nullptr || espressor.cicluriService == nullptr)
    {
        return false;
    }

    bool compatibil = true;

    if (*cafea.scorIntensitate > 9.0 && espressor.tensiuneStandard < 240)
    {
        compatibil = false;
        cout << "Atentie: Cafea premium din " << cafea.origine
             << " necesita espressor cu tensiune mai mare!" << endl;
    }

    if (*espressor.cicluriService > 500)
    {
        cout << "Atentie: Espressorul " << espressor.marca << " necesita service urgent!!" << endl;
    }

    cout << "Testare: " << espressor.marca << " cu cafea din " << cafea.origine << endl;
    cout << "Status: " << (compatibil ? "Compatibil" : "Incompatibil") << endl;

    return compatibil;
}

class Cafenea
{
private:
    Angajat barista;
    int nrAngajati;
    string adresaCafenea;

public:
    Cafenea() : nrAngajati(10), adresaCafenea("Str. Lalelelor"),barista() {}
};

int main()
{

    return 0;
}