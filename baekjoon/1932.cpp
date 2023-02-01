#include <iostream>
#include <algorithm>

using namespace std;

int n, maxNum;
int dp[501][501] = {0, };

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    maxNum = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cin >> dp[i][j];
        }
    }

    for (int i = n - 1; i > 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            dp[i-1][j] += max(dp[i][j], dp[i][j+1]);
        }
    }
    
    cout << dp[0][0];

    return 0;
}