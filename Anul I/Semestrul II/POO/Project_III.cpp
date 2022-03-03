#include <iostream>
#include <math.h>
#include <string>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <vector>
using namespace std;

//PROTOTIPURI

template <class T>
class punct;

template <class T = float>
istream& operator>> (istream&, punct<T>&);

template <class T = float>
ostream& operator<< (ostream&, punct<T>&);


template <class A>
class patrat;

template <class A = float>
istream& operator>> (istream&, patrat<A>&);

template <class A = float>
ostream& operator<< (ostream&, patrat<A>&);


template <class C>
class dreptunghi;

template <class C = float>
istream& operator>> (istream&, dreptunghi<C>&);

template <class C = float>
ostream& operator<< (ostream&, dreptunghi<C>&);

template <class B>
class romb;

template <class B = float>
istream& operator>> (istream&, romb<B>&);

template <class B = float>
ostream& operator<< (ostream&, romb<B>&);

template <class D>
class paralelogram;

template <class D = float>
istream& operator>> (istream&, paralelogram<D>&);

template <class D = float>
ostream& operator<< (ostream&, paralelogram<D>&);

template <class F>
class trapez;

template <class F = float>
istream& operator>> (istream&, trapez<F>&);

template <class F = float>
ostream& operator<< (ostream&, trapez<F>&);

//**************************************************PUNCT***************************************************
template <class T = float>
class punct {
protected:
	T x, y;
public:
	punct();
	punct(T, T);
	punct(const punct<T>&);
	~punct();
	punct<T>& operator= (punct<T>&);
	friend istream& operator>> <>(istream&, punct<T>&);
	friend ostream& operator<< <>(ostream&, punct<T>&);
	template <class> friend class patrat;
	template <class> friend class romb;
	template <class> friend class paralelogram;
	template <class> friend class trapez;
};

template <class T>
punct<T>::punct()
{
	x = 0;
	y = 0;
}

template <class T>
punct<T>::punct(T a, T b)
{
	x = a;
	y = b;
}

template <class T>
punct<T>::punct(const punct<T>& ob)
{
	x = ob.x;
	y = ob.y;
}

template <class T>
punct<T>& punct<T>::operator=(punct<T>& ob)
{
	if (this != &ob)
	{
		x = ob.x;
		y = ob.y;
	}
	return *this;
}

template <class T >
istream& operator>>(istream& in, punct<T> &ob)
{
	in >> ob.x >> ob.y;
	return in;
}

template <class T >
ostream& operator<<(ostream& out, punct<T> &ob)
{
	out << ob.x << ',' << ob.y << "\n";
	return out;
}

template <class T >
punct<T>::~punct()
{
	//cout<<destructor;
}
//*************************************************PATRAT*************************************************
template <class A = float>
class patrat {
protected:
	punct<A> stanga_jos;
	A latura;
	bool valid = 1;
	static int nrPatrate;
public:
	patrat();
	patrat(punct<A>, A);
	patrat(patrat<A>&);
	~patrat();
	patrat<A>& operator=(patrat<A>&);
	friend istream& operator>> <>(istream&, patrat<A>&);
	friend ostream& operator<< <>(ostream&, patrat<A>&);
	virtual void citire();
	virtual void afisare();
	virtual float arie();
	void validitate();
	static void showNrPatrate();
	//	void get_validitate();
};

template <class A>
void patrat<A>::citire()
{
	int x, y;
	cout << "Vom avea nevoie de coordonatele punctului stanga_jos al patratului:\n";
	cout << "abscisa:";
	cin >> x;
	cout << "\nordonata:";
	cin >> y;
	punct<A> pct(x, y);
	stanga_jos = pct;
	cout << "\nVom avea nevoie si de latura patratului:";
	cin >> latura;
}
template <class A>
void patrat<A>::afisare()
{
	cout << "Coordonate pct 1:";
	cout << stanga_jos.x << ' ' << stanga_jos.y << "\n";
	cout << "Latime:" << latura;
}
template <class A>
int patrat<A>::nrPatrate;

template <class A>
void patrat<A>::showNrPatrate()
{
	cout << nrPatrate;
}

template <class A>
void patrat<A>::validitate()
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

template <class A>
float patrat<A>::arie()
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

template <class A>
patrat<A>::patrat()
{
	stanga_jos.x = 0;
	stanga_jos.y = 0;
	latura = 0;
}

template <class A>
patrat<A>::patrat(punct<A> ob, A x)
{
	stanga_jos = ob;
	latura = x;
	nrPatrate++;
}

template <class A>
patrat<A>::patrat(patrat<A>& ob)
{
	stanga_jos = ob.stanga_jos;
	latura = ob.latura;
}

template <class A>
patrat<A>& patrat<A>::operator=(patrat<A>& ob)
{
	if (this != &ob)
	{
		stanga_jos = ob.stanga_jos;
		latura = ob.latura;
	}
	return *this;
}

template <class A>
istream& operator>>(istream& in, patrat<A> &ob)
{
	cout << "Vom avea nevoie de abscisa si ordonata punctului stanga_jos:";
	in >> ob.stanga_jos;
	system("CLS");
	cout << "Vom avea nevoie de lungimea primei laturi:";
	in >> ob.latura;
	return in;
}

template <class A>
ostream& operator<<(ostream& out, patrat<A> &ob)
{
	out << ob.stanga_jos;
	out << ob.latura << "\n";
	return out;
}

template <class A>
patrat<A>::~patrat()
{
	//cout<<"destructor";
}

//*************************************************Dreptunghi*************************************************

template <class C = float>
class dreptunghi :virtual public patrat<C> {
protected:
	C latura2;
	bool valid = 1;
public:
	dreptunghi();
	dreptunghi(punct<C>, C, C);
	dreptunghi(dreptunghi<C>&);
	~dreptunghi();
	dreptunghi<C>& operator= (dreptunghi<C>&);
	virtual void citire();
	virtual void afisare();
	friend istream& operator>> <>(istream&, dreptunghi<C>&);
	friend ostream& operator<< <>(ostream&, dreptunghi<C>&);
	void validitate();
	virtual float arie();
	//	void get_validitate();
};

template <class C>
void dreptunghi<C>::citire()
{
	C x, y;
	cout << "Vom avea nevoie de coordonatele punctului stanga_jos al dreptunghiului:\n";
	cout << "abscisa:";
	cin >> x;
	cout << "\nordonata:";
	cin >> y;

	punct<C> punctulet(x, y);
	patrat<C>::stanga_jos = punctulet;

	cout << "Vom avea nevoie de marimea latimii si lungimii dreptunghiului:";
	cin >> patrat<C>::latura >> latura2;
}

template <class C>
void dreptunghi<C>::afisare()
{
	cout << "Laturi:" << patrat<C>::latura << ' ' << latura2 << "\n" << "Coordonate punct:";
	cout << patrat<C>::stanga_jos;
}

template <class C>
void dreptunghi<C>::validitate()
{
	if (patrat<C>::latura < 0 || latura2 < 0)
	{
		valid = 0;
		cout << "Dreptunghiul nu este valid";
	}
	else
	{
		cout << "Dreptunghiul este valid!";
	}
}

template <class C>
float dreptunghi<C>::arie()
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
	return patrat<C>::latura * latura2;
}

template <class C>
dreptunghi<C>::dreptunghi() :patrat<C>()
{
	latura2 = 0;
}

template <class C>
dreptunghi<C>::dreptunghi(punct<C> pct, C x1, C x2) : patrat<C>(pct, x1)
{
	latura2 = x2;
}

template <class C>
dreptunghi<C>::dreptunghi(dreptunghi<C>& ob) : patrat<C>(ob)
{
	latura2 = ob.latura2;
}

template <class C>
dreptunghi<C>& dreptunghi<C>::operator=(dreptunghi<C>& ob)
{
	if (this != &ob)
	{
		patrat<C>::operator=(ob);
		latura2 = ob.latura2;
	}
	return *this;
}

template <class C>
istream& operator>> (istream& in, dreptunghi<C>& ob)
{
	in >> (patrat<C>&)ob;
	cout << "Vom avea nevoie si de lungimea laturii 2:";
	in >> ob.latura2;
	return in;
}

template <class C>
ostream& operator<< (ostream& out, dreptunghi<C>& ob)
{
	out << (patrat<C>&)ob;
	out << ob.latura2;
	out << "\n";
	return out;
}

template <class C>
dreptunghi<C>::~dreptunghi()
{
	//cout<<"destructor";
}

//*************************************************Romb*************************************************

template <class B = float>
class romb :virtual public patrat<B> {
protected:
	punct<B> colt_opus;
	bool valid = 1;
	bool paralele = 0;
public:
	romb();
	romb(punct<B>, punct<B>, B);
	romb(romb<B>&);
	~romb();
	romb<B>& operator= (romb<B>&);
	virtual void afisare();
	virtual void citire();
	friend istream& operator>> <>(istream&, romb<B>&);
	friend ostream& operator<< <>(ostream&, romb<B>&);
	void validitate();
	virtual float arie();
	//	void get_validitate();
};

template <class B>
void romb<B>::afisare()
{
	cout << "Punct1:" << patrat<B>::stanga_jos;
	cout << "Punct2:" << colt_opus;

	cout << "Latura:" << patrat<B>::latura;
}

template <class B>
void romb<B>::citire()
{
	B x1, y1, x2, y2;
	cout << "Coordonatele primului punct:";
	cin >> x1 >> y1;
	punct<B> pctt(x1, y1);
	patrat<B>::stanga_jos = pctt;

	cout << "\nCoordonatele celui de-al doilea punct:";
	cin >> x2 >> y2;
	punct<B> pct(x2, y2);
	colt_opus = pct;

	cout << "\nLatura:";
	cin >> patrat<B>::latura;
}

template <class B>
void romb<B>::validitate()
{
	B latura_verificare;
	punct<B> punct3, punct4;

	punct3.x = patrat<B>::stanga_jos.x + patrat<B>::latura;
	punct3.y = patrat<B>::stanga_jos.y;

	latura_verificare = sqrt((colt_opus.x - punct3.x) * (colt_opus.x - punct3.x) + (colt_opus.y - punct3.y) * (colt_opus.y - punct3.y));

	if (patrat<B>::latura != latura_verificare || patrat<B>::latura < 0 || paralele == 0)
	{
		valid = 0;
		cout << "Rombul nu este valid";
	}
	else
	{
		cout << "Rombul este valid";
	}

}

template <class B>
float romb<B>::arie()
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

	punct<B> punct3, punct4;

	B diagonala1, diagonala2;

	punct3.x = patrat<B>::stanga_jos.x + patrat<B>::latura;
	punct3.y = patrat<B>::stanga_jos.y;

	punct4.x = colt_opus.x - patrat<B>::latura;
	punct4.y = colt_opus.y;

	diagonala1 = sqrt((colt_opus.x - patrat<B>::stanga_jos.x) * (colt_opus.x - patrat<B>::stanga_jos.x) + (colt_opus.y - patrat<B>::stanga_jos.y) * (colt_opus.y - patrat<B>::stanga_jos.y));
	diagonala2 = sqrt((punct3.x - punct4.x) * (punct3.x - punct4.x) + (punct3.y - punct4.y) * (punct3.y - punct4.y));

	return ((diagonala1 * diagonala2) / 2.0);
}

template <class B>
romb<B>::romb() :patrat<B>()
{
	colt_opus.x = 0;
	colt_opus.y = 0;
}

template <class B>
romb<B>::romb(punct<B> pct, punct<B> pct2, B x1) : patrat<B>(pct, x1)
{
	colt_opus = pct2;

	punct<B> colt1, colt2;

	colt1.x = patrat<B>::stanga_jos.x + patrat<B>::latura;
	colt1.y = patrat<B>::stanga_jos.y;

	colt2.x = colt_opus.x - patrat<B>::latura;
	colt2.y = colt_opus.y;

	B panta1, panta2;

	panta1 = (colt1.y - patrat<B>::stanga_jos.y) / (colt1.x - patrat<B>::stanga_jos.x);
	panta2 = (colt2.y - colt_opus.y) / (colt2.x - colt_opus.x);

	if ((panta1 == panta2) && (panta1 == 0))
	{
		paralele = 1;
	}

}

template <class B>
romb<B>::romb(romb<B>& ob) : patrat<B>(ob)
{
	colt_opus = ob.colt_opus;
}

template <class B>
romb<B>& romb<B>::operator=(romb<B>& ob)
{
	if (this != &ob)
	{
		patrat<B>::operator=(ob);
		colt_opus = ob.colt_opus;
	}
	return *this;
}

template <class B>
istream& operator>>(istream& in, romb<B>& ob)
{
	in >> (patrat<B>&)ob;
	cout << "Vom avea nevoie si de coordonatele puncului opus:";
	in >> ob.colt_opus;
	return in;
}

template <class B>
ostream& operator<<(ostream& out, romb<B>& ob)
{
	out << (patrat<B>&)ob;
	out << ob.colt_opus;
	out << "\n";
	return out;
}

template <class B>
romb<B>::~romb()
{
	//cout<<"destructor";
}

//**********************************************************PARALELOGRAM***************************************

template <class D>
class paralelogram : public dreptunghi<D>, public romb<D> {
protected:
	bool valid = 1;
	bool paralele = 0;
public:
	paralelogram() :dreptunghi<D>(), romb<D>() {};
	paralelogram(D x, punct<D> pct1, punct<D> pct2, D y) :dreptunghi<D>(pct1, x, y), romb<D>(pct1, pct2, x), patrat<D>(pct1, x) {
		punct<D> colt1, colt2;

		colt1.x = patrat<D>::stanga_jos.x + patrat<D>::latura;
		colt1.y = patrat<D>::stanga_jos.y;

		colt2.x = romb<D>::colt_opus.x - patrat<D>::latura;
		colt2.y = romb<D>::colt_opus.y;

		float panta1, panta2;

		panta1 = (colt1.y - patrat<D>::stanga_jos.y) / (colt1.x - patrat<D>::stanga_jos.x);
		panta2 = (colt2.y - romb<D>::colt_opus.y) / (colt2.x - romb<D>::colt_opus.x);

		if ((panta1 == panta2) && (panta1 == 0))
		{
			paralele = 1;
		}
	};
	paralelogram(paralelogram<D>& ob) :dreptunghi<D>(ob), romb<D>(ob) {};
	~paralelogram();
	paralelogram<D>& operator= (paralelogram<D>&);
	friend istream& operator>> <>(istream&, paralelogram<D>&);
	friend ostream& operator<< <>(ostream&, paralelogram<D>&);
	virtual void afisare();
	virtual void citire();
	void validitate();
	virtual float arie();
	//void get_validitate();
};

template <class D>
void paralelogram<D>::citire()
{
	D x1, y1, x2, y2;
	cout << "Coordonatele primului punct:";
	cin >> x1 >> y1;
	punct<D> pct(x1, y1);
	patrat<D>::stanga_jos = pct;

	cout << "\nCoordonatele celui de-al doilea punct:";
	cin >> x2 >> y2;
	punct<D> pcttt(x2, y2);
	romb<D>::colt_opus = pcttt;

	cout << "\nLatime:";
	cin >> patrat<D>::latura;

	cout << "\nLungime:";
	cin >> dreptunghi<D>::latura2;
}

template <class D>
void paralelogram<D>::afisare()
{
	cout << "Punct1:" << patrat<D>::stanga_jos;
	cout << "Punct2:" << romb<D>::colt_opus;

	cout << "Latime:" << patrat<D>::latura;
	cout << "\nLungime:" << dreptunghi<D>::latura2;
}

template <class D>
void paralelogram<D>::validitate()
{

	float latura_verificare;
	punct<D> punct3, punct4;

	punct3.x = patrat<D>::stanga_jos.x + patrat<D>::latura;
	punct3.y = patrat<D>::stanga_jos.y;

	latura_verificare = sqrt((romb<D>::colt_opus.x - punct3.x) * (romb<D>::colt_opus.x - punct3.x) + (romb<D>::colt_opus.y - punct3.y) * (romb<D>::colt_opus.y - punct3.y));


	if (patrat<D>::latura != latura_verificare || patrat<D>::latura < 0 || paralele == 0)
	{
		valid = 0;
		cout << "Paralaelogramul nu este valid!";
	}
	else
	{
		cout << "Paralelogramul este valid";
	}
}

template <class D>
float paralelogram<D>::arie()
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

	diagonala = sqrt((romb<D>::colt_opus.x - patrat<D>::stanga_jos.x) * (romb<D>::colt_opus.x - patrat<D>::stanga_jos.x) + (romb<D>::colt_opus.y - patrat<D>::stanga_jos.y) * (romb<D>::colt_opus.y - patrat<D>::stanga_jos.y));

	p = (patrat<D>::latura + dreptunghi<D>::latura2 + diagonala) / 2.0;
	return (2 * sqrt(p * (p - patrat<D>::latura) * (p - dreptunghi<D>::latura2) * (p - diagonala)));
}

template <class D>
paralelogram<D>& paralelogram<D>::operator=(paralelogram<D>& ob)
{
	if (this != &ob)
	{
		dreptunghi<D>::operator=(ob);
		romb<D>::operator=(ob);

	}
	return *this;
}

template <class D>
istream& operator>>(istream& in, paralelogram<D>& ob)
{

	in >> (dreptunghi<D>&)ob;
	cout << "Vom avea nevoie si de coordonatele punctului opus:";
	in >> ob.colt_opus;
	return in;
}

template <class D>
ostream& operator<<(ostream& out, paralelogram<D>& ob)
{

	out << (dreptunghi<D>&)ob;
	out << ob.colt_opus;
	return out;
}

template <class D>
paralelogram<D>::~paralelogram()
{
	//cout<<"PArelalogram";
}
//****************************************************TRAPEZ*****************************************

template <class F>
class trapez : public paralelogram<F> {
private:
	float baza2;
	bool valid = 1;
	bool paralele = 0;
public:
	trapez();
	trapez(F, punct<F>, punct<F>, F, F);
	trapez(trapez<F>&);
	trapez& operator=(trapez<F>&);
	~trapez(){/*cout<<"TRAPEZ;*/}
	friend istream& operator>> <>(istream&, trapez<F>&);
	friend ostream& operator<< <>(ostream&, trapez<F>&);
	virtual void afisare();
	virtual void citire();
	void validitate();
	virtual float arie();
};

template <class F>
void trapez<F>::citire()
{
	F x1, y1, x2, y2;
	cout << "Coordonatele primului punct:";
	cin >> x1 >> y1;
	punct<F> pct(x1, y1);
	patrat<F>::stanga_jos = pct;

	cout << "\nCoordonatele celui de-al doilea punct:";
	cin >> x2 >> y2;
	punct<F> pctttt(x2, y2);
	romb<F>::colt_opus = pctttt;

	cout << "\nLatura:";
	cin >> patrat<F>::latura;

	cout << "\nBaza Mare:";
	cin >> dreptunghi<F>::latura2;

	cout << "\nBaza Mica:";
	cin >> baza2;
}

template <class F>
void trapez<F>::afisare()
{
	cout << "Punct1:" << patrat<F>::stanga_jos;
	cout << "Punct2:" << romb<F>::colt_opus;

	cout << "Latura:" << patrat<F>::latura;
	cout << "\nBaza mare:" << dreptunghi<F>::latura2;
	cout << "\nBaza mica:" << baza2;
}

template <class F>
void trapez<F>::validitate()
{
	punct<F> punct1;

	punct1.x = patrat<F>::stanga_jos.x + dreptunghi<F>::latura2;
	punct1.y = patrat<F>::stanga_jos.y;

	float latura_verificare;

	latura_verificare = sqrt((romb<F>::colt_opus.x - punct1.x) * (romb<F>::colt_opus.x - punct1.x) + (romb<F>::colt_opus.y - punct1.y) * (romb<F>::colt_opus.y - punct1.y));

	if (paralele == 0 || latura_verificare != patrat<F>::latura)
	{
		valid = 0;
		cout << "Trapezul nu este valid";
	}
	else
	{
		cout << "Trapezul este valid";
	}
}

template <class F>
float trapez<F>::arie()
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
		cout << "Trapezul nu este valid!";
		return NULL;
	}

	punct<F> punct3, punct4;

	punct3.x = romb<F>::colt_opus.x - baza2;
	punct3.y = patrat<F>::stanga_jos.y;

	punct4.x = punct3.x;
	punct4.y = romb<F>::colt_opus.y;

	float inaltime;

	inaltime = sqrt((punct3.x - punct4.x) * (punct3.x - punct4.x) + (punct3.y - punct4.y) * (punct3.y - punct4.y));

	return (baza2 + dreptunghi<F>::latura2) * inaltime / 2.0;
}

template <class F>
trapez<F>::trapez() :paralelogram<F>()
{
	baza2 = 0;
}

template <class F>
trapez<F>::trapez(F x1, punct<F> pct, punct<F> pct2, F x2, F x3) : paralelogram<F>(x1, pct, pct2, x2), patrat<F>(pct, x1)
{
	baza2 = x3;

	punct<F> colt1, colt2;

	colt1.x = patrat<F>::stanga_jos.x + patrat<F>::latura;
	colt1.y = patrat<F>::stanga_jos.y;

	colt2.x = romb<F>::colt_opus.x - patrat<F>::latura;
	colt2.y = romb<F>::colt_opus.y;

	float panta1, panta2;

	panta1 = (colt1.y - patrat<F>::stanga_jos.y) / (colt1.x - patrat<F>::stanga_jos.x);
	panta2 = (colt2.y - romb<F>::colt_opus.y) / (colt2.x - romb<F>::colt_opus.x);

	if ((panta1 == panta2) && (panta1 == 0))
	{
		paralele = 1;
	}
}

template <class F>
trapez<F>::trapez(trapez<F>& ob) : paralelogram<F>(ob)
{
	baza2 = ob.baza2;
}

template <class F>
trapez<F>& trapez<F>::operator=(trapez<F>& ob)
{
	if (this != &ob)
	{
		paralelogram<F>::operator=(ob);
		baza2 = ob.baza2;
	}
	return *this;
}

template <class F>
istream& operator>>(istream& in, trapez<F>& ob)
{
	in >> (paralelogram<F>&)ob;
	cout << "Vom avea nevoie si de baza mica:";
	in >> ob.baza2;
	return in;
}

template <class F>
ostream& operator<<(ostream& out, trapez<F>& ob)
{
	out << (paralelogram<F>&)ob;
	out << ob.baza2;
	return out;
}

void meniu()
{
	int alegere, x, y, latura, latime, lungime, bazaMare, bazaMica;
	bool merge_meniu = true;
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

					punct<float> punctulet(x, y);

					cout << "Vom avea nevoie de lungimea laturii patratului:";
					cin >> latura;

					patrat<float> patratel(punctulet, latura);

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

					punct<float> punctulet(x, y);

					cout << "Vom avea nevoie de marimea latimii si lungimii dreptunghiului:";
					cin >> latime >> lungime;

					dreptunghi<float> dreptunghiulet(punctulet, latime, lungime);

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

					punct<float> punctulet1(x, y);

					cout << "Vom avea nevoie de coordonatele punctului opus al rombului:\n";
					cout << "abscisa:";
					cin >> x;
					cout << "\nordonata:";
					cin >> y;

					system("CLS");

					punct<float> punctulet2(x, y);

					cout << "Vom avea nevoie de marimea laturii rombului:";
					cin >> latura;

					romb<float> rombulet(punctulet1, punctulet2, latura);

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

					punct<float> punctulet1(x, y);

					cout << "Vom avea nevoie de coordonatele punctului opus al paralelogramului:\n";
					cout << "abscisa:";
					cin >> x;
					cout << "\nordonata:";
					cin >> y;

					system("CLS");

					punct<float> punctulet2(x, y);

					cout << "Vom avea nevoie de marimea latimii si lungimii paralelogramului:";
					cin >> latime >> lungime;

					paralelogram<float> paralelogramulet(latime, punctulet1, punctulet2, lungime);

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

					punct<float> punctulet1(x, y);

					cout << "Vom avea nevoie de coordonatele punctului opus al trapezului:\n";
					cout << "abscisa:";
					cin >> x;
					cout << "\nordonata:";
					cin >> y;

					system("CLS");

					punct<float> punctulet2(x, y);

					cout << "Vom avea nevoie de marimea Bazei mari si laturii trapezului:";
					cin >> bazaMare >> latura;

					cout << "Vom avea nevoie si de marimea bazei mici a trapezului";

					cin >> bazaMica;

					trapez<float> trapezulet(latura, punctulet1, punctulet2, bazaMare, bazaMica);

					while (while_trapez)
					{
						system("CLS");
						cout << "1.Verificati daca Trapezului este valid\n";
						cout << "2.Afisati aria Trapezului(Daca este valid)\n";
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

			//patrat** v;
			//v = new patrat * [n];

			vector<patrat<float>*> v(n);

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
					v[i] = new patrat<float>();
					cin >> *dynamic_cast<patrat<float>*>(v[i]);
				}
				else if (alegeree == 2)
				{

					v[i] = new dreptunghi<float>();
					cin >> *dynamic_cast<dreptunghi<float>*>(v[i]);

				}
				else if (alegeree == 3)
				{
					v[i] = new romb<float>();
					cin >> *dynamic_cast<romb<float>*>(v[i]);
				}
				else if (alegeree == 4)
				{
					v[i] = new paralelogram<float>();
					cin >> *dynamic_cast<paralelogram<float>*>(v[i]);
				}
				else if (alegeree == 5)
				{
					v[i] = new trapez<float>();
					cin >> *dynamic_cast<trapez<float>*>(v[i]);
				}
			}

			system("CLS");

			for (int i = 0; i < n; i++)
			{
				cout << "Forma geometrica " << i << ":\n";
				if (typeid(*v[i]) == typeid(patrat<float>))
				{
					cout << *dynamic_cast<patrat<float>*>(v[i]);
				}
				else if (typeid(*v[i]) == typeid(dreptunghi<float>))
				{


					cout << *dynamic_cast<dreptunghi<float>*>(v[i]);

				}
				else if (typeid(*v[i]) == typeid(romb<float>))
				{

					cout << *dynamic_cast<romb<float>*>(v[i]);
				}
				else if (typeid(*v[i]) == typeid(paralelogram<float>))
				{

					cout << *dynamic_cast<paralelogram<float>*>(v[i]);
				}
				else if (typeid(*v[i]) == typeid(trapez<float>))
				{
					cout << *dynamic_cast<trapez<float>*>(v[i]);
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
