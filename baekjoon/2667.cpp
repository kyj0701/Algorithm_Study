#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,-1,1};
int apartment[51][51];
int complex = 0;
int apart;
vector<int> aparts;
bool visited[51][51] = {0, };

void dfs(int y, int x);

int main(void)
{
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%1d", &apartment[i][j]);
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (apartment[i][j] && !visited[i][j])
            {
                complex++;
                visited[i][j] = true;
                apart = 1;
                dfs(i, j);
                aparts.push_back(apart);
            }
        }
    }

    sort(aparts.begin(), aparts.end());

    printf("%d\n", complex);

    for (int i = 0; i < aparts.size(); i++)
    {
        printf("%d\n", aparts[i]);
    }

    return 0;
}

void dfs(int y, int x)
{
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;

        if (apartment[ny][nx] && !visited[ny][nx])
        {
            apart++;
            visited[ny][nx] = true;
            dfs(ny, nx);
        }
    }
}