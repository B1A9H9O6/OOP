#include<iostream>

using namespace std;
//DZ-1============================================================
class Figure
{
public:
	Figure() = default;
	virtual void area()  = 0;
	virtual void printName()  = 0;
	
};

class Parallelogram 
{
public:
	
	virtual void printName()=0 ;
	virtual void area() =0;
};

class Circle : public Figure
{
public:
	Circle(double _R) : R(_R){}
	virtual void printName() override { cout << "Circle : "; };
	virtual void area() override { cout << 3.14 * R * R << endl; };
private:
	double R;
};  

class Rectangle : public Parallelogram
{
private:
	double a1, b2;
public:
	Rectangle(double _a1, double _b2): a1(_a1), b2(_b2) {}
	virtual void printName() override { cout << "Rectangle : "; };
	virtual void area() override { cout << a1*b2<<endl; };
};

class Square : public Parallelogram
{
private:
	double a;
public:
	Square(double _a): a(_a) {}
	virtual void printName() override { cout << "Square : "; };
	virtual void area() override { cout << a *a<<endl; };
};

class Rhombus : public Parallelogram
{
private:
	double a,b;
public:
	Rhombus(double _a, double _b) : a(_a), b(_b) {}
	virtual void printName() override { cout << "Rhombus : "; };
	virtual void area() override { cout << a * b << endl; };
	
};
//=================================================================

//DZ-2=============================================================
class Car
{
public:
	void compani(){}
	void model(){}
	Car() { cout << __FUNCTION__ << endl; }
};

class PassengerCar :virtual public Car
{
public:
	PassengerCar() { cout << __FUNCTION__ << endl; }
};

class Bus :virtual public Car
{
public:
	Bus() { cout << __FUNCTION__ << endl; }
};

class Minivan : public PassengerCar , public Bus
{
public:
	Minivan() { cout << __FUNCTION__ << endl; }
};
//=================================================================

//DZ-3=============================================================
class Fraction
{
	int a, b;
public:
	Fraction(int _a =1, int _b =1): a(_a), b(_b) { if (b == 0)cout << "ERROR" << endl; }
	void print()
	{
		cout<<"= " << a << "/" << b << endl;
	}
	friend Fraction operator + (const Fraction& f1, const Fraction& f2)
	{
		if ((f1.b == 0) || (f2.b == 0))
		{
			cout << "ERROR" << endl;
			return 0;
		}
		return Fraction(f1.a * f2.b + f2.a * f1.b, f1.b * f2.b);
	}
	friend Fraction operator - (const Fraction& f1, const Fraction& f2)
	{
		if  ((f1.b == 0) || (f2.b == 0))
		{
			cout << "ERROR" << endl;
			return 0;
		}
		return Fraction(f1.a * f2.b - f2.a - f1.b, f1.b * f2.b);
	}
	friend Fraction operator * (const Fraction& f1, const Fraction& f2)
	{
		if ((f1.b == 0) || (f2.b == 0))
		{
			cout << "ERROR" << endl;
			return 0;
		}
		return Fraction(f1.a * f2.a , f2.b * f1.b);
	}
	friend Fraction operator / (const Fraction& f1, const Fraction& f2)
	{
		if ((f1.b == 0) || (f2.b == 0))
		{
			cout << "ERROR" << endl;
			return 0;
		}
		return Fraction(f1.a / f2.b, f2.a / f1.b);
	}
};
//DZ-4=============================================================

class Card
{
public:
	enum Suit
	{
		clubs = 1,	
		diamonds,	
		hearts,		
		spades
	};
	enum valueCard
	{
		A = 1, _2, _3, _4, _5, _6, _7, _8, _9, _10,
		J=10, Q=10, K=10
		
	};
	void mapPos()
	{
		bool map = false;
	}
	void Flip(bool _map)
	{
		if (_map == false)
			_map = true;
		else
			_map = false;
	}
	//=============================================================
};
int main()
{
	//DZ-1=========================================================
	Circle C1(10);
	C1.printName();
	C1.area();

	Rectangle P1(5, 7);
	P1.printName();
	P1.area();

	Square S1(5);
	S1.printName();
	S1.area();

	Rhombus P2(5,8);
	P2.printName();
	P2.area();
	//=============================================================

	//DZ-2=========================================================
	Minivan A;
	//=============================================================

	//DZ-3=========================================================
	Fraction f1(20, 30);
	Fraction f2(30, 30);
	Fraction f3;
	f3 = f1 + f2;
	f3.print();
	
	f3 = f1 - f2;
	f3.print();

	f3 = f1 * f2;
	f3.print();

	f3 = f1 / f2;
	f3.print();
	return 0;
}