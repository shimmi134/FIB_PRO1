#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    string s;
    while (cin >> s)
    {
        bool iscorr = true;
        int count1 = 0;
        int count2 = 0;
        if (s[0] == ']' || s[0] == ')')
            count1--;
        else
        {
            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] == '(')
                    count1++;
                else if (s[i] == ')')
                {
                    if (count1 == 0) iscorr = false;
                    else
                        count1--;
                }
                else if (s[i] == '[')
                    count2++;
                else if (s[i] == ']')
                {
                    if (count2 == 0) iscorr = false;
                    else
                        count2--;
                }
            }
        }
        if (count1 == 0  && count2 == 0 && iscorr)
            cout << "yes";
        else 
            cout << "no";
        cout << endl;
    }
}