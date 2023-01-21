#include <iostream>

using namespace std;

int N, M;
int nums[9] = {0,};
bool visited[9] = {0,};

void DFS(int cnt);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    DFS(0);

    return 0;
}

void DFS(int cnt)
{
    if (cnt == M)
    {
        for(int i = 0; i < M; i++) cout << nums[i] << ' ';
        cout << '\n';
        return;
    }
    
    for (int i = 1; i <= N; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            nums[cnt] = i;
            DFS(cnt + 1);
            visited[i] = false;
        }
    }
}