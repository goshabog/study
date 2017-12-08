#include <iostream>
using namespace std;

class coord
{
    int x,y;
  public:
    coord() {x=y=0;}
    coord(int i, int j) { x = i; y = j;}
    void get_xy(int &a, int &b) { a = x; b = y; }
    void print() { cout << "x = " << x << " y = " << y << endl; }
    coord operator+(coord ob2);
    coord operator+(int i);
    coord operator+();

    coord operator-(coord ob2);
    coord operator-();

    coord operator=(coord ob2);

    coord operator*(coord ob2);
    coord operator*(int i);

    int operator==(coord ob2);
    int operator&&(coord ob2);
    int operator<(coord ob2);
    int operator>(coord ob2);

    coord operator++();
    coord operator++(int notused);

    coord operator--();
    coord operator--(int notused);
};

coord coord:: operator+(coord ob2)
{
    coord temp;
    temp.x = x + ob2.x;
    temp.y = y + ob2.y;
    return temp;
}

coord coord:: operator+()
{
    if (x <0) x = -x;
    if (y <0) y = -y;
    return *this;
}

coord coord:: operator-(coord ob2)
{
    coord temp;
    temp.x = x - ob2.x;
    temp.y = y - ob2.y;
    return temp;
}

coord coord:: operator-()
{
    x = -x;
    y = -y;
    return *this;
}

coord coord:: operator=(coord ob2)
{
    x = ob2.x;
    y = ob2.y;
    return *this;
}

coord coord:: operator+(int i)
{
    coord temp;
    temp.x = x + i;
    temp.y = y + i;
    return temp;
}

coord coord:: operator*(coord ob2)
{
    coord temp;
    temp.x = x * ob2.x;
    temp.y = y * ob2.y;
    return temp;
}

coord coord:: operator*(int i)
{
    coord temp;
    temp.x = x * i;
    temp.y = y * i;
    return temp;
}

int coord::operator==(coord ob2)
{
    return (x == ob2.x) && (y == ob2.y);
}

int coord::operator&&(coord ob2)
{
    return (x && ob2.x) && (y && ob2.y);
}

int coord::operator<(coord ob2)
{
    return (x < ob2.x) && (y < ob2.y);
}

int coord::operator>(coord ob2)
{
    return (x > ob2.x) && (y > ob2.y);
}

coord coord::operator++()
{
    x++;
    y++;
    return *this;
}

coord coord::operator++(int notused)
{
    x++;
    y++;
    return *this;
}

coord coord::operator--()
{
    x--;
    y--;
    return *this;
}

coord coord::operator--(int notused)
{
    x--;
    y--;
    return *this;
}

int main()
{
    coord o1(10,10), o2(5,3), o3;
    coord o4(10,10), o5(0,0);
    cout << "o1: ";
    o1.print();

    cout << "o2: ";
    o2.print();

    o3 = o1 + o2;
    cout << "o3 = o1+o2: ";
    o3.print();

    o3 = o1 - o2;
    cout << "o3 = o1-o2: ";
    o3.print();

    o3 = o1;
    cout << "o3 = o1: ";
    o3.print();

    o3 = o1 + 100;
    cout << "o3 = o1+100: ";
    o3.print();

    o3 = o1 * o2;
    cout << "o3 = o1*o2: ";
    o3.print();

    o3 = o1 * 100;
    cout << "o3 = o1*100: ";
    o3.print();

    if(o1 == o2)
       cout << "o1 == o2\n";
    else
       cout << "o1 != o2\n";

    if(o1 == o4)
       cout << "o1 == o4\n";
    else
       cout << "o4 != o4\n";

    if(o1 && o2)
       cout << "o1 && o2 is true\n";
    else
       cout << "o1 && o2 is false\n";

    if(o1 && o5)
       cout << "o1 && o5 is true\n";
    else
       cout << "o1 && o5 is false\n";

    if(o1 < o2)
       cout << "o1 < o2 is true\n";
    else
       cout << "o1 < o2 is false\n";

    if(o1 > o5)
       cout << "o1 > o5 is true\n";
    else
       cout << "o1 > o5 is false\n";

    (++o1).print();
    (o1++).print();

    (--o2).print();
    (o2--).print();

    (-o1).print();
    (+o1).print();
    return 0;
}   
