#include <iostream>
#include <math.h>
#include <string>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
using namespace std;
//**********************************************PUNCT**********************************************************************************
class punct {
protected:
	float x, y;
public:
	punct();
	punct(float, float);
	punct(const punct&);
	~punct();
	punct& operator= (punct&);
	friend istream& operator>>(istream&, punct&);
	friend ostream& operator<<(ostream&, punct&);
	friend class patrat;
	friend class romb;
	friend class paralelogram;
	friend class trapez;
};

punct::punct() 
{
	x = 0;
	y = 0;
}

punct::punct(float a, float b)
{
	x = a;
	y = b;
}

punct::punct(const punct& ob)
{
	x = ob.x;
	y = ob.y;
}

punct& punct::operator=(punct& ob)
{
	if (this != &ob)
	{
		x = ob.x;
		y = ob.y;
	}
	return *this;
}

istream& operator>>(istream& in, punct& ob)
{
	in >> ob.x >> ob.y;
	return in;
}

ostream& operator<<(ostream& out, punct& ob)
{
	out << ob.x <<','<< ob.y<<"\n";
	return out;
}

punct::~punct()
{
	//cout<<destructor;
}
//*******************************************************PATRAT************************************************************************************************
class patrat {
protected:
	punct stanga_jos;
	float latura;
	bool valid = 1;
	static int nrPatrate;
public:
	patrat();
	patrat(punct, float);
	patrat(patrat&);
	~patrat();
	patrat& operator=(patrat&);
	friend istream& operator>>(istream&, patrat&);
	friend ostream& operator<<(ostream&, patrat&);
	virtual float arie();
	void validitate();
	static void showNrPatrate();
//	void get_validitate();
};

int patrat::nrPatrate;

void patrat::showNrPatrate()
{
	cout << nrPatrate;
}

void patrat::validitate()
{
	if (latura <= 0)
	{
		valid = 0;
		cout << "Patratul nu este valid!";
	}
	else
	{
		cout << "Patratul este valid!";
	}
}

float patrat::arie()
{
	try
	{
		if (valid == false)
		{
			throw 1;
		}
	}
	catch (int)
	{
		cout << "Patratul nu este valid!";
		return NULL;
	}
	return latura * latura;
}

patrat::patrat()
{
	stanga_jos.x = 0;
	stanga_jos.y = 0;
	latura = 0;
}

patrat::patrat(punct ob, float x)
{
	stanga_jos = ob;
	latura = x;
	nrPatrate++;
}

patrat::patrat(patrat& ob)
{
	stanga_jos = ob.stanga_jos;
	latura = ob.latura;
}

patrat& patrat::operator=(patrat& ob)
{
	if (this != &ob)
	{
		stanga_jos = ob.stanga_jos;
		latura = ob.latura;
	}
	return *this;
}

istream& operator>>(istream& in, patrat& ob)
{
	cout << "Vom avea nevoie de abscisa si ordonata punctului stanga_jos:";
	in >> ob.stanga_jos;
	system("CLS");
	cout << "Vom avea nevoie de lungimea primei laturi:";
	in >> ob.latura;
	return in;
}

ostream& operator<<(ostream& out, patrat& ob)
{
	out << ob.stanga_jos;
	out << ob.latura << "\n";
	return out;
}

patrat::~patrat()
{
	//cout<<"destructor";
}
//*************************************************************************DREPTUNGHI******************************************************************************************
class dreptunghi:virtual public patrat {
protected:
	float latura2;
	bool valid=1;
public:
	dreptunghi();
	dreptunghi(punct, float, float);
	dreptunghi(dreptunghi&);
	~dreptunghi();
	dreptunghi& operator= (dreptunghi&);
	friend istream& operator>>(istream&, dreptunghi&);
	friend ostream& operator<<(ostream&, dreptunghi&);
	void validitate();
	virtual float arie();
//	void get_validitate();
};

void dreptunghi::validitate()
{
	if (latura<0 || latura2<0)
	{
		valid = 0;
		cout << "Dreptunghiul nu este valid";
	}
	else
	{
		cout << "Dreptunghiul este valid!";
	}
}

float dreptunghi::arie()
{
	try
	{
		if (valid == false)
		{
			throw 1;
		}
	}
	catch (int)
	{
		cout << "Dreptunghiul nu este valid!";
		return NULL;
	}
	return latura * latura2;
}

dreptunghi::dreptunghi() :patrat()
{
	latura2 = 0;
}

dreptunghi::dreptunghi(punct pct, float x1, float x2) : patrat(pct, x1)
{
	latura2 = x2;
}

dreptunghi::dreptunghi(dreptunghi& ob) : patrat(ob)
{
	latura2 = ob.latura2;
}

dreptunghi& dreptunghi::operator=(dreptunghi& ob)
{
	if (this != &ob)
	{
		patrat::operator=(ob);
		latura2 = ob.latura2;
	}
	return *this;
}

istream& operator>>(istream& in, dreptunghi& ob)
{
	in >> (patrat&) ob;
	cout << "Vom avea nevoie si de lungimea laturii 2:";
	in >> ob.latura2;
	return in;
}

ostream& operator<<(ostream& out, dreptunghi& ob)
{
	out << (patrat&)ob;
	out << ob.latura2;
	out << "\n";
	return out;
}

dreptunghi::~dreptunghi()
{
	//cout<<"destructor";
}
//****************************************************************************************ROMB*****************************************************************************************
class romb:virtual public patrat {
protected:
	punct colt_opus;
	bool valid=1;
	bool paralele = 0;
public:
	romb();
	romb(punct, punct, float);
	romb(romb&);
	~romb();
	romb& operator= (romb&);
	friend istream& operator>>(istream&, romb&);
	friend ostream& operator<<(ostream&, romb&);
	void validitate();
	virtual float arie();
//	void get_validitate();
};

void romb::validitate()
{
	float latura_verificare;
	punct punct3, punct4;

	punct3.x = stanga_jos.x + latura;
	punct3.y = stanga_jos.y;

	latura_verificare = sqrt((colt_opus.x - punct3.x) * (colt_opus.x - punct3.x) + (colt_opus.y - punct3.y) * (colt_opus.y - punct3.y));

	if (latura != latura_verificare || latura < 0 || paralele == 0)
	{
		valid = 0;
		cout << "Rombul nu este valid";
	}
	else
	{
		cout << "Rombul este valid";
	}

}

float romb::arie()
{

	try
	{
		if (valid == 0)
		{
			throw 1;
		}
	}
	catch (int)
	{
		cout << "Rombul nu este valid!";
		return NULL;
	}

	punct punct3, punct4;

	float diagonala1, diagonala2;

	punct3.x = stanga_jos.x + latura;
	punct3.y = stanga_jos.y;

	punct4.x = colt_opus.x - latura;
	punct4.y = colt_opus.y;

	diagonala1 = sqrt((colt_opus.x - stanga_jos.x) * (colt_opus.x - stanga_jos.x) + (colt_opus.y - stanga_jos.y) * (colt_opus.y - stanga_jos.y));
	diagonala2 = sqrt((punct3.x - punct4.x) * (punct3.x - punct4.x) + (punct3.y - punct4.y) * (punct3.y - punct4.y));

	return ((diagonala1 * diagonala2) / 2.0);
}

romb::romb() :patrat()
{
	colt_opus.x = 0;
	colt_opus.y = 0;
}

romb::romb(punct pct,punct pct2 ,float x1) : patrat(pct, x1)
{
	colt_opus = pct2;

	punct colt1, colt2;

	colt1.x = stanga_jos.x + latura;
	colt1.y = stanga_jos.y;

	colt2.x = colt_opus.x - latura;
	colt2.y = colt_opus.y;

	float panta1, panta2;

	panta1 = (colt1.y - stanga_jos.y) / (colt1.x - stanga_jos.x);
	panta2 = (colt2.y - colt_opus.y) / (colt2.x - colt_opus.x);

	if ((panta1 == panta2) && (panta1 == 0))
	{
		paralele = 1;
	}

}

romb::romb(romb& ob) : patrat(ob)
{
	colt_opus = ob.colt_opus;
}

romb& romb::operator=(romb& ob)
{
	if (this != &ob)
	{
		patrat::operator=(ob);
		colt_opus = ob.colt_opus;
	}
	return *this;
}

istream& operator>>(istream& in, romb& ob)
{
	in >> (patrat&)ob;
	cout << "Vom avea nevoie si de coordonatele puncului opus:";
	in >> ob.colt_opus;
	return in;
}

ostream& operator<<(ostream& out, romb& ob)
{
	out << (patrat&)ob;
	out << ob.colt_opus;
	out << "\n";
	return out;
}

romb::~romb()
{
	//cout<<"destructor";
}
//**********************************************************************************PARALELOGRAM******************************************************************************************
class paralelogram: public dreptunghi, public romb {
protected:
	bool valid=1;
	bool paralele = 0;
public:
	paralelogram() :dreptunghi(), romb() {};
	paralelogram(float x, punct pct1, punct pct2, float y) :dreptunghi(pct1, x, y), romb(pct1, pct2, x), patrat(pct1, x) {
		punct colt1, colt2;

		colt1.x = stanga_jos.x + latura;
		colt1.y = stanga_jos.y;

		colt2.x = colt_opus.x - latura;
		colt2.y = colt_opus.y;

		float panta1, panta2;

		panta1 = (colt1.y - stanga_jos.y) / (colt1.x - stanga_jos.x);
		panta2 = (colt2.y - colt_opus.y) / (colt2.x - colt_opus.x);

		if ((panta1 == panta2) && (panta1 == 0))
		{
			paralele = 1;
		}
	};
	paralelogram(paralelogram& ob) :dreptunghi(ob), romb(ob) {};
	~paralelogram();
	paralelogram& operator= (paralelogram&);
	friend istream& operator>>(istream&, paralelogram&);
	friend ostream& operator<<(ostream&, paralelogram&);
	void validitate();
	virtual float arie();
	//void get_validitate();
};

void paralelogram::validitate()
{

	float latura_verificare;
	punct punct3, punct4;

	punct3.x = stanga_jos.x + latura;
	punct3.y = stanga_jos.y;

	latura_verificare = sqrt((colt_opus.x - punct3.x) * (colt_opus.x - punct3.x) + (colt_opus.y - punct3.y) * (colt_opus.y - punct3.y));


	if (latura != latura_verificare || latura < 0 || paralele == 0)
	{
		valid = 0;
		cout << "Paralaelogramul nu este valid!";
	}
	else
	{
		cout << "Paralelogramul este valid";
	}
}

float paralelogram::arie()
{
	try
	{
		if (valid == 0)
		{
			throw 1;
		}
	}
	catch (int)
	{
		cout << "Paralelogramul nu este valid!";
		return NULL;
	}

	float p;
	float diagonala;

	diagonala = sqrt((colt_opus.x - stanga_jos.x) * (colt_opus.x - stanga_jos.x) + (colt_opus.y - stanga_jos.y) * (colt_opus.y - stanga_jos.y));

	p = (latura + latura2 + diagonala) / 2.0;
	return (2 * sqrt(p*(p-latura)*(p-latura2)*(p-diagonala)));
}

paralelogram& paralelogram::operator=(paralelogram& ob)
{
	if (this != &ob)
	{
		dreptunghi::operator=(ob);
		romb::operator=(ob);
		
	}
	return *this;
}

istream& operator>>(istream& in, paralelogram& ob)
{
	
	in >> (dreptunghi&)ob;
	cout << "Vom avea nevoie si de coordonatele punctului opus:";
	in >> ob.colt_opus;
	return in;
}

ostream& operator<<(ostream& out, paralelogram& ob)
{
	
	out << (dreptunghi&)ob;
	out << ob.colt_opus;
	out << "\n";
	return out;
}

paralelogram::~paralelogram()
{
	//cout<<"PArelalogram";
}
//*****************************************************************************TRAPEZ**********************************************************************************************
class trapez: public paralelogram {
private:
	float baza2;
	bool valid=1;
	bool paralele = 0;
public:
	trapez();
	trapez(float, punct, punct, float, float);
	trapez(trapez&);
	trapez& operator=(trapez&);
	friend istream& operator>>(istream&, trapez&);
	friend ostream& operator<<(ostream&, trapez&);
	void validitate();
	virtual float arie();
	//void get_validitate();
};

void trapez::validitate()
{
	punct punct1;

	punct1.x = stanga_jos.x + latura2;
	punct1.y = stanga_jos.y;

	float latura_verificare;

	latura_verificare = sqrt((colt_opus.x - punct1.x) * (colt_opus.x - punct1.x) + (colt_opus.y - punct1.y) * (colt_opus.y - punct1.y));

	if (paralele == 0 || latura_verificare!=latura)
	{
		valid = 0;
		cout << "Trapezul nu este valid";
	}
	else
	{
		cout << "Trapezul este valid";
	}
}

float trapez::arie()
{
	try
	{
		if (valid == 0)
		{
			throw 1;
		}
	}
	catch (int)
	{
		cout << "Rombul nu este valid!";
		return NULL;
	}

	punct punct3, punct4;

	punct3.x = colt_opus.x - baza2;
	punct3.y = stanga_jos.y;

	punct4.x = punct3.x;
	punct4.y = colt_opus.y;

	float inaltime;

	inaltime = sqrt((punct3.x - punct4.x) * (punct3.x - punct4.x) + (punct3.y - punct4.y) * (punct3.y - punct4.y));

	return (baza2 + latura2) * inaltime / 2.0;
}

trapez::trapez() :paralelogram()
{
	baza2 = 0;
}

trapez::trapez(float x1, punct pct, punct pct2, float x2, float x3) : paralelogram(x1, pct, pct2, x2), patrat(pct, x1)
{
	baza2 = x3;

	punct colt1, colt2;

	colt1.x = stanga_jos.x + latura;
	colt1.y = stanga_jos.y;

	colt2.x = colt_opus.x - latura;
	colt2.y = colt_opus.y;

	float panta1, panta2;

	panta1 = (colt1.y - stanga_jos.y) / (colt1.x - stanga_jos.x);
	panta2 = (colt2.y - colt_opus.y) / (colt2.x - colt_opus.x);

	if ((panta1 == panta2) && (panta1 == 0))
	{
		paralele = 1;
	}
}

trapez::trapez(trapez& ob) : paralelogram(ob)
{
	baza2 = ob.baza2;
}

trapez& trapez::operator=(trapez& ob)
{
	if (this != &ob)
	{
		paralelogram::operator=(ob);
		baza2 = ob.baza2;
	}
	return *this;
}

istream& operator>>(istream& in, trapez& ob)
{
	in >> (paralelogram&)ob;
	cout << "Vom avea nevoie si de baza mica:";
	in >> ob.baza2;
	return in;
}

ostream& operator<<(ostream& out, trapez& ob)
{
	out << (paralelogram&)ob;
	out << ob.baza2;
	return out;
}

void meniu()
{
	int alegere, x, y, latura, latime, lungime, bazaMare, bazaMica;
	bool merge_meniu=true;
	while (merge_meniu)
	{
		system("CLS");
		cout << "                                WELCOME TO FORME GEOMETRICE SIMULATOR\n";
		cout << "CHOOSE AN ACTION:\n";
		cout << "1.Creati o forma geometrica noua.\n";
		cout << "2.Citirea informatiilor complete a n obiecte(de diferite tipuri), memorarea si afisarea acestora.\n";
		cout << "3.Leave\n";

		cout << "Action:";
		cin >> alegere;

		if (alegere == 1)
		{
			int alegere1;
			bool merge_submeniu = true;
			system("CLS");
			while (merge_submeniu)
			{
				system("CLS");

				cout << "Alegeti forma geometrica dorita\n";
				cout << "1.Patrat\n";
				cout << "2.Dreptunghi\n";
				cout << "3.Romb\n";
				cout << "4.Paralelogram\n";
				cout << "5.Trapez\n";
				cout << "6.Leave\n\n";

				cout << "Alegere:";
				cin >> alegere1;

				if (alegere1 == 1)
				{
					int alegerePatrat;
					bool while_patrat = true;
					system("CLS");

					cout << "Vom avea nevoie de coordonatele punctului stanga_jos al patratului:\n";
					cout << "abscisa:";
					cin >> x;
					cout << "\nordonata:";
					cin >> y;

					system("CLS");

					punct punctulet(x, y);

					cout << "Vom avea nevoie de lungimea laturii patratului:";
					cin >> latura;

					patrat patratel(punctulet, latura);

					while (while_patrat)
					{
						system("CLS");
						cout << "1.Verificati daca Patratul este valid\n";
						cout << "2.Afisati aria patratului(Daca este valid)\n";
						cout << "3.Leave\n\n";

						cout << "Alegere:";
						cin >> alegerePatrat;

						if (alegerePatrat == 1)
						{
							system("CLS");
							patratel.validitate();
							Sleep(5000);
						}
						else if (alegerePatrat == 2)
						{
							system("CLS");
							float arie = patratel.arie();
							if (arie != 0)
								cout << arie;
							Sleep(5000);
						}
						else
						{
							while_patrat = false;
						}
					}

				}
				else if (alegere1 == 2)
				{
					int alegereDreptunghi;
					bool while_dreptunghi = true;
					system("CLS");

					cout << "Vom avea nevoie de coordonatele punctului stanga_jos al dreptunghiului:\n";
					cout << "abscisa:";
					cin >> x;
					cout << "\nordonata:";
					cin >> y;

					system("CLS");

					punct punctulet(x, y);

					cout << "Vom avea nevoie de marimea latimii si lungimii dreptunghiului:";
					cin >> latime >> lungime;

					dreptunghi dreptunghiulet(punctulet, latime, lungime);

					while (while_dreptunghi)
					{
						system("CLS");
						cout << "1.Verificati daca Dreptunghiul este valid\n";
						cout << "2.Afisati aria dreptunghiului(Daca este valid)\n";
						cout << "3.Leave\n\n";

						cout << "Alegere:";
						cin >> alegereDreptunghi;

						if (alegereDreptunghi == 1)
						{
							system("CLS");
							dreptunghiulet.validitate();
							Sleep(5000);
						}
						else if (alegereDreptunghi == 2)
						{
							system("CLS");
							float arie = dreptunghiulet.arie();
							if (arie != 0)
								cout << arie;
							Sleep(5000);
						}
						else
						{
							while_dreptunghi = false;
						}
					}
				}
				else if (alegere1 == 3)
				{
					int alegereRomb;
					bool while_romb = true;
					system("CLS");

					cout << "Vom avea nevoie de coordonatele punctului stanga_jos al rombului:\n";
					cout << "abscisa:";
					cin >> x;
					cout << "\nordonata:";
					cin >> y;

					system("CLS");

					punct punctulet1(x, y);

					cout << "Vom avea nevoie de coordonatele punctului opus al rombului:\n";
					cout << "abscisa:";
					cin >> x;
					cout << "\nordonata:";
					cin >> y;

					system("CLS");

					punct punctulet2(x, y);
					
					cout << "Vom avea nevoie de marimea laturii rombului:";
					cin >> latura;

					romb rombulet(punctulet1, punctulet2,  latura);

					while (while_romb)
					{
						system("CLS");
						cout << "1.Verificati daca Rombul este valid\n";
						cout << "2.Afisati aria rombului(Daca este valid)\n";
						cout << "3.Leave\n\n";

						cout << "Alegere:";
						cin >> alegereRomb;

						if (alegereRomb == 1)
						{
							system("CLS");
							rombulet.validitate();
							Sleep(5000);
						}
						else if (alegereRomb == 2)
						{
							system("CLS");
							float arie = rombulet.arie();
							if (arie != 0)
								cout << arie;
							Sleep(5000);
						}
						else
						{
							while_romb = false;
						}
					}
				}
				else if (alegere1 == 4)
				{
					int alegereParalelogram;
					bool while_paralelogram = true;
					system("CLS");

					cout << "Vom avea nevoie de coordonatele punctului stanga_jos al paralelogramului:\n";
					cout << "abscisa:";
					cin >> x;
					cout << "\nordonata:";
					cin >> y;

					system("CLS");

					punct punctulet1(x, y);

					cout << "Vom avea nevoie de coordonatele punctului opus al paralelogramului:\n";
					cout << "abscisa:";
					cin >> x;
					cout << "\nordonata:";
					cin >> y;

					system("CLS");

					punct punctulet2(x, y);
					
					cout << "Vom avea nevoie de marimea latimii si lungimii paralelogramului:";
					cin >> latime >> lungime;

					paralelogram paralelogramulet(latime, punctulet1, punctulet2, lungime);

					while (while_paralelogram)
					{
						system("CLS");
						cout << "1.Verificati daca Paralelogramul este valid\n";
						cout << "2.Afisati aria Paralelogramului(Daca este valid)\n";
						cout << "3.Leave\n\n";

						cout << "Alegere:";
						cin >> alegereParalelogram;

						if (alegereParalelogram == 1)
						{
							system("CLS");
							paralelogramulet.validitate();
							Sleep(5000);
						}
						else if (alegereParalelogram == 2)
						{
							system("CLS");
							float arie = paralelogramulet.arie();
							if (arie != 0)
								cout << arie;
							Sleep(5000);
						}
						else
						{
							while_paralelogram = false;
						}
					}
				}
				else if (alegere1 == 5)
				{
					int alegereTrapez;
					bool while_trapez = true;
					system("CLS");

					cout << "Vom avea nevoie de coordonatele punctului stanga_jos al trapezului:\n";
					cout << "abscisa:";
					cin >> x;
					cout << "\nordonata:";
					cin >> y;

					system("CLS");

					punct punctulet1(x, y);

					cout << "Vom avea nevoie de coordonatele punctului opus al trapezului:\n";
					cout << "abscisa:";
					cin >> x;
					cout << "\nordonata:";
					cin >> y;
	
					system("CLS");

					punct punctulet2(x, y);

					cout << "Vom avea nevoie de marimea Bazei mari si laturii trapezului:";
					cin >> bazaMare >> latura;

					cout << "Vom avea nevoie si de marimea bazei mici a trapezului";

					cin >> bazaMica;

					trapez trapezulet(latura, punctulet1, punctulet2, bazaMare, bazaMica);

					while (while_trapez)
					{
						system("CLS");
						cout << "1.Verificati daca Paralelogramul este valid\n";
						cout << "2.Afisati aria Paralelogramului(Daca este valid)\n";
						cout << "3.Leave\n\n";
	
						cout << "Alegere:";
						cin >> alegereTrapez;

						if (alegereTrapez == 1)
						{
							system("CLS");
							trapezulet.validitate();
							Sleep(5000);
						}
						else if (alegereTrapez == 2)
						{
							system("CLS");
							float arie = trapezulet.arie();
							if (arie != 0)
								cout << arie;
							Sleep(5000);
						}
						else
						{
							while_trapez = false;
						}
					}
				}
				else
				{
					merge_submeniu = 0;
				}
			}
		}
		else if (alegere == 2)
		{
			system("CLS");
			int n, alegeree;

			cout << "Cate obiecte doriti sa stocati?\n";
			cin >> n;

			patrat** v;
			v = new patrat * [n];

			system("CLS");

			for (int i = 0; i < n; i++)
			{
				system("CLS");

				cout << "Ce obiect doriti sa stocati?\n";

				cout << "1.Patrat\n";
				cout << "2.Dreptunghi\n";
				cout << "3.Romb\n";
				cout << "4.Paralelogram\n";
				cout << "5.Trapez\n";

				cin >> alegeree;

				system("CLS");

				if (alegeree == 1)
				{
					v[i] = new patrat();
					cin >> *dynamic_cast<patrat*>(v[i]);
				}
				else if (alegeree == 2)
				{
					
					v[i] = new dreptunghi();
					cin >> *dynamic_cast<dreptunghi*>(v[i]);
					
				}
				else if (alegeree == 3)
				{
					v[i] = new romb();
					cin >> *dynamic_cast<romb*>(v[i]);
				}
				else if (alegeree == 4)
				{
					v[i] = new paralelogram();
					cin >> *dynamic_cast<paralelogram*>(v[i]);
				}
				else if (alegeree == 5)
				{
					v[i] = new trapez();
					cin >> *dynamic_cast<trapez*>(v[i]);
				}
			}

			system("CLS");

			for (int i = 0; i < n; i++)
			{
				cout << "Forma geometrica " << i << ":\n";
				if (typeid(*v[i])==typeid(patrat))
				{
					cout << *dynamic_cast<patrat*>(v[i]);
				}
				else if (typeid(*v[i]) == typeid(dreptunghi))
				{

				
					cout << *dynamic_cast<dreptunghi*>(v[i]);

				}
				else if (typeid(*v[i]) == typeid(romb))
				{
				
					cout << *dynamic_cast<romb*>(v[i]);
				}
				else if (typeid(*v[i]) == typeid(paralelogram))
				{
					
					cout << *dynamic_cast<paralelogram*>(v[i]);
				}
				else if (typeid(*v[i]) == typeid(trapez))
				{
					cout << *dynamic_cast<trapez*>(v[i]);
				}
			}

			Sleep(10000);

		}
		else
		{
			merge_meniu = false;
		}

	}
}

int main()
{
	meniu();
	return 0;
}
