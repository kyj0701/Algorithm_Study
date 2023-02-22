#include <iostream>
#include <algorithm>

using namespace std;

int T, K;
int sum[501];
int file[501];
int DP[501][501];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;

    while (T--)
    {

        cin >> K;

        for (int i = 1; i <= K; i++)
        {
            cin >> file[i];
            sum[i] = sum[i-1] + file[i];
        }

        for (int i = 1; i <= K; i++)
        {
            for (int j = 1; j <= K - i; j++)
            {
                DP[j][i + j] = INT32_MAX;

                for (int k = j; k < i + j; k++)
                {
                    DP[j][i + j] = min(DP[j][i + j], DP[j][k] + DP[k + 1][i + j] - sum[j - 1] + sum[i + j]);
                }
            }
        }

        cout << DP[1][K] << '\n';
    }

    return 0;
}