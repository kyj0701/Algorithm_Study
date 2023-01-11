#include <iostream>
#include <set>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int sLen;
    string S;
    set<string> subS;

    cin >> S;

    sLen = S.size();

    for(int i = 1; i <= sLen; i++)
    {
        for(int j = 0; j < sLen; j++)
        {
            if (i + j > sLen) break;
            subS.insert(S.substr(j, i));
        }
    }

    cout << subS.size();

    return 0;
}