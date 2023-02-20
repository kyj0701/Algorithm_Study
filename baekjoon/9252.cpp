#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int DP[1001][1001];
string str1;
string str2;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> str1;
    cin >> str2;

    for (int i = 1; i <= str1.size(); i++)
    {
        for (int j = 1; j <= str2.size(); j++)
        {
            if (str1[i-1] == str2[j-1]) DP[i][j] = DP[i-1][j-1] + 1;
            else DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
        }
    }

    cout << DP[str1.size()][str2.size()];
    
    return 0;
}