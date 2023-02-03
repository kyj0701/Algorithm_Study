#include <iostream>

using namespace std;

int num[1025][1025];
int sum[1025][1025];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    int fromX, fromY, toX, toY;

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> num[i][j];

            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + num[i][j];
        }
    }

    for (int i = 0; i < M; i++)
    {
        cin >> fromX >> fromY >> toX >> toY;

        cout << sum[toX][toY] - sum[fromX - 1][toY] - sum[toX][fromY - 1] + sum[fromX - 1][fromY - 1] << '\n';
    }

    return 0;
}