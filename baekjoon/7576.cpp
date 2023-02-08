#include <iostream>
#include <queue>

using namespace std;

int storage[1001][1001];
queue<pair<int, int>> q;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int M, N;
int res = 0;

void DFS(int j, int i);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> M >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> storage[i][j];
            if (storage[i][j] == 1) q.push({i, j});
        }
    }

    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
        
            if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;

            if (storage[ny][nx] == 0)
            {
                storage[ny][nx] = storage[y][x] + 1;
                q.push({ny, nx});
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (storage[i][j] == 0) 
            {
                cout << "-1";
                return 0;
            }

            if (res < storage[i][j]) res = storage[i][j];
        }
    }

    cout << res - 1;

    return 0;
}