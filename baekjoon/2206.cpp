#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <tuple>

using namespace std;

int N, M;
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,-1,1};
int visited[1001][1001][2];

int BFS(vector<string> &map)
{
    queue<tuple<int, int, int>> q;
    q.push(make_tuple(0, 0, 1));

    visited[0][0][1] = 1;

    int tmpX, tmpY, block;

    while(!q.empty())
    {
        tmpX = get<0>(q.front());
        tmpY = get<1>(q.front());
        block = get<2>(q.front());
        q.pop();

        if (tmpX == N - 1 && tmpY == M - 1) return visited[tmpX][tmpY][block];

        for(int i = 0; i < 4; i++)
        {
            int nextX = tmpX + dx[i];
            int nextY = tmpY + dy[i];

            if (nextX < N && nextX >= 0 &&  nextY < M && nextY >= 0)
            {
                if (map[nextX][nextY] == '1' && block)
                {
                    q.push(make_tuple(nextX, nextY, 0));
                    visited[nextX][nextY][block - 1] = visited[tmpX][tmpY][block] + 1; 
                }
                else if (map[nextX][nextY] == '0' && visited[nextX][nextY][block] == 0)
                {
                    q.push(make_tuple(nextX, nextY, block));
                    visited[nextX][nextY][block] = visited[tmpX][tmpY][block] + 1; 
                }
            }
        }
    }

    return -1;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    vector<string> map(N);

    for (int i = 0; i < N; i++)
    {
        cin >> map[i];
    }

    cout << BFS(map);

    return 0;
}