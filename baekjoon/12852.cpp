#include <iostream>

using namespace std;

int DP[1000001];
int before[1000001];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;

    cin >> N;

    DP[1] = 0;
    before[1] = 0;

    for (int i = 2; i <= N; i++)
    {
        DP[i] = DP[i - 1] + 1;
        before[i] = i - 1;

        if (i % 2 == 0 && DP[i] > DP[i / 2] + 1)
        {
            DP[i] = DP[i / 2] + 1;
            before[i] = i / 2;
        }

        if (i % 3 == 0 && DP[i] > DP[i / 3] + 1)
        {
            DP[i] = DP[i / 3] + 1;
            before[i] = i / 3;
        }
    }

    cout << DP[N] << '\n';

    while (N != 0)
    {
        cout << N << ' ';
        N = before[N];
    }

    return 0;
}