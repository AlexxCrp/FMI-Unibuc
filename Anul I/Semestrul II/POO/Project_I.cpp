#include <iostream>
#include <string>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <cstring>

using namespace std;

class persoana {
	string nume;
	int anNastere;
	char sex;
public:
	persoana();
	persoana(string, int, char);
	persoana(const persoana&);
	persoana& operator=(persoana&);
	string get_nume();
	int get_anNastere();
	char get_sex();
	void set_nume(string);
	void set_anNastere(int);
	void set_sex(char);
	~persoana();
	friend istream& operator>>(istream&, persoana&);
	friend ostream& operator<<(ostream&, persoana&);
	friend class baza_de_date;
};

istream& operator>>(istream& in, persoana& obiect)
{
	in >> obiect.nume;
	in >> obiect.anNastere;
	in >> obiect.sex;
	return in;
}

ostream& operator<<(ostream& out, persoana& obiect)
{
	out << obiect.nume<<endl;
	out << obiect.anNastere<<endl;
	out << obiect.sex<<endl;
	return out;
}

persoana::persoana() {
	nume = "nedeterminat";
	anNastere = 0;
	sex = '?';
}

persoana::persoana(string x, int y, char z) {
	nume = x;
	anNastere = y;
	sex = z;
}

persoana::~persoana() {
	//cout << "destructor";
}

persoana::persoana(const persoana& obiect) {
	nume = obiect.nume;
	anNastere = obiect.anNastere;
	sex = obiect.sex;
}

persoana& persoana::operator=(persoana& obiect) {
	if (this != &obiect)
	{
		nume = obiect.nume;
		anNastere = obiect.anNastere;
		sex = obiect.sex;
	}
	return *this;
}

string persoana::get_nume() {
	return nume;
}

int persoana::get_anNastere() {
	return anNastere;
}

char persoana::get_sex() {
	return sex;
}

void persoana::set_nume(string x) {
	nume = x;
}

void persoana::set_anNastere(int x) {
	anNastere = x;
}

void persoana::set_sex(char x) {
	sex = x;
}

class baza_de_date {
	int nrPersoane;
	persoana * persoane;

public:
	baza_de_date();
	baza_de_date(int);
	baza_de_date(const baza_de_date&);
	~baza_de_date();
	baza_de_date& operator=(baza_de_date&);
	void set_nrPersoane(int);
	int get_nrPersoane();
	void addPersoana(persoana);
	void elimPersoana(string);
	void elimPersoana(int);
	void elimPersoana(char);
	void afisPersoaneAlfabetic();
	void afisPersoaneCrescator(); 
	friend istream& operator>>(istream&, baza_de_date&);
	friend ostream& operator<<(ostream&, baza_de_date&);
	
};


istream& operator>>(istream& in, baza_de_date& obiect)
{
	in >> obiect.nrPersoane;
	for (int i = 0; i < obiect.nrPersoane; i++)
	{
		in >> obiect.persoane[i];
	}
	return in;
}

ostream& operator<<(ostream& out, baza_de_date& obiect)
{
	out << obiect.nrPersoane << endl;
	for (int i = 0; i < obiect.nrPersoane; i++)
	{
		out << obiect.persoane[i] << ' ';
	}
	return out;
}

baza_de_date::baza_de_date() {
	nrPersoane = 0;
	persoane = new persoana[nrPersoane];
}

baza_de_date::baza_de_date(int x) {
	nrPersoane = x;
	persoane = new persoana[nrPersoane];
	for (int i = 0; i < nrPersoane; i++)
	{
		persoane[i].nume = "\0";
		persoane[i].anNastere = NULL;
		persoane[i].sex = '\0';
	}
}

baza_de_date::baza_de_date(const baza_de_date& obiect) {
	nrPersoane = obiect.nrPersoane;
	persoane = new persoana[nrPersoane];
	for (int i = 0; i < nrPersoane; i++)
	{
		persoane[i] = obiect.persoane[i];
	}
}

baza_de_date& baza_de_date::operator=(baza_de_date& obiect) {
	if (this != &obiect)
	{
		nrPersoane = obiect.nrPersoane;
		persoane = new persoana[nrPersoane];
		for (int i = 0; i < nrPersoane; i++)
		{
			persoane[i] = obiect.persoane[i];
		}
	}
	return *this;
}

baza_de_date::~baza_de_date() {
	delete[] persoane;
}

void baza_de_date::set_nrPersoane(int x) {
	nrPersoane = x;
}

int baza_de_date::get_nrPersoane() {
	return nrPersoane;
}

void baza_de_date::addPersoana(persoana obiect) {
	int i = 0;
	while (persoane[i].nume != "\0" && i < nrPersoane)
	{
		i++;
	}
	if (i < nrPersoane)
	{
		persoane[i] = obiect;
	}

	else
	{	
		int j;
		int k = nrPersoane + 1;
		persoana* aux;
		aux = new persoana[k];
		for (j = 0; j < nrPersoane; j++)
		{
			aux[j] = persoane[j];                 
		}
		aux[j] = obiect;
		nrPersoane++;
		delete[] persoane;
		persoane = aux;		
	}

}

void baza_de_date::elimPersoana(string nume) {
	persoana* aux;
	int k = 0,j=0;
	for (int i = 0; i < nrPersoane; i++)
	{
		if (persoane[i].nume == nume)
		{
			k++;
		}
	}
	aux = new persoana[nrPersoane - k];
	for (int i = 0; i < nrPersoane; i++)
	{
		if (persoane[i].nume != nume)
		{
			aux[j++] = persoane[i];
		}
	}
	delete[] persoane;
	nrPersoane -= k;
	persoane = aux;
}

void baza_de_date::elimPersoana(int anNastere) {
	persoana* aux;
	int k = 0,j=0;
	for (int i = 0; i < nrPersoane; i++)
	{
		if (persoane[i].anNastere == anNastere)
		{
			k++;
		}
	}
	aux = new persoana[nrPersoane - k];
	for (int i = 0; i < nrPersoane; i++)
	{
		if (persoane[i].anNastere != anNastere)
		{
			aux[j++] = persoane[i];
		}
	}
	delete[] persoane;
	nrPersoane -= k;
	persoane = aux;
}

void baza_de_date::elimPersoana(char sex) {
	persoana* aux;
	int k = 0, j=0;
	for (int i = 0; i < nrPersoane; i++)
	{
		if (persoane[i].sex == sex)
		{
			k++;
		}
	}
	aux = new persoana[nrPersoane - k];
	for (int i = 0; i < nrPersoane; i++)
	{
		if (persoane[i].sex != sex)
		{
			aux[j++] = persoane[i];
		}
	}
	delete[] persoane;
	nrPersoane -= k;
	persoane = aux;
}

void baza_de_date::afisPersoaneAlfabetic() {
	persoana* aux;
	int k = 0;
	aux = new persoana[nrPersoane];
	persoana minim;
	minim.nume = "zzzzzzzzzzzzzzzzzzz";
	aux[0].nume = "\0";
	for (int i = 0; i < nrPersoane; i++)
	{
		if (persoane[i].nume < minim.nume)
		{
			minim = persoane[i];
			
		}
	}
	aux[k++] = minim;
	minim.nume = "zzzzzzzzzzzzzzzzzzz";
	for (int i = 1; i < nrPersoane; i++)
	{
		for (int j = 0; j < nrPersoane; j++)
		{
			if (persoane[j].nume < minim.nume && persoane[j].nume > aux[k-1].nume)
			{
				minim = persoane[j];
			}
		}
		aux[k++] = minim;
		minim.nume = "zzzzzzzzzzzzzzzzzzz";
	}
	for (int i = 0; i < nrPersoane; i++)
	{
		cout << aux[i];
	}
}

void baza_de_date::afisPersoaneCrescator(){
	persoana* aux;
	int k = 0;
	aux = new persoana[nrPersoane];
	persoana maxim;
	maxim.anNastere = 0;
	for (int i = 0; i < nrPersoane; i++)
	{
		if (persoane[i].anNastere > maxim.anNastere)
		{
			maxim = persoane[i];
		}
	}
	aux[k++] = maxim;
	maxim.anNastere = 0;
	for (int i = 1; i < nrPersoane; i++)
	{
		for (int j = 0; j < nrPersoane; j++)
		{
			if (persoane[j].anNastere > maxim.anNastere && persoane[j].anNastere < aux[k - 1].anNastere)
			{
				maxim = persoane[j];
			}
		}
		aux[k++] = maxim;
		maxim.anNastere = 0;
	}
	for (int i = 0; i < nrPersoane; i++)
	{
		cout << aux[i];
	}
}


void Meniu() {
	bool meniu = true;
	int actiune, anNastere;
	string nume;										//TOT PROGRAMUL A FOST IMPLEMENTAT CU IMPRESIA CA LA NUME TREBUIE SCRIS UN SINGUR NUME,
	char sex;											//ADICA UN STRING FARA SPATII.
	baza_de_date BD(1);
	while (meniu)
	{
		cout << "Actiuni disponibile:" << endl << endl;

		cout << "1.Adaugati o persoana in baza de date" << endl;
		cout << "2.Eliminati o persoana din baza de date(In functie de nume)" << endl;
		cout << "3.Eliminati o persoana din baza de date(In functie de anul nasterii)" << endl;
		cout << "4.Eliminati o persoana din baza de date(In functie de Sex)" << endl;
		cout << "5.Afisati persoanele din baza de date in ordine lexicografica" << endl;
		cout << "6.Afisati persoanele din baza de date in ordine crescatoare a varstelor" << endl;
		cout << "7.Inchideti programul" << endl << endl;

		cout << "Alegeti numarul actiunii dorite:";
		cin >> actiune;

		system("CLS");
		nume = "";
		if (actiune == 1)
		{
			string aux1;
			cout << "Tastati numele de familie anul nasterii si sexul persoanei:";
			cin >> nume >> anNastere >> sex;
			persoana om(nume, anNastere, sex);
			BD.addPersoana(om);
			Sleep(500);
			cout << "Persoana adaugata cu succes";
			Sleep(3000);
		}
		else if (actiune == 2)
		{
			cout << "Tastati numele persoanei pe care doriti sa o eliminati:";
			cin >> nume;
			BD.elimPersoana(nume);
			Sleep(500);
			cout << "Persoana(e) eliminata(e) cu succes";
			Sleep(3000);
		}
		else if (actiune == 3)
		{
			cout << "Tastati anul nasterii persoanei pe care doriti sa o eliminati:";
			cin >> anNastere;
			BD.elimPersoana(anNastere);
			Sleep(500);
			cout << "Persoana(e) eliminata(e) cu succes";
			Sleep(3000);
		}
		else if (actiune == 4)
		{
			cout << "Tastati sexul persoanei pe care doriti sa o eliminati:";
			cin >> sex;
			BD.elimPersoana(sex);
			Sleep(500);
			cout << "Persoana(e) eliminata(e) cu succes";
			Sleep(3000);
		}
		else if (actiune == 5)
		{
			BD.afisPersoaneAlfabetic();
			cout << endl;
			cout << "In 10 secunde, ecranul se va intoarce la meniul principal";
			Sleep(10000);
		}
		else if (actiune == 6)
		{
			BD.afisPersoaneCrescator();
			cout << endl;
			cout << "In 10 secunde, ecranul se va intoarce la meniul principal";
			Sleep(10000);
		}
		else
		{
			meniu = false;
		}
		system("CLS");
	}

}


int main() {

	Meniu();

	return 0;
}