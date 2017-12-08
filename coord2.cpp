/*
 * define operations by using friend functions
 */
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
    friend coord operator+(coord o1, coord ob2);
    friend coord operator+(coord o1, int i);
    friend coord operator+(int i, coord o1);

    friend coord operator++(coord &o); //prefix version
    friend coord operator++(coord &o, int notused); //postfix version

    friend coord operator-(coord o1, coord ob2);
    friend coord operator-(coord o1, int i);

    friend coord operator*(coord o1, int i);
    friend coord operator*(int i, coord o1);

    friend coord operator--(coord &ob);  // prefix version
    friend coord operator--(coord &ob, int unused); // postfix version
};

coord operator+(coord ob1, coord ob2)
{
    coord temp;
    temp.x = ob1.x + ob2.x;
    temp.y = ob1.y + ob2.y;
    return temp;
}

coord operator+(coord ob1, int i)
{
    coord temp;
    temp.x = ob1.x + i;
    temp.y = ob1.y + i;
    return temp;
}

coord operator+(int i, coord ob1)
{
    coord temp;
    temp.x = ob1.x + i;
    temp.y = ob1.y + i;
    return temp;
}

coord operator++(coord &ob)
{
    ob.x++;
    ob.y++;
    return ob;
}

coord operator++(coord &ob, int notused)
{
    ob.x++;
    ob.y++;
    return ob;
}

coord operator-(coord ob1, coord ob2)
{
    coord temp;
    temp.x = ob1.x - ob2.x;
    temp.y = ob1.y - ob2.y;
    return temp;
}

coord operator-(coord ob1, int i)
{
    coord temp;
    temp.x = ob1.x - i;
    temp.y = ob1.y - i;
    return temp;
}

coord operator*(coord ob1, int i)
{
    coord temp;
    temp.x = ob1.x * i;
    temp.y = ob1.y * i;
    return temp;
}

coord operator*(int i, coord ob1)
{
    coord temp;
    temp.x = ob1.x * i;
    temp.y = ob1.y * i;
    return temp;
}

coord operator--(coord &ob)
{
    ob.x--;
    ob.y--;
    return ob;
}

coord operator--(coord &ob, int notused)
{
    ob.x--;
    ob.y--;
    return ob;
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

    o1 = o1 +10;
    cout << "o1+10: ";
    o1.print();

    o1 = 99 + o1;
    cout << "99+o1: ";
    o1.print();

    ++o1;
    o1.print();

    o1++;
    o1.print();

    o3 = o1 - o2;
    cout << "o3 = o1-o2: ";
    o3.print();

    o3 = o1 - 2;
    cout << "o3 = o1-2: ";
    o3.print();

    o3 = o1 * 2;
    cout << "o3 = o1*2: ";
    o3.print();

    o3 = 10 * o1;
    cout << "o3 = 10*o1: ";
    o3.print();

    --o3;
    cout << "--o3: ";
    o3.print();

    o3--;
    cout << "o3--: ";
    o3.print();

    return 0;
}
