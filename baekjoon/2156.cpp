#include <iostream>
#include <algorithm>

using namespace std;

int wine[10001];
int DP[10001];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> wine[i];
    }

    DP[0] = wine[0] = 0;
    DP[1] = wine[1];
    DP[2] = wine[1] + wine[2];

    for (int i = 3; i <= n; i++)
    {
        DP[i] = max({DP[i-3] + wine[i-1] + wine[i], DP[i-2] + wine[i], DP[i-1]});
    }

    cout << DP[n];

    return 0;
}
