#include <iostream>
#include<string>
#include<cassert>
#include<vector>
#include <algorithm>
#include <set>
#include <iterator>

using namespace std;

class ArrayInt
{
private:
	int m_length;
	int* m_data;
public:
	ArrayInt() : m_length(0), m_data(nullptr) {}

	ArrayInt(int length) : m_length(length) {
		assert(length >= 0);
		if (length > 0)
			m_data = new int[length];
		else
			m_data = nullptr;
	}
	~ArrayInt()
	{
		delete[] m_data;
		m_data = nullptr;
	}
	
	int* begin()
	{
		return &m_data[0];
	}

	int* end()
	{
		return m_data+ m_length;
	}

	void fill(int val)
	{
		for (size_t i = 0; i < m_length; i++)
		{
			m_data[i] = val;
		}
	}
	int size()
	{
		return m_length;
	}
	void erase()
	{
		if (m_data != nullptr)
		{
			delete[] m_data;
			m_data = nullptr;
			m_length = 0;
		}
	}

	int& operator[](int index)
	{
		assert(index >= 0 && index < m_length);
		return m_data[index];
	}
	void resize(int newSize)
	{
		if (newSize == m_length)
		{
			return;
		}
		if (newSize <= 0)
		{
			erase();
			return;
		}
		int* newData = new int[newSize]{0};
		int N_copy = (newSize > m_length) ? m_length : newSize;
		for (size_t i = 0; i < N_copy; i++)
		{
			newData[i]=m_data[i];
		}
		delete[] m_data;
		m_data = newData;
		m_length = newSize;
	}

	void insert(int val, int index)
	{
		int* newData = new int[m_length+1] {0};
		newData[index] = val;
		for (size_t i = 0; i < index; i++)
		{
			newData[i] = m_data[i];
		}
		for (size_t i = index; i < m_length; i++)
		{
			newData[i+1] = m_data[i];
		}
		delete[] m_data;
		m_data = newData;
		m_length++;
	}
	//DZ-1===========================================================
	void pop_back()
	{
		if (m_length > 0)
			m_data[--m_length] = 0;
		else
			erase();
	}

	void pop_front()
	{
		if (m_length > 0)
		{
			m_data = &m_data[1];
			--m_length;
		}
		else
			erase();

	}
	void sort()
	{
		qSort(m_data, 0, m_length - 1);
	}
	
	void qSort(int* s_arr, int first, int last)
	{
		if (first < last)
		{
			int left = first, right = last, middle = s_arr[(left + right) / 2];
			do
			{
				while (s_arr[left] < middle) left++;
				while (s_arr[right] > middle) right--;
				if (left <= right)
				{
					int tmp = s_arr[left];
					s_arr[left] = s_arr[right];
					s_arr[right] = tmp;
					left++;
					right--;
				}
			} while (left <= right);
			qSort(s_arr, first, right);
			qSort(s_arr, left, last);
		}
	}
	void print()
	{
		for (size_t i = 0; i <m_length; i++)
		{
			cout << m_data[i] << " ";
		}
		cout << endl;
	}
};
//===================================================================


//DZ-3==============================================================
class Card
{
public:
	enum rank { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };
	enum suit { CLUBS, DIAMONDS, HEARTS, SPADES };

	Card(rank r = ACE, suit s = SPADES, bool ifu = true) : m_Rank(r), m_Suit(s), m_IsFaceUp(ifu) { }

	int	GetValue() const
	{
		int value = 0;
		if (m_IsFaceUp)
		{
			value = m_Rank;
			if (value > 10)
			{
				value = 10;
			}
		}
		return value;
	}
	void Flip()
	{
		m_IsFaceUp = !m_IsFaceUp;
	}

	friend std::ostream& operator<<(std::ostream& s, const Card& aCard);
private:
	rank m_Rank;
	suit m_Suit;
	bool m_IsFaceUp;
};

class Hand
{
public:
	Hand()
	{
		m_Cards.reserve(7);
	}
	virtual ~Hand()
	{
		Clear();
	}
	void Add(Card* pCard)
	{
		m_Cards.push_back(pCard);
	}
	void Clear()
	{

		vector<Card*>::iterator iter = m_Cards.begin();
		for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
		{
			delete* iter;
			*iter = nullptr;
		}

		m_Cards.clear();
	}
	int GetTotal() const
	{

		if (m_Cards.empty())
		{
			return 0;
		}

		if (m_Cards[0]->GetValue() == 0)
		{
			return 0;
		}

		int total = 0;
		std::vector<Card*>::const_iterator iter;
		for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
		{
			total += (*iter)->GetValue();
		}

		bool containsAce = false;
		for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
		{
			if ((*iter)->GetValue() == Card::ACE)
			{
				containsAce = true;
			}
		}

		if (containsAce && total <= 11)
		{
			total += 10;
		}

		return total;
	}
protected:

	vector<Card*> m_Cards;
};
//==================================================================


int main()
{
	setlocale(LC_ALL, "RUS");
	ArrayInt A1;
	ArrayInt A2(10);
	A2.fill(50);

	cout << A1.size() << endl;
	A1.erase();
	cout << A1.size() << endl;
	cout << A2[2] << endl;
	A2[2] = 100;
	cout << A2[2] << endl;

	A2.resize(15);

	A2.insert(100, 12);
	for (size_t i = 0; i < A2.size(); i++)
	{
		cout << A2[i] << " ";
	}
	cout << endl;
	//DZ-1==========================================================
	A2.pop_back();
	A2.pop_back();
	A2.print();

	A2.pop_front();
	A2.print();

	A2.sort();
	A2.print();
	//===============================================================
	//DZ-2===========================================================
	vector<int> v = { 1, 5, 2, 2, 6, 7, 3, 1, 9, 2, 3, 5, 8, 4 };
	set<int> s(v.begin(), v.end());
	cout << s.size() << " различных значений из " << v.size() << endl;
	//===============================================================
	return 0;
}















