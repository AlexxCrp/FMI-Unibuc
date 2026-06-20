/*
Carpineanu Alexandu - Grupa 131
Tutore laborator: Anca Madalina Dobrovat
Compilator folosit: Compilatorul Folosid de Visual Studio 2019
*/
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;


class malware {
protected:
	float rating_impact;
	int zi_infectare;
	int luna_infectare;
	int an_infectare;
	string nume;
	string metoda_infectare;
	vector <string> reg_modificati;
public:
	virtual void calculare() {};
	malware();
	malware(float, int, int, int, string, string, string[]);
	malware(const malware&);
	~malware() {/*destructor*/ };
	malware& operator= (malware&);
	friend istream& operator>>(istream&, malware&);
	friend ostream& operator<<(ostream&, malware&);
};

malware::malware() 
{
	rating_impact = 0;
	zi_infectare = '\0';
	luna_infectare = '\0';
	an_infectare = '\0';
	nume = '\0';
	metoda_infectare = '\0';
	for (int i = 0; i < reg_modificati.size(); i++)
	{
		reg_modificati[i] = '\0';
	}
}

malware::malware(float a, int b, int c, int d, string e, string f, string g[])
{
	rating_impact = a;
	zi_infectare = b;
	luna_infectare = c;
	an_infectare = d;
	nume = e;
	metoda_infectare = f;
	for (int i = 0; i < reg_modificati.size(); i++)
	{
		reg_modificati[i] = g[i];
	}
}

malware::malware(const malware& ob)
{

	rating_impact = ob.rating_impact;
	zi_infectare = ob.zi_infectare;
	luna_infectare = ob.luna_infectare;
	an_infectare = ob.an_infectare;
	nume = ob.nume;
	metoda_infectare = ob.metoda_infectare;
	for (int i = 0; i < reg_modificati.size(); i++)
	{
		reg_modificati[i] = ob.reg_modificati[i];
	}
}

malware& malware::operator=(malware& ob)
{
	if (this != &ob)
	{
		rating_impact = ob.rating_impact;
		zi_infectare = ob.zi_infectare;
		luna_infectare = ob.luna_infectare;
		an_infectare = ob.an_infectare;
		nume = ob.nume;
		metoda_infectare = ob.metoda_infectare;
		for (int i = 0; i < reg_modificati.size(); i++)
		{
			reg_modificati[i] = ob.reg_modificati[i];
		}
	}
	return *this;
}

istream& operator>>(istream& in, malware& ob)
{
	int a;
	cout << "Rating impact:";
	in >> ob.rating_impact;

	cout << "\n Zi, Luna, An infectare:";
	in >> ob.zi_infectare >> ob.luna_infectare >> ob.an_infectare;

	cout << "\nNume:";
	in >> ob.nume;

	cout << "\nSe cunoaste metoda de infectare?(0=nu/1=da):";
	in >> a;
	if (a == 1)
	{
		cout << "\nMetoda Infectare:";
		in >> ob.metoda_infectare;
	}
	else
	{
		ob.metoda_infectare = "unknown";
	}
	int nr;
	cout << "\nNumar registrii modificati:";
	in >> nr;
	cout << "\nRegistrii modificati:";
	for (int i = 0; i < nr; i++)
	{
		string x;
		in >> x;
		ob.reg_modificati.push_back(x);
	}
	return in;
}

ostream& operator<<(ostream& out, malware& ob)
{
	out << "\nRating impact:" << ob.rating_impact;
	out << "\nZi, Luna, An infectare:" << ob.zi_infectare << ' ' << ob.luna_infectare << ' ' << ob.an_infectare;
	out << "\nNume:" << ob.nume;
	out << "\nMetoda Infectare:" << ob.metoda_infectare;
	out << "\nRegistrii modificati:";
	for (int i = 0; i < ob.reg_modificati.size(); i++)
	{
		out << ob.reg_modificati[i] << ' ';
	}
	return out;
}

class rootkit : virtual public malware {
protected:
	vector<string> l_importuri, l_stringuri;
public:
	virtual void calculare() {};
	rootkit();
	rootkit(float, int, int, int, string, string, string[], string[], string[]);
	rootkit(const rootkit&);
	~rootkit() {/*destructor*/ };
	rootkit& operator= (rootkit&);
	friend istream& operator>>(istream&, rootkit&);
	friend ostream& operator<<(ostream&, rootkit&);
};

rootkit::rootkit() :malware()
{

	for (int i = 0; i < l_importuri.size(); i++)
	{
		l_importuri[i] = '\0';
	}
	for (int i = 0; i < l_stringuri.size(); i++)
	{
		l_stringuri[i] = '\0';
	}
}

rootkit::rootkit(float a, int b, int c, int d, string e, string f, string g[], string h[], string j[]) : malware(a,b,c,d,e,f,g)
{
	for (int i = 0; i < l_importuri.size(); i++)
	{
		l_importuri[i] = h[i];
	}
	for (int i = 0; i < l_stringuri.size(); i++)
	{
		l_stringuri[i] = j[i];
	}
}

rootkit::rootkit(const rootkit& ob) : malware(ob)
{
	for (int i = 0; i < l_importuri.size(); i++)
	{
		l_importuri[i] = ob.l_importuri[i];
	}
	for (int i = 0; i < l_stringuri.size(); i++)
	{
		l_stringuri[i] = ob.l_stringuri[i];
	}
}

rootkit& rootkit::operator=(rootkit& ob)
{
	if (this != &ob)
	{
		malware::operator=(ob);
		for (int i = 0; i < l_importuri.size(); i++)
		{
			l_importuri[i] = ob.l_importuri[i];
		}
		for (int i = 0; i < l_stringuri.size(); i++)
		{
			l_stringuri[i] = ob.l_stringuri[i];
		}
	}
	return *this;
}

istream& operator>>(istream& in, rootkit& ob)
{
	in >> (malware&)ob;
	cout << "\nNr importuri:";
	int nr1;;
	in >> nr1;
	cout << "\nLista importuri:";
	for (int i = 0; i < nr1; i++)
	{
		string x;
		in >> x;
		ob.l_importuri.push_back(x);
	}

	cout << "\nNr Stringuri:";
	int nr2;;
	in >> nr2;
	cout << "\nLista stringuri:";
	for (int i = 0; i < nr2; i++)
	{
		string x;
		in >> x;
		ob.l_stringuri.push_back(x);
	}
	return in;
}

ostream& operator<<(ostream& out, rootkit& ob)
{
	out << (malware&)ob;
	out << "\nImporturi";
	for (int i = 0; i < ob.l_importuri.size(); i++)
	{
		out << ob.l_importuri[i] << ' ';
	}

	out << "\nStringuri";
	for (int i = 0; i < ob.l_stringuri.size(); i++)
	{
		out << ob.l_stringuri[i] << ' ';
	}
	return out;
}

class keylogger : virtual public malware {
protected:
	vector<string> l_functii, l_taste;
public:
	virtual void calculare() {};
	keylogger();
	keylogger(float, int, int, int, string, string, string[], string[], string[]);
	keylogger(const keylogger&);
	~keylogger() {/*destructor*/ };
	keylogger& operator= (keylogger&);
	friend istream& operator>>(istream&, keylogger&);
	friend ostream& operator<<(ostream&, keylogger&);
};

keylogger::keylogger() :malware()
{

	for (int i = 0; i < l_functii.size(); i++)
	{
		l_functii[i] = '\0';
	}
	for (int i = 0; i < l_taste.size(); i++)
	{
		l_taste[i] = '\0';
	}
}

keylogger::keylogger(float a, int b, int c, int d, string e, string f, string g[], string h[], string j[]) : malware(a, b, c, d, e, f, g)
{
	for (int i = 0; i < l_functii.size(); i++)
	{
		l_functii[i] = h[i];
	}
	for (int i = 0; i < l_taste.size(); i++)
	{
		l_taste[i] = j[i];
	}
}

keylogger::keylogger(const keylogger& ob) : malware(ob)
{
	for (int i = 0; i < l_functii.size(); i++)
	{
		l_functii[i] = ob.l_functii[i];
	}
	for (int i = 0; i < l_taste.size(); i++)
	{
		l_taste[i] = ob.l_taste[i];
	}
}

keylogger& keylogger::operator=(keylogger& ob)
{
	if (this != &ob)
	{
		malware::operator=(ob);
		for (int i = 0; i < l_functii.size(); i++)
		{
			l_functii[i] = ob.l_functii[i];
		}
		for (int i = 0; i < l_taste.size(); i++)
		{
			l_taste[i] = ob.l_taste[i];
		}
	}
	return *this;
}

istream& operator>>(istream& in, keylogger& ob)
{
	in >> (malware&)ob;
	cout << "\nNr importuri:";
	int nr1;;
	in >> nr1;
	cout << "\nLista importuri:";
	for (int i = 0; i < nr1; i++)
	{
		string x;
		in >> x;
		ob.l_functii.push_back(x);
	}

	cout << "\nNr Stringuri:";
	int nr2;;
	in >> nr2;
	cout << "\nLista stringuri:";
	for (int i = 0; i < nr2; i++)
	{
		string x;
		in >> x;
		ob.l_taste.push_back(x);
	}
	return in;
}

ostream& operator<<(ostream& out, keylogger& ob)
{
	out << (malware&)ob;
	out << "\nImporturi";
	for (int i = 0; i < ob.l_functii.size(); i++)
	{
		out << ob.l_functii[i] << ' ';
	}

	out << "\nStringuri";
	for (int i = 0; i < ob.l_taste.size(); i++)
	{
		out << ob.l_taste[i] << ' ';
	}
	return out;
}

class kernel_keylogger : public rootkit, public keylogger {
private:
	int ascunde;
public:
	virtual void calculare() {};
	kernel_keylogger();
	kernel_keylogger(float, int, int, int, string, string, string[], string[], string[], string[], string[], int m);
	kernel_keylogger(const kernel_keylogger&);
	~kernel_keylogger() {/*destructor*/ };
	kernel_keylogger& operator= (kernel_keylogger&);
	friend istream& operator>>(istream&, kernel_keylogger&);
	friend ostream& operator<<(ostream&, kernel_keylogger&);
};

kernel_keylogger::kernel_keylogger() : rootkit(), keylogger()
{
	ascunde = NULL;
}

kernel_keylogger::kernel_keylogger(float a, int b, int c, int d, string e, string f, string g[], string h[], string j[], string k[], string l[], int m) : rootkit(a, b, c, d, e, f, g, h, j), keylogger(a, b, c, d, e, f, g, k, l), malware(a, b, c, d, e, f, g)
{
	ascunde = m;
}

kernel_keylogger::kernel_keylogger(const kernel_keylogger& ob) : rootkit(ob), keylogger(ob)
{
	ascunde = ob.ascunde;
}

kernel_keylogger& kernel_keylogger::operator=(kernel_keylogger& ob)
{
	if (this != &ob)
	{
		rootkit::operator=(ob);
		keylogger::operator=(ob);
		ascunde = ob.ascunde;
	}
		return *this;
}

istream& operator>>(istream& in, kernel_keylogger& ob)
{
	in >> (rootkit&)ob;
	cout << "\nNr importuri:";
	int nr1;;
	in >> nr1;
	cout << "\nLista importuri:";
	for (int i = 0; i < nr1; i++)
	{
		string x;
		in >> x;
		ob.l_functii.push_back(x);
	}

	cout << "\nNr Stringuri:";
	int nr2;;
	in >> nr2;
	cout << "\nLista stringuri:";
	for (int i = 0; i < nr2; i++)
	{
		string x;
		in >> x;
		ob.l_taste.push_back(x);
	}

	cout << "Ascunde?(0=nu/1=da)";
	in >> ob.ascunde;
	return in;
}

ostream& operator<<(ostream& out, kernel_keylogger& ob)
{
	out << (rootkit&)ob;
	out << "\nImporturi";
	for (int i = 0; i < ob.l_functii.size(); i++)
	{
		out << ob.l_functii[i] << ' ';
	}

	out << "\nStringuri";
	for (int i = 0; i < ob.l_taste.size(); i++)
	{
		out << ob.l_taste[i] << ' ';
	}

	if (ob.ascunde == 1)
	{
		out << "\nascunde";
	}
	else
	{
		out << "\nnu ascunde";
	}
	return out;
}

class ransomware : public malware {
private:
	int r_criptare;
	float r_obfuscare;
public:
	virtual void calculare() {};
	ransomware();
	ransomware(float, int, int, int, string, string, string[], int, float);
	ransomware(const ransomware&);
	~ransomware() {/*destructor*/ };
	ransomware& operator= (ransomware&);
	friend istream& operator>>(istream&, ransomware&);
	friend ostream& operator<<(ostream&, ransomware&);
};

ransomware::ransomware() :malware()
{

	r_criptare = 0;
	r_obfuscare = 0;
}

ransomware::ransomware(float a, int b, int c, int d, string e, string f, string g[], int h, float j) : malware(a, b, c, d, e, f, g)
{
	r_criptare = h;
	r_obfuscare = j;
}

ransomware::ransomware(const ransomware& ob) : malware(ob)
{
	r_criptare = ob.r_criptare;
	r_obfuscare = ob.r_obfuscare;
}

ransomware& ransomware::operator=(ransomware& ob)
{
	if (this != &ob)
	{
		malware::operator=(ob);
		r_criptare = ob.r_criptare;
		r_obfuscare = ob.r_obfuscare;
	}
	return *this;
}

istream& operator>>(istream& in, ransomware& ob)
{
	in >> (malware&)ob;
	cout << "\nRating Criptare:";
	in >> ob.r_criptare;

	cout << "\nRating Obfuscare:";
	in >> ob.r_obfuscare;
	return in;
}

ostream& operator<<(ostream& out, ransomware& ob)
{
	out << (malware&)ob;
	out << "\nRating criptare";
	out << ob.r_criptare;

	out << "\nRating Obfuscare";
	out << ob.r_obfuscare;
	return out;
}


class computer {
private:
	static int id;
	vector<malware*> v;
	float rating_final;
public:
	virtual void calculare() {};
	static void increment_id() { id++; };
	friend istream& operator>>(istream&, computer&);
	friend ostream& operator<<(ostream&, computer&);
};

istream& operator>>(istream& in, computer& ob)
{
	cout << "Cati virusi are computerul?";
	int n;
	in >> n;

	for (int i = 0; i < n; i++)
	{
		system("CLS");

		cout << "\nCe virus?";

		cout << "1.Rootkit";
		cout << "2.Keylogger";
		cout << "3.Kernel-Keylogger";
		cout << "4.Ransomware";

		int optiune;
		in >> optiune;

		if (optiune == 1) {
			ob.v[i] = new rootkit();
			in >> *dynamic_cast<rootkit*>(ob.v[i]);
		}
		else if (optiune == 2)
		{
			ob.v[i] = new keylogger();
			in >> *dynamic_cast<keylogger*>(ob.v[i]);
		}
		else if (optiune == 3)
		{
			ob.v[i] = new kernel_keylogger();
			in >> *dynamic_cast<kernel_keylogger*>(ob.v[i]);
		}
		else
		{
			ob.v[i] = new ransomware();
			in >> *dynamic_cast<ransomware*>(ob.v[i]);
		}
	}
	return in;
}

ostream& operator<<(ostream& out, computer& ob)
{
	for (int i = 0; i < ob.v.size(); i++)
	{
		if (typeid(*ob.v[i]) == typeid(rootkit))
		{
			out << *dynamic_cast<rootkit*>(ob.v[i]);
		}
		//... nu mai am timp
	}
	return out;
}


int main()
{
	//nu mai am timp si de afisare si stocare de computere :(
	return 0;
}