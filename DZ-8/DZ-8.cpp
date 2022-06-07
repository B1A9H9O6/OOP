#include<iostream>
#include<string>
#include<exception>
#include"D-3.h"


using namespace std;

char getUserInputKey()
{
	char c;
	cin.get(c);
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return c;
}

template <typename T>
T getUserInput(bool allowZero = false, bool allowNegative = false, bool checkAllinput = true)
{
	while (true)
	{
		T input;
		cin >> input;
		if (cin.fail() || (input < 0) && !allowNegative || (input == 0) && !allowZero)
		{
			cout << "Ошибка ввода, повторите ввод: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else
		{
			if ((cin.peek() != cin.widen('\n')) && checkAllinput)
			{
				cout << "Ошибка ввода, повторите ввод: ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			else
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				return input;
			}
		}
	}
}
//DZ-1==============================================================================
/*
class DivisionByZero : public std::exception
{
public:
	DivisionByZero(const string& err = "Division by zero detected!") : error(err)
	{};

	const char* what() const noexcept { return error.c_str(); }

private:
	string error;
};


template <typename T>
double_t div(T dividend, T divider)
{
	if (divider == 0) throw DivisionByZero();
	return static_cast<double_t>(dividend) / divider;
}

void Task1()
{
	cout << "Работа с Функцией div:" << endl << endl;
	int64_t a, b;
	double_t aa, bb, result;
	try
	{
		cout << "введите целое число a = ";
		a = getUserInput<int>(true, true);
		cout << "введите целое число b = ";
		b = getUserInput<int>(true, true);
		result = div<int>(a, b);
		cout << a << " / " << b << " = " << result << endl;

		cout << "введите дробное число a = ";
		aa = getUserInput<double>(true, true);
		cout << "введите дробное число b = ";
		bb = getUserInput<double>(true, true);
		result = div<double>(aa, bb);
		cout << aa << " / " << bb << " = " << result << endl;
	}
	catch (const std::exception& exception)
	{
		cerr << "Возникла ошибка: " << exception.what() << endl;
	}
	catch (...)
	{
		cerr << "Возникла не известная ошибка!" << endl;
	}
}*/
//DZ-2========================================================

class Ex
{
public:
	Ex(double_t arg) : x(arg)
	{};
	double_t what() const noexcept { return x; };

private:
	double_t x;
};

class Bar
{
public:
	Bar() : y(0)
	{};

	void set(double_t a)
	{
		if (y + a > 100) throw Ex(a * y);
		else y = a;
	}

private:
	double_t y;
};

void Task2()
{
	cout << "Работа с классом Bar:" << endl << endl;
	Bar bar;
	double_t n;
	try
	{
		do
		{
			cout << "Введите n = ";
			n = getUserInput<double>(true, true);
			bar.set(n);
			cout << endl;
		} while (n != 0);
	}
	catch (const Ex& ex)
	{
		cerr << "Возникла ошибка: Ex с параметром (" << ex.what() << ")" << endl;
	}
	catch (...)
	{
		cerr << "Возникла не известная ошибка!" << endl;
	}
}
//DZ-3===================================================


void Task3()
{
	system("cls");
	Robot rb;
	char c;
	do
	{
		cout << "Работа с классом Робот:" << endl << endl;
		rb.print();
		cout << endl << "Для перемещения используйте WASD, для выхода Q" << endl;
		c = getUserInputKey();
		system("cls");
		try
		{
			switch (c)
			{
			case 'd':
			case 'D':
				rb.move(Direction::RIGHT);
				break;
			case 'a':
			case 'A':
				rb.move(Direction::LEFT);
				break;
			case 'w':
			case 'W':
				rb.move(Direction::UP);
				break;
			case 's':
			case 'S':
				rb.move(Direction::DOWN);
				break;
			case 'q':
			case 'Q':
				break;
			default:
				rb.move(Direction::other);
			}
		}
		catch (const OffTheField& ex)
		{
			cerr << "Попытка выхода за пределы поля! " << ex.what() << endl;
		}
		catch (const IllegalCommand& ex)
		{
			cerr << "Указано неизвестное направление!" << endl;
		}
		catch (...)
		{
			cerr << "Неизвестная ошибка!" << endl;
		}
	} while (c != 'q' && c != 'Q');


}


int main()
{
	setlocale(LC_ALL, "RUS");

//Task1();

 Task2();

 Task3();
 return 0;
}
