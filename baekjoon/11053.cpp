#include <iostream>
#include <algorithm>

using namespace std;

int nums[1001];
int DP[1001];
int N, result;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> nums[i];
    }

    result = 0;

    for (int i = 0; i < N; i++)
    {
        DP[i] = 1;

        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j])
            {
                DP[i] = max(DP[i], DP[j] + 1);
            }
        }

        result = max(result, DP[i]);
    }

    cout << result;
    
    return 0;
}