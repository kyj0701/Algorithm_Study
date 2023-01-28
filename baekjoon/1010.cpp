#include <iostream>

using namespace std;

long long pascal[1001][1001];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T, N, K;

    cin >> T;

    pascal[0][0] = 1;
    pascal[1][0] = 1;
    pascal[1][1] = 1;

    for (int i = 0; i < T; i++)
    {
        cin >> K >> N;

        for(int i = 2; i <= N; i++)
        {
            pascal[i][0] = 1;
            for (int j = 0; j <= K; j++)
            {
                if (i == j) pascal[i][j] = 1;
                else
                {
                    pascal[i][j] = (pascal[i-1][j-1] + pascal[i-1][j]); 
                }
            }
        }

        cout << pascal[N][K] << '\n';
    }

    return 0;   
}