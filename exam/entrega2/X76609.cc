#include <iostream>
using namespace std;

//IN: Direcciones al principio (x1, y1) y direcciones al final (x2, y2)
//OUT: En que sentido se mueve para ir de (x1, y1) a (x2, y2)

int main()
{
    int total;
    cin >> total;
    while (total != 0)
    {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (y2 > y1)
            cout << 'N';
        else if (y2 < y1)
            cout << 'S';
        if (x2 > x1)
            cout << 'E';
        else if (x2 < x1)
            cout << 'O';
        cout << endl;
        total--;
    }
}
