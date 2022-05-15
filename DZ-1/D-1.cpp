#include <iostream>
#include<string>
#include <cstdint>

using namespace std;
//DZ-1=====================================================
class power
{
public:
    void set_a(double _val) { a = _val; }
    void set_b(int _val) { b = _val; }

    double get_a() { return a; }
    double get_b() { return b; }
    double calculate()
    {
           
           for (int i = 0; i < b; i++)
            {
                if (b == 1)
                    return a;
                else if (b % 2 == 0)
                    a = a * a, b = b / 2;
                else
                    a = (a * a) * a, b = (b / 2) ;
            }
       
    }


private:
    double a;
    int b;
};
//=========================================================

//DZ-2=====================================================
class RGBA
{
public:
    RGBA(int red, int grean, int blue, int alpha)
    {
        m_red = (red>0) ? red:0,
            m_grean = (grean > 0) ? grean : 0 ,
            m_blue = (blue > 0) ? blue : 0 ,
            m_alpha = (alpha > 255) ? alpha : 255;
    }
    void print();
private:
    int m_red ;
    int m_grean ;
    int m_blue ;
    int m_alpha ;
};
void RGBA::print()
{
    cout << endl;
    cout << m_red << " " << m_grean << " " << m_blue << " " << m_alpha << endl;
}
//=========================================================

//DZ-3=====================================================
class Stack
{
public:
    void reset()
    {
        next=0;
        for (int i = 0; i < 10; i++)
            arr[i] = 0;
    }

    int push(int t)
    {
        if (next == 10)
            return false;
        
        arr[next++] = t;
            return true;
    }

    int pop()
    {
            return arr[--next];
    } 
    void print()
        {
            cout << "( ";
            for (int i = 0; i < next; ++i)
                cout << arr[i] << ' ';
            cout << ")" << endl;
        }

private:
    int arr[10];
    int next;
};


int main()
{
    //DZ-1==========================================
    power p1;
    p1.set_a(2.5);
    p1.set_b(2);

    cout << p1.get_a() << " " << p1.get_b() << endl;
    p1.calculate();

    cout << p1.get_a() << " " << p1.get_b() << endl;
    //==============================================

    //DZ-2==========================================
    int red=0, grean=0, blue=0, alpha=255; 
    RGBA p2(red, grean, blue, alpha);
    p2.print();

    cout << " red: ";
    cin >> red;
    cout << "grean: ";
    cin >> grean;
    cout << "blue: ";
    cin >> blue;
    cout << "alpha: ";
    cin >> alpha;

    RGBA p3(red, grean, blue, alpha);
    p3.print();
    //=============================================

    //DZ-3=========================================
    Stack stack;
    stack.reset();
    stack.print();

    stack.push(3);
    stack.push(7);
    stack.push(5);
    stack.print();

    stack.pop();
    stack.print();

    stack.pop();
    stack.pop();
    stack.print();
    return 0;
}
