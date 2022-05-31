#include <iostream>
#include <string>
#include <cstring>
#include<vector>
using namespace std;


//DZ-1==================================================
template<typename T>
class Pair1
{
public:
	Pair1(const T& _a, const T& _b) : a(_a), b(_b)
	{};

	T first() const { return a; };
	T second() const { return b; };

private:
	T a, b;
};
//=======================================================

//DZ-2===================================================
template<typename T1, typename T2>
class Pair
{
public:
	Pair(const T1& _a, const T2& _b) : a(_a), b(_b)
	{};

	T1 first() const { return a; };
	T2 second() const { return b; };

private:
	T1 a;
	T2 b;
};
//=======================================================

//DZ-3===================================================
template <typename T>
class StringValuePair : public Pair<string, T>
{
public:
	StringValuePair(const string& a, const T& b) : Pair<string, T>(a,b)
	{};
};
//========================================================
int main()
{
	//DZ-1===============================================
    Pair1<int> p1(6, 9);
    cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

    const Pair1<double> p2(3.4, 7.8);
    cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
	//===================================================

	//DZ-2===============================================
	Pair<int, double> p3(6, 7.8);
	cout << "Pair: " << p3.first() << ' ' << p3.second() << '\n';

	const Pair<double, int> p4(3.4, 5);
	cout << "Pair: " << p4.first() << ' ' << p4.second() << '\n';
	//===================================================

	//DZ-3===============================================
	StringValuePair<int> svp("Amazing", 7);
	cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';
	//===================================================


    return 0;
}