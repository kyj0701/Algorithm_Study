#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int storage[101][101][101];
queue<tuple<int, int, int>> q;
int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
int M, N, H;
int res = 0;

void DFS(int j, int i);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> M >> N >> H;

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                cin >> storage[i][j][k];
                if (storage[i][j][k] == 1) q.push({i, j, k});
            }
        }
    }

    if (q.empty())
    {
        cout << "-1";
        return 0;
    }

    while (!q.empty())
    {
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int z = get<2>(q.front());

        q.pop();

        for (int i = 0; i < 6; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];
        
            if (ny < 0 || ny >= N || nx < 0 || nx >= H || nz < 0 || nz >= M) continue;

            if (storage[nx][ny][nz] == 0)
            {
                storage[nx][ny][nz] = storage[x][y][z] + 1;
                q.push({nx, ny, nz});
            }
        }
    }

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                if (storage[i][j][k] == 0) 
                {
                    cout << "-1";
                    return 0;
                }

                if (res < storage[i][j][k]) res = storage[i][j][k];
            }
        }
    }

    cout << res - 1;

    return 0;
}