#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define INF 987654321

using namespace std;

int V, E, K;
int shortest[20001];
vector <pair<int,int>> graph[20001];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int u, v, w;

    cin >> V >> E;
    cin >> K;

    for (int i = 0; i < E; i++)
    {
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v, w));
    }

    for (int i = 1; i <= V; i++)
    {
        shortest[i] = INF;
    }

    priority_queue<pair<int, int>> pq;

    pq.push(make_pair(0, K));
    shortest[K] = 0;

    while (!pq.empty())
    {
        int cost = -pq.top().first;
        int current = pq.top().second;
        pq.pop();

        for (int i = 0; i < graph[current].size(); i++)
        {
            int next = graph[current][i].first;
            int nCost = graph[current][i].second;

            if (cost + nCost < shortest[next])
            {
                shortest[next] = cost + nCost;
                pq.push(make_pair(-shortest[next], next));
            }
        }
        
    }

    for (int i = 1; i <= V; i++)
    {
        if (shortest[i] == INF) cout << "INF\n";
        else cout << shortest[i] << '\n';
    }

    return 0;
}