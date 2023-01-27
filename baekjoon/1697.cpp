#include <iostream>
#include <queue>

using namespace std;

bool check[100001];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    int answer;
    int cnt;
    int locate;
    int x1, x2, x3;
    queue<pair<int, int>> q;

    cin >> N >> K;

    q.emplace(N, 0);

    while(!q.empty())
    {
        locate = q.front().first;
        cnt = q.front().second;
        q.pop();

        if (locate == K)
        {
            answer = cnt;
            break;
        }

        x1 = locate - 1;
        x2 = locate + 1;
        x3 = locate * 2;

        if (x1 >= 0 && !check[x1])
        {
            q.emplace(x1, cnt + 1);
            check[x1] = true;
        }

        if (x2 <= K && !check[x2])
        {
            q.emplace(x2, cnt + 1);
            check[x2] = true;
        }

        if (x3 <= K+1 && !check[x3])
        {
            q.emplace(x3, cnt + 1);
            check[x3] = true;
        }
    }

    cout << answer;

    return 0;
}