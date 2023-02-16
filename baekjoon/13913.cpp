#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N, K;
bool check[100001];
int before[100001];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int x1, x2, x3;
    int locate, cnt;
    int answer = 0;
    queue<pair<int, int>> q;
    vector<int> res;

    cin >> N >> K;

    q.emplace(make_pair(N, 0));

    while(!q.empty())
    {
        locate = q.front().first;
        cnt = q.front().second;
        q.pop();

        if (locate == K)
        {
            int index = locate;
            while(index != N)
            {
                res.push_back(index);
                index = before[index];
            }
            cout << cnt << '\n';
            break;
        }

        x1 = locate - 1;
        x2 = locate + 1;
        x3 = locate * 2;

        if (x1 >= 0 && !check[x1])
        {
            q.emplace(make_pair(x1, cnt + 1));
            check[x1] = true;
            before[x1] = locate;
        }

        if (x2 <= K && !check[x2])
        {
            q.emplace(make_pair(x2, cnt + 1));
            check[x2] = true;
            before[x2] = locate;
        }

        if (x3 <= K+1 && !check[x3])
        {
            q.emplace(make_pair(x3, cnt + 1));
            check[x3] = true;
            before[x3] = locate;
        }
    }

    cout << N << ' ';

    for (int i = res.size() - 1; i >= 0 ; i--)
    {
        cout << res[i] << ' ';
    }

    return 0;
}