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

class Cafea
{

private:
	string origine;
	static int totalSortimente;
	const string brand = "Cafenea Aroma";
	float *scorAromatica;
	int codProdus;

public:
	Cafea() : scorAromatica(nullptr)
	{
		origine = "Etiopia";
		codProdus = 100;
		scorAromatica = new float(8.5f);
		totalSortimente++;
	}

	Cafea(const string &origineNoua, int codNou)
	{
		origine = origineNoua;
		codProdus = codNou;
		scorAromatica = new float(7.0f);
		totalSortimente++;
	}

	Cafea(const string &origineNoua, int codNou, float scor)
	{
		origine = origineNoua;
		codProdus = codNou;
		scorAromatica = new float(scor);
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

		if (cafea.scorAromatica != nullptr)
		{
			this->scorAromatica = new float(*cafea.scorAromatica);
		}
		else
		{
			this->scorAromatica = nullptr;
		}

		totalSortimente++;
	}

	~Cafea()
	{
		if (scorAromatica != nullptr)
		{
			delete scorAromatica;
		}
		totalSortimente--;
	}

	// Getteri
	string getOrigine()
	{
		return this->origine;
	}
	int getCodProdus()
	{
		return this->codProdus;
	}

	float getScorAromatica()
	{
		if (this->scorAromatica != nullptr)
		{
			return *this->scorAromatica;
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

	void setScorAromatica(float scor)
	{
		if (scor > 0)
		{
			if (this->scorAromatica != nullptr)
			{
				*this->scorAromatica = scor;
			}
			else
			{
				this->scorAromatica = new float(scor);
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
	string getNume()
	{
		return this->nume;
	}

	int getIdAngajat()
	{
		return this->idAngajat;
	}

	double *getOrePeSaptamana()
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

	friend float calculeazaPlataPeOra(const Angajat &angajat);
	friend float calculeazaCostComanda(const Cafea &cafea, const Angajat &angajat, int grame);
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

	string getMarca()
	{
		return this->marca;
	}

	int getTensiuneStandard()
	{
		return this->tensiuneStandard;
	}

	int getCicluriService()
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
	if (cafea.scorAromatica == nullptr || grame <= 0)
	{
		return 0.0f;
	}

	float pretCafea = *cafea.scorAromatica * grame * 0.5;
	float comision = *angajat.orePeSaptamana * 0.1;

	cout << "Comanda procesata de: " << angajat.nume << endl;
	cout << "Cafea din: " << cafea.origine << " (cod: " << cafea.codProdus << ")" << endl;
	cout << "Cost total: " << (pretCafea + comision) << " lei" << endl;

	return pretCafea + comision;
}

bool verificaCompatibilitateEspressor(const Espressor &espressor, const Cafea &cafea)
{
	if (cafea.scorAromatica == nullptr || espressor.cicluriService == nullptr)
	{
		return false;
	}

	bool compatibil = true;

	if (*cafea.scorAromatica > 9.0 && espressor.tensiuneStandard < 240)
	{
		compatibil = false;
		cout << "Atentie: Cafea premium din " << cafea.origine
			 << " necesita espressor cu tensiune mai mare!" << endl;
	}

	if (*espressor.cicluriService > 500)
	{
		cout << "Atentie: Espressorul " << espressor.marca << " necesita service urgent!" << endl;
	}

	cout << "Testare: " << espressor.marca << " cu cafea din " << cafea.origine << endl;
	cout << "Status: " << (compatibil ? "Compatibil" : "Incompatibil") << endl;

	return compatibil;
}

int main()
{

	cout << " Clasa Cafea " << endl;
	Cafea cafea1;
	Cafea cafea2("Columbia", 101, 9.5f);

	cout << "Cafea 1: " << cafea1.getOrigine() << ", Brand: " << cafea1.getBrand()
		 << ", Scor: " << cafea1.getScorAromatica() << endl;
	cout << "Cafea 2: " << cafea2.getOrigine() << ", Cod: " << cafea2.getCodProdus()
		 << ", Scor: " << cafea2.getScorAromatica() << endl;

	cafea1.setOrigine("Brazil");
	cafea1.setScorAromatica(8.0f);
	cout << "Cafea 1 dupa modificare: " << cafea1.getOrigine()
		 << ", Scor: " << cafea1.getScorAromatica() << endl;

	cout << "Total sortimente: " << Cafea::getTotalSortimente() << endl;

	// Test constructor copiere
	Cafea cafea3(cafea2);
	cout << "Cafea 3 (copie din cafea2): " << cafea3.getOrigine()
		 << ", Scor: " << cafea3.getScorAromatica() << endl;
	cout << endl;

	cout << " Clasa Angajat " << endl;
	Angajat angajat1;
	Angajat angajat2("Ion Popescu", 201, 45.0);

	cout << "Angajat 1: " << angajat1.getNume() << ", ID: " << angajat1.getIdAngajat()
		 << ", Ore: " << *angajat1.getOrePeSaptamana() << endl;
	cout << "Angajat 2: " << angajat2.getNume() << ", Locatie: " << angajat2.getLocatie()
		 << ", Ore: " << *angajat2.getOrePeSaptamana() << endl;

	angajat1.setNume("Maria Ionescu");
	angajat1.setOrePeSaptamana(42.0);
	cout << " Angajat 1 dupa modificare: " << angajat1.getNume()
		 << ", Ore: " << *angajat1.getOrePeSaptamana() << endl;

	cout << "Salariu minim: " << Angajat::getSalariu() << " lei" << endl;

	Angajat angajat3(angajat2);
	cout << "Angajat 3 (copie din angajat2): " << angajat3.getNume()
		 << ", Ore: " << *angajat3.getOrePeSaptamana() << endl;
	cout << endl;

	cout << "Test Clasa Espressor " << endl;
	Espressor espressor1;
	Espressor espressor2("DeLonghi", 240, 150);

	cout << "Espressor 1: " << espressor1.getMarca() << ", Tensiune: "
		 << espressor1.getTensiuneStandard() << "V, Cicluri: "
		 << espressor1.getCicluriService() << endl;
	cout << "Espressor 2: " << espressor2.getMarca() << ", Tip: "
		 << espressor2.getTip() << ", Cicluri: "
		 << espressor2.getCicluriService() << endl;

	espressor1.setMarca("Gaggia");
	espressor1.setCicluriService(50);
	cout << "Espressor 1 dupa modificare: " << espressor1.getMarca()
		 << ", Cicluri: " << espressor1.getCicluriService() << endl;

	cout << "Total espresoare active: " << Espressor::getTotalEspresoareActive() << endl;

	Espressor espressor3(espressor2);
	cout << "Espressor 3 (copie din espressor2): " << espressor3.getMarca()
		 << ", Cicluri: " << espressor3.getCicluriService() << endl;
	cout << endl;

	cout << " Functii Friend " << endl;

	//  Functie 1-calculeazaPlataPeOra
	cout << "Test 1 - Plata pe ora:" << endl;
	float plata1 = calculeazaPlataPeOra(angajat1);
	float plata2 = calculeazaPlataPeOra(angajat2);
	cout << endl;

	// Functie 2- calculeazaCostComanda
	cout << "Cost comanda:" << endl;
	float cost = calculeazaCostComanda(cafea2, angajat2, 250);
	cout << endl;

	// Functie 3- verificaCompatibilitateEspressor
	cout << " Compatibilitate espressor:" << endl;
	bool compat1 = verificaCompatibilitateEspressor(espressor1, cafea1);
	cout << endl;
	bool compat2 = verificaCompatibilitateEspressor(espressor2, cafea2);
	cout << endl;

	return 0;
}