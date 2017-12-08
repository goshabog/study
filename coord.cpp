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
};

coord coord:: operator+(coord ob2)
{
    coord temp;
    temp.x = x + ob2.x;
    temp.y = y + ob2.y;
    return temp;
}

int main()
{
    coord o1(10,10), o2(5,3), o3;
    cout << "o1: ";
    o1.print();

    cout << "o2: ";
    o2.print();

    o3 = o1 + o2;
    cout << "o3 = o1+o2: ";
    o3.print();

    return 0;
}   
