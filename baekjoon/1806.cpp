#include <iostream>
#include <algorithm>

using namespace std;

int N, S;
int nums[100001];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> S;

    for (int i = 0; i < N; i++)
    {
        cin >> nums[i];
    }

    int start = 0;
    int end = 0;
    int sum = nums[0];
    int res = INT32_MAX;

    while (start <= end && end < N)
    {
        if (sum >= S) res = min(res, end - start + 1);
        
        if (sum < S)
        {
            end++;
            sum += nums[end];
        }
        else
        {
            sum -= nums[start];
            start++;
        }
    }

    if (res == INT32_MAX) cout << '0';
    else cout << res;

    return 0;
}