#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(int start);

int N, M, R;
int cnt = 1;

vector<int> vertex[100001];
bool visited[100001] = {0, };
int result[100001];

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
    
    dfs(R);

    for(int i = 1; i <= N; i++)
    {
        cout << result[i] << '\n';
    }

    return 0;
}

void dfs(int start)
{
    if (visited[start]) return ;

    visited[start] = true;
    result[start] = cnt;
    cnt++;

    sort(vertex[start].begin(), vertex[start].end());
    for (int i = 0; i < vertex[start].size(); i++)
    {
        dfs(vertex[start][i]);
    }
}