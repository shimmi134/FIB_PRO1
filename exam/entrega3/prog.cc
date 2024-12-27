#include <iostream>
using namespace std;

//IN: Una serie de numeros n.
//OUT: Imprimeix "SI" en cas que trobi 5 o mes nombres de 4 xifres que 
//comencin i acabin en el mateix nombre. Imprimeix "NO" en cas contrari.

int main()
{
    int n, count = 0;
    while (count != 5 and cin >> n)
    {
        if (n > 999 and n < 10000)
        {
            int last = n % 10;
            while (n > 9)
                n = n/10;
            if (n == last)
                count++;
        }
    }
    if (count >= 5)
        cout << "SI";
    else
        cout << "NO";

}
