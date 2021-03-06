#include <iostream>
using namespace std;

class three_d
{
    int x,y,z;
  public:
    three_d(int i, int j, int k)
    {
        x = i; y = j; z = k;
    }

    three_d()
    {
        x = y = z = 0;
    }

    void get(int &i, int &j, int &k)
    {
        i = x; j = y; k = z;
    }

    three_d operator+(three_d ob);
    three_d operator-(three_d ob);
    three_d operator++();
    three_d operator--();
    three_d operator+(int n);
    friend three_d operator+(int n, three_d &ob);
    int operator==(three_d ob);
    int operator!=(three_d ob);
    int operator||(three_d ob);
};

three_d three_d::operator+(three_d ob)
{
    three_d temp;
    temp.x = x + ob.x;
    temp.y = y + ob.y;
    temp.z = z + ob.z;
    return temp;
}

three_d three_d::operator-(three_d ob)
{
    three_d temp;
    temp.x = x - ob.x;
    temp.y = y - ob.y;
    temp.z = z - ob.z;
    return temp;
}

three_d three_d::operator++()
{
    x++;
    y++;
    z++;
    return *this;
}

three_d three_d::operator--()
{
    x--;
    y--;
    z--;
    return *this;
}

three_d three_d::operator+(int n)
{
    three_d temp;
    temp.x = x + n;
    temp.y = y + n;
    temp.z = z + n;
    return temp;
}

three_d operator+(int n, three_d &ob)
{
    three_d temp;
    temp.x = n + ob.x;
    temp.y = n + ob.y;
    temp.z = n + ob.z;
    return temp;
}

int three_d::operator==(three_d ob)
{
    return (x == ob.x && y == ob.y && z == ob.z);
}

int three_d::operator!=(three_d ob)
{
    return (x != ob.x || y != ob.y || z != ob.z);
}

int three_d::operator||(three_d ob)
{
    return (x || ob.x && y || ob.y && z || ob.z);
}

int main()
{
    int i,j,k;
    three_d o1(1,2,3), o2(4,5,6), o3;
    o1.get(i,j,k);
    cout << "o1: " << i << " " << j << " " << k << endl;
    o2.get(i,j,k);
    cout << "o2: " << i << " " << j << " " << k << endl;
    o3.get(i,j,k);
    cout << "o3: " << i << " " << j << " " << k << endl;

    o3 = o1 + o2;
    o3.get(i,j,k);
    cout << "o3 = o1 + o2: " << i << " " << j << " " << k << endl;

    o3 = o2 - o1;
    o3.get(i,j,k);
    cout << "o3 = o2 - o1: " << i << " " << j << " " << k << endl;

    o3 = ++o1;
    o3.get(i,j,k);
    cout << "o3 = ++o1: " << i << " " << j << " " << k << endl;

    o3 = --o2;
    o3.get(i,j,k);
    cout << "o3 = --o2: " << i << " " << j << " " << k << endl;

    o3 = o1 + 10;
    o3.get(i,j,k);
    cout << "o3 = o1 + 10: " << i << " " << j << " " << k << endl;

    o3 = 5 + o1;
    o3.get(i,j,k);
    cout << "o3 = 5 + o1: " << i << " " << j << " " << k << endl;

    return 0;
}
