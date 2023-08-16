#include <iostream>

using namespace std;

int N, M, S, E;
int nums[2002];
bool DP[2002][2002];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    
    for (int i = 1; i <= N; i++)
    {
        cin >> nums[i];
        DP[i][i] = true;

        if (i != 1 && nums[i-1] == nums[i])
        {
            DP[i-1][i] = true;
        }
    }

    for (int i = 2; i <= N - 1; i++)
    {
        for (int j = 1; i + j <= N; j++)
        {
            if (nums[j] == nums[i+j] && DP[j+1][i+j-1]) DP[j][i+j] = true;
        }
    }

    cin >> M;

    for (int i = 0; i < M; i++)
    {
        cin >> S >> E;

        cout << DP[S][E] << '\n';
    }

    return 0;
}