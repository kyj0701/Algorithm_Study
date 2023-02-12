#include <iostream>
#include <queue>

using namespace std;

int N, M;
int board[101];
int before[101];


void BFS(int start);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    int x, y;

    for (int i = 1; i <= 100; i++)
    {
        before[i] = INT32_MAX;
    }

    for (int i = 0; i < N + M; i++)
    {
        cin >> x >> y;
        board[x] = y;
    }

    BFS(1);

    cout << before[100];

    return 0;
}

void BFS(int start)
{
    queue<pair<int, int>> q;
    q.emplace(start, 0);
    before[start] = 0;

    while(!q.empty())
    {
        int now = q.front().first;
        int cnt = q.front().second;
        q.pop();

        for (int i = 1; i <= 6; i++)
        {
            int tmp = cnt;
            int next = now + i;
            if (next > 100) continue;

            tmp++;
            if (board[next] != 0)
            {
                next = board[next];
            }

            if (before[next] > tmp)
            {
                before[next] = tmp;
                q.emplace(next, tmp);
            }
        }
    }
}