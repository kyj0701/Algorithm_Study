#include <iostream>

using namespace std;

long long pascal[1001][1001];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, K;

    cin >> N >> K;

    pascal[0][0] = 1;
    pascal[1][0] = 1;
    pascal[1][1] = 1;

    for(int i = 2; i <= N; i++)
    {
        pascal[i][0] = 1;
        for (int j = 0; j <= K; j++)
        {
            if (i == j) pascal[i][j] = 1;
            else
            {
                pascal[i][j] = (pascal[i-1][j-1] + pascal[i-1][j]) % 10007; 
            }
        }
    }

    cout << pascal[N][K];

    return 0;   
}