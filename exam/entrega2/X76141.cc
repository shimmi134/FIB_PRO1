#include <iostream>
using namespace std;

//IN: Un numero n de numeros magicos que tenemos que encontrar.
//OUT: Los n primeros numeros magicos que hay.

int main()
{
    int num, x;
    x = 1;
    cin >> num;
    while (num != 0)
    {
        int result = 0;
        int n = x;
        int len = 0;
        while (n != 0)
        {
            len++;
            n = n/10;
        }
        n = x;
        while (n != 0)
        {
            int count = len;
            int digit = n % 10;
            int pow = 1;
            while (count != 0)
            {
                pow = pow * digit;
                count--;
            }
            result = result + pow;
            n = n/10;
        }
        if (result == x)
        {
            cout << result << " ";
            num--;
        }
        x++;
    }
}
