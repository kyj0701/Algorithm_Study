#include <iostream>
#include <numeric>

using namespace std;

long long cnt[1001];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M, num;

    cin >> N >> M;

    long long sum = 0;
    long long res = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> num;
        sum += num;
        cnt[sum % M]++;
    }

    for (int i = 0; i <= 1000; i++)
    {
        res += cnt[i] * (cnt[i] - 1) / 2;
    }

    cout << res + cnt[0];

    return 0;
}