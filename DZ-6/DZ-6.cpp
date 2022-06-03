#include <iostream>
#include<string>

using namespace std;

//DZ-1==========================================
template <typename T>
T getUserInput(bool allowZero, bool allowNegative, bool checkAllinput)
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
void Task1()
{
	cout << "Ввод числа int с защитой от \"Дурака\":" << endl;
	int a = getUserInput<int>(true, true, true);
	cout << "Вы ввели: " << a << endl;
}
//==============================================

//DZ-2==========================================
ostream& endll(std::ostream& out)
{
	char enter = out.widen('\n');
	out.put(enter);
	out.put(enter);
	out.flush();
	return out;
}
void Task2()
{
	cout << "Работа с собственным манипулятором endll:" << endl;
	cout << "Привет" << endll;
	cout << "После endll" << endl;
}
//================================================

int main()
{
	setlocale(LC_ALL, "RUS");
	//DZ-1==========================================
	Task1();
	//==============================================

	//DZ-2==========================================
	Task2();
	//==============================================
	return 0;
}

