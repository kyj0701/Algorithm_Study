#include <iostream>

using namespace std;

int coins[101];
int DP[10001];

int main(void)
{
    int n, k;

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    DP[0] = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = coins[i]; j <= k; j++)
        {
            DP[j] += DP[j - coins[i]];
        }
    }

    cout << DP[k];

    return 0;
}