#include <iostream>

using namespace std;

struct Data{
    int dia, mes, any;
};


Data read_data(void)
{
    char c;
    Data d;
    cin >> d.dia >> c >> d.mes >> c >> d.any;
    return d;
}

bool menor(const Data& d1, const Data& d2)
{
    if (d1.any < d2.any) return true;
    else if (d1.any == d2.any and d1.mes < d2.mes) return true;
    else if (d1. any == d2.any and d1.mes == d2.mes and d1.dia < d2.dia) return true;
    return false;
}

int main (void)
{
    int n;
    bool correct = false;
    cin >> n;
    Data d1 = read_data();
    Data d2 = read_data();
    n = n-2; // Ja hem llegit dues
    while (n > 0 and not correct)
    {
        Data d3 = read_data();
        n--;
        if ((menor(d1,d2) and menor (d2,d3)) or (menor(d3,d2) and menor(d2,d1)))
        {
            correct = true;
            cout << d2.dia << '/' << d2.mes << '/' << d2.any << endl;
        }
        d1 = d2;
        d2 = d3;
    }
    if (not correct)
    {
        cout << "cap data trobada" << endl;
    }
}

