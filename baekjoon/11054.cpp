#include <iostream>
#include <algorithm>

using namespace std;

int nums[1001];
int DP1[1001];
int DP2[1001];
int N;

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

    for (int i = 0; i < N; i++)
    {
        DP1[i] = 1;

        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j])
            {
                DP1[i] = max(DP1[i], DP1[j] + 1);
            }
        }
    }

    for (int i = N - 1; i >= 0; i--)
    {
        DP2[i] = 1;
        
        for (int j = i + 1; j < N; j++)
        {
            if (nums[j] < nums[i])
            {
                DP2[i] = max(DP2[i], DP2[j] + 1);
            }
        }
    }

    int result = 0;

    for (int i = 0; i < N; i++)
    {
        result = max(result, DP1[i] + DP2[i]);
    }

    cout << result - 1;
    
    return 0;
}