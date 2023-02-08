#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int storage[101][101][101];
queue<tuple<int, int, int>> q;
int dx[6] = {0, 0, 0, 0, -1, 1};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dz[6] = {-1, 1, 0, 0 };
int M, N, H;
int res = 0;

void DFS(int j, int i);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> M >> N >> H;

    for (int k = 0; k < H; k++)
        {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                cin >> storage[i][j][k];
                if (storage[i][j][k] == 1) q.push({i, j, k});
            }
        }
    }

    while (!q.empty())
    {
        int z = get<2>(q.front());
        int y = get<1>(q.front());
        int x = get<0>(q.front());
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
        
            if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;

            if (storage[ny][nx][z] == 0)
            {
                storage[ny][nx][z] = storage[y][x][z] + 1;
                q.push({ny, nx, z});
            }
        }

        for (int i = 0; i < 2; i++)
        {
            int nz = z + dz[i];

            if (nz < 0 || nz >= H) continue;

            if (storage[y][x][nz] == 0)
            {
                storage[y][x][nz] = storage[y][x][nz] + 1;
                q.push({y, x, nz});
            }
        }
    }

    for (int k = 0; k < H; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
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