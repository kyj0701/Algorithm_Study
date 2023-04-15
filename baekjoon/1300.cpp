#include <iostream>
#include <algorithm>

using namespace std;

int N, k;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> k;

    int low = 1;
    int high = k;
    int mid;
    int res = 0;

    while (true)
    {
        if (low > high) break;
        mid = (low + high) / 2;

        int cnt = 0;
        for (int i = 1; i <= N; i++)
        {
            cnt += min(mid / i, N);
        }

        if (cnt >= k)
        {
            res = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    cout << res;

    return 0;
}