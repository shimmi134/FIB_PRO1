#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    string s;
    while (cin >> s)
    {
        int count1 = 0, count2 = 0;
        
        // Handle the case where the first character is unmatched
        if (s[0] == ']' || s[0] == ')')
        {
            cout << "no" << endl;
            continue;
        }

        bool isBalanced = true;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(') count1++;
            else if (s[i] == ')')
            {
                if (count1 == 0) 
                {
                    isBalanced = false;
                    break;
                }
                count1--;
            }
            else if (s[i] == '[') count2++;
            else if (s[i] == ']')
            {
                if (count2 == 0) 
                {
                    isBalanced = false;
                    break;
                }
                count2--;
            }
        }

        // Output result based on the counts and whether it's balanced
        if (count1 == 0 && count2 == 0 && isBalanced)
            cout << "yes";
        else
            cout << "no";
        cout << endl;
    }
}

