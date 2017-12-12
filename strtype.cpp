#include <iostream>
#include <cstring>
using namespace std;

class strtype
{
    char *str;
    int len;
  public:
    strtype(char *s);
    strtype(int l);
    strtype();
    ~strtype();
    void show() { cout << str << endl;}
    strtype operator+(strtype s2);
    strtype &operator=(strtype s2);
};

strtype::strtype(char *s)
{
    len = strlen(s);
    str = new char[len +1];
    strcpy(str, s);
}

strtype::strtype(int l)
{
    len = l;
    str = new char[len +1];
}

strtype::strtype()
{
    len = 0;
    str = NULL;
}

strtype::~strtype()
{
    delete [] str;
}

strtype strtype::operator+(strtype s2)
{
    strtype temp(len + s2.len);
    strcpy(temp.str, str);
    strcpy(temp.str+len, s2.str);
    cout << temp.str << endl;
    return temp;
}

strtype &strtype::operator=(strtype s2)
{
    if (len != s2.len)
    {
        if (str != NULL) delete [] str;
        str = new char[s2.len +1];
        len = s2.len;
    }
    strcpy(str, s2.str);
    return *this;
}

int main()
{
    char* c1 = (char*)"Hello ";
    char* c2 = (char*)"word!";
    strtype s1(c1), s2(c2), s3;
    cout << "s1: ";
    s1.show();
    cout << "s2: ";
    s2.show();

    s3 = s1 + s2;
    cout << "s3: ";
    s3.show();

    return 0;
}
