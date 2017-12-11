#include <iostream>
#include <cstdlib>
using namespace std;

class dynarray
{
    int *p;
    int size;
  public:
    dynarray(int s);
    ~dynarray();
    int &put(int i);
    int get(int i);
    dynarray &operator=(dynarray& ob);
};

dynarray:: dynarray(int s)
{
    if (s <= 0)
    {
       cout << "Wrong array size=" << s << " Must be > 0\n";
       exit(1);
    }
    p = new int[s];
    if (p == NULL)
    {
       cout << "Memory allocation error\n";
       exit(2);
    }
    size = s;
}

dynarray::~dynarray()
{
    delete [] p;
}

int &dynarray::put(int i)
{
    if (i <0 || i >=size)
    {
       cout << "Wrong array index=" << i << endl;
       exit(1);
    }
    return p[i];
}

int dynarray::get(int i)
{
    if (i <0 || i >=size)
    {
       cout << "Wrong array index=" << i << endl;
       exit(1);
    }
    return p[i];
}

dynarray &dynarray::operator=(dynarray& ob)
{
    if ( ob.size > size)
    {
       delete [] p;
       p =  new int [ob.size];
       if (!p)
       {
           cout << "Memory allocation error\n";
           exit(2);
       }
       size = ob.size;
    }
    for (int i=0; i < size; ++i)
    {
        p[i] = ob.p[i];
    }
    return *this;
}

int main()
{
    dynarray o1(3), o2(5);

    for (int i=0; i < 3; i++)
    {
        o1.put(i) = 2*i;
    }
    cout << "o1: ";
    for (int i=0; i < 3; i++)
    {
        cout << o1.get(i) << " ";
    }
    cout << endl;
    for (int i=0; i < 5; i++)
    {
        o2.put(i) = 3*i;
    }
    cout << "o2: ";
    for (int i=0; i < 5; i++)
    {
        cout << o2.get(i) << " ";
    }
    cout << endl;

    o1 = o2;

    cout << "o1: ";
    for (int i=0; i < 5; i++)
    {
        cout << o1.get(i) << " ";
    }
    cout << endl;
    return 0;    
}
