#include <iostream>
#include <algorithm>

using namespace std;

int nums[100001];
int sums[100001];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    sums[0] = nums[0];
    int result = sums[0];

    for (int i = 1; i < n; i++)
    {
        sums[i] = max(nums[i], nums[i] + sums[i-1]);
        result = max(result, sums[i]);
    }

    cout << result;

    return 0;
}