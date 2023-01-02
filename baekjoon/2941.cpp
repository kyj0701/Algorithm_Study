#include <iostream>

using namespace std;

int main(void)
{
    string word;
    int count = 0;

    cin >> word;

    int len = word.length();

    for (int i = 0; i < len; i++)
    {
        if (i != len - 2)
        {
            if (word[i] == 'd' && word[i+1] == 'z' && word[i+2] == '=')
            {
                count++;
                i += 2;
                continue;
            }
        }
        if (i != len -1)
        {
            if (word[i] == 'l' && word[i+1] == 'j')
            {
                count++;
                i += 1;
                continue;
            }
            else if (word[i] == 'n' && word[i+1] == 'j')
            {
                count++;
                i += 1;
                continue;
            }
            else if (word[i] == 'c')
            {
                if (word[i+1] == '=')
                {
                    count++;
                    i += 1;
                    continue;
                }
                else if (word[i+1] == '-')
                {
                    count++;
                    i += 1;
                    continue;
                }
            }
            else if (word[i] == 'd')
            {
                if (word[i+1] == '-')
                {
                    count++;
                    i += 1;
                    continue;
                }
            }
            else if (word[i] == 's' || word[i] == 'z')
            {
                if (word[i+1] == '=')
                {
                    count++;
                    i += 1;
                    continue;
                }
            }
        }
        
        count++;
    }

    cout << count;

    return 0;
}