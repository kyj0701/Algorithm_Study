#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void bfs(int start);

int N, M, R;
int cnt = 1;

vector<int> vertex[100001];
bool visited[100001] = {0, };
int result[100001];
queue<int> Q;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int u, v;

    cin >> N >> M >> R;

    for (int i = 0; i < M; i++)
    {
        cin >> u >> v;

        vertex[v].push_back(u);
        vertex[u].push_back(v);
    }
    
    for (int i = 1; i <= N; i++) sort(vertex[i].begin(), vertex[i].end());

    bfs(R);

    for(int i = 1; i <= N; i++)
    {
        cout << result[i] << '\n';
    }

    return 0;
}

void bfs(int start)
{
    visited[start] = true;
    result[start] = cnt;
    cnt++;
    Q.push(start);

    while(!Q.empty())
    {
        int x = Q.front();
        Q.pop();

        
        for (int i = 0; i < vertex[x].size(); i++)
        {
            int tmp = vertex[x][i];
            if (!visited[tmp])
            {
                visited[tmp] = true;
                result[tmp] = cnt;
                cnt++;
                Q.push(tmp);
            }
        }
    }
}