#include <iostream>
#include <string.h>

using namespace std;

int T, N, M, K;

int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,-1,1};
int cabagge[51][51] = {0, };
bool visited[51][51] = {0, };

void dfs(int y, int x);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;

    int cy, cx;
    int sum;

    for(int t = 0; t < T; t++)
    {
        cin >> M >> N >> K;

        memset(cabagge, 0, sizeof(cabagge));
        memset(visited, 0, sizeof(visited));

        sum = 0;

        for (int i = 0; i < K; i++)
        {
            cin >> cx >> cy;
            cabagge[cy][cx] = 1;
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0 ; j < M; j++)
            {
                if (cabagge[i][j] && !visited[i][j])
                {
                    sum++;
                    visited[i][j] = true;
                    dfs(i, j);
                }
            }
        }

        cout << sum << '\n';
    }

    return 0;
}

void dfs(int y, int x)
{
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;

        if (cabagge[ny][nx] && !visited[ny][nx])
        {
            visited[ny][nx] = true;
            dfs(ny, nx);
        }
    }
}