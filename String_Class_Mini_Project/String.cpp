#include <iostream>
using namespace std;
class String
{
    char *p;
public:
    String()
    {
        p = new char[1];
        p[0] = '\0';
    }
    String(const char *s)
    {
        int n = 0;
        while(s[n] != '\0')
            n++;

        p = new char[n + 1];
        for(int i = 0; i <= n; i++)
            p[i] = s[i];
    }

    String(const String &s)
    {
        int n = 0;
        while(s.p[n] != '\0')
            n++;

        p = new char[n + 1];
        for(int i = 0; i <= n; i++)
            p[i] = s.p[i];
    }

String& operator=(const String &s)
    {
        if(this != &s)
        {
            delete[] p;
            int n = 0;

     while(s.p[n] != '\0')
                n++;
            p = new char[n + 1];
 for(int i = 0; i <= n; i++)
                p[i] = s.p[i];
        }
        return *this;
    }
    String operator+(const String &s)
    {
        String temp;

        int n1 = 0;
        int n2 = 0;

        while(p[n1] != '\0')
            n1++;

        while(s.p[n2] != '\0')
            n2++;

        delete[] temp.p;

        temp.p = new char[n1 + n2 + 1];

        int i;
        for(i = 0; i < n1; i++)
            temp.p[i] = p[i];

        for(int j = 0; j < n2; j++)
            temp.p[i++] = s.p[j];
        temp.p[i] = '\0';
 return temp;
    }
 char& operator[](int i)
    {
        return p[i];
    }

    bool operator==(const String &s)
    {
        int i = 0;

        while(p[i] != '\0' || s.p[i] != '\0')
        {
            if(p[i] != s.p[i])
                return false;
            i++;
        }

        return true;
    }

    bool operator!=(const String &s)
    {
        return !(*this == s);
    }
    bool operator<(const String &s)
    {
        int i = 0;

        while(p[i] != '\0' && s.p[i] != '\0')
        {
            if(p[i] < s.p[i])
                return true;

            if(p[i] > s.p[i])
                return false;

            i++;
        }

        return p[i] < s.p[i];
    }
    bool operator>(const String &s)
    {
        int i = 0;

        while(p[i] != '\0' && s.p[i] != '\0')
        {
            if(p[i] > s.p[i])
                return true;
            if(p[i] < s.p[i])
                return false;
            i++;
        }
 return p[i] > s.p[i];
    }

bool operator<=(const String &s)
    {
        return !(*this > s);
    }

    bool operator>=(const String &s)
    {
        return !(*this < s);
    }

    friend ostream& operator<<(ostream &, const String &);
    friend istream& operator>>(istream &, String &);
    friend void strcpy(String &, const String &);
    friend void strncpy(String &, const String &, int);
    friend int strcmp(const String &, const String &);
    friend int strncmp(const String &, const String &, int);
    friend void strcat(String &, const String &);
    friend void strncat(String &, const String &, int);
friend void strrev(String &);
    friend void strupr(String &);
friend void strlwr(String &);
    friend char* strchr(String &, char);
    friend char* strrchr(String &, char);
    friend char* strstr(String &, const char *);
    friend int strlen(const String &);

    ~String()
    {
        delete[] p;
    }
};
ostream& operator<<(ostream &out, const String &s)
{
    out << s.p;
    return out;
}
istream& operator>>(istream &in, String &s)
{
    char temp[100];

    in >> temp;

    delete[] s.p;
    int n = 0;
    while(temp[n] != '\0')
        n++;
    s.p = new char[n + 1];

    for(int i = 0; i <= n; i++)
        s.p[i] = temp[i];
return in;
}

void strcpy(String &s2, const String &s1)
{
    delete[] s2.p;
    int n = 0;
    while(s1.p[n] != '\0')
        n++;

    s2.p = new char[n + 1];
    for(int i = 0; i <= n; i++)
        s2.p[i] = s1.p[i];
}

void strncpy(String &s2, const String &s1, int n)
{
    delete[] s2.p;
    s2.p = new char[n + 1];
    for(int i = 0; i < n && s1.p[i] != '\0'; i++)
        s2.p[i] = s1.p[i];
    s2.p[n] = '\0';
}

int strcmp(const String &s2, const String &s1)
{
    int i = 0;
while(s2.p[i] != '\0' || s1.p[i] != '\0')
    {
        if(s2.p[i] > s1.p[i])
            return 1;
        if(s2.p[i] < s1.p[i])
            return -1;
 i++;
    }

    return 0;
}
int strncmp(const String &s2, const String &s1, int n)
{
    for(int i = 0; i < n; i++)
    {
        if(s2.p[i] > s1.p[i])
        return 1;

    if(s2.p[i] < s1.p[i])
            return -1;

 if(s2.p[i] == '\0')
            return 0;
    }
    return 0;
}

void strcat(String &s2, const String &s1)
{
    int n1 = 0;
    int n2 = 0;

    while(s2.p[n1] != '\0')
        n1++;

    while(s1.p[n2] != '\0')
        n2++;

    char *temp = new char[n1 + n2 + 1];

    int i;

    for(i = 0; i < n1; i++)
        temp[i] = s2.p[i];

    for(int j = 0; j < n2; j++)
        temp[i++] = s1.p[j];

    temp[i] = '\0';

    delete[] s2.p;
    s2.p = temp;
}

void strncat(String &s2, const String &s1, int n)
{
    int n1 = 0;
    int n2 = 0;
    while(s2.p[n1] != '\0')
        n1++;
    while(s1.p[n2] != '\0' && n2 < n)
      n2++;
char *temp = new char[n1 + n2 + 1];

    int i;
    for(i = 0; i < n1; i++)
        temp[i] = s2.p[i];

    for(int j = 0; j < n2; j++)
        temp[i++] = s1.p[j];

    temp[i] = '\0';
    delete[] s2.p;
    s2.p = temp;
}

void strrev(String &s1)
{
    int n = 0;
    while(s1.p[n] != '\0')
        n++;
    int start = 0;
    int end = n - 1;
 while(start < end)
    {
        char temp = s1.p[start];
        s1.p[start] = s1.p[end];
        s1.p[end] = temp;
start++;
        end--;
    }
}

void strupr(String &s1)
{
    for(int i = 0; s1.p[i] != '\0'; i++)
    {
        if(s1.p[i] >= 'a' && s1.p[i] <= 'z')
            s1.p[i] = s1.p[i] - 32;
    }
}

void strlwr(String &s1)
{
    for(int i = 0; s1.p[i] != '\0'; i++)
    {
        if(s1.p[i] >= 'A' && s1.p[i] <= 'Z')
            s1.p[i] = s1.p[i] + 32;
    }
}

char* strchr(String &s1, char ch)
{
    for(int i = 0; s1.p[i] != '\0'; i++)
    {
        if(s1.p[i] == ch)
            return &s1.p[i];
    }

    return 0;
}

char* strrchr(String &s1, char ch)
{
    char *last = 0;

    for(int i = 0; s1.p[i] != '\0'; i++)
    {
        if(s1.p[i] == ch)
            last = &s1.p[i];
    }

    return last;
}

char* strstr(String &s1, const char *sub)
{
    for(int i = 0; s1.p[i] != '\0'; i++)
    {
        int j = 0;

        while(sub[j] != '\0' && s1.p[i + j] == sub[j])
            j++;

        if(sub[j] == '\0')
            return &s1.p[i];
    }

    return 0;
}

int strlen(const String &s1)
{
    int i = 0;

    while(s1.p[i] != '\0')
        i++;

    return i;
}

int main()
{
    String s1;
    String s2("Hello");
    String s3(s2);
    String s4;
    s4 = s2;

    cout << "s1 = " << s1 << endl;
cout << "s2 = " << s2 << endl;
 cout << "s3 = " << s3 << endl;
    cout << "s4 = " << s4 << endl;

    String s5(" World");
    String s6;
 s6 = s2 + s5;

    cout << "s6 = " << s6 << endl;
    cout << "s2[1] = " << s2[1] << endl;
s2[0] = 'h';

    cout << "s2 = " << s2 << endl;
    String a("Apple");
    String b("Banana");
    cout << "a > b = " << (a > b) << endl;
    cout << "a < b = " << (a < b) << endl;
 cout << "a >= b = " << (a >= b) << endl;
 cout << "a <= b = " << (a <= b) << endl;
    cout << "a == b = " << (a == b) << endl;
    cout << "a != b = " << (a != b) << endl;

    String input;
  cout << "Enter a string: ";
    cin >> input;
   cout << "input = " << input << endl;

    String x("Hello");
    String y("World");
    String z;
    strcpy(z, x);
    cout << "strcpy = " << z << endl;

    strncpy(z, y, 3);
    cout << "strncpy = " << z << endl;

    cout << "strcmp = " << strcmp(x, y) << endl;
    cout << "strncmp = " << strncmp(x, y, 2) << endl;

    z = x;
    strcat(z, y);
cout << "strcat = " << z << endl;
    z = x;
strncat(z, y, 3);
    cout << "strncat = " << z << endl;

    z = x;
strrev(z);
    cout << "strrev = " << z << endl;
    z = x;
    strupr(z);
    cout << "strupr = " << z << endl;
 z = "HELLO";
    strlwr(z);
    cout << "strlwr = " << z << endl;

    z = "Hello";

    char *p1 = strchr(z, 'l');
    if(p1 != 0)
  cout << "strchr = " << p1 << endl;

char *p2 = strrchr(z, 'l');

    if(p2 != 0)
        cout << "strrchr = " << p2 << endl;
  z = "Hello World";

char *p3 = strstr(z, "World");

 if(p3 != 0)
        cout << "strstr = " << p3 << endl; 
    cout << "strlen = " << strlen(z) << endl;
return 0;
}
