#include <iostream>
#include <deque>

using namespace std;

int check[100001];
int N, K;

int BFS();

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;
    cout << BFS();

    return 0;
}

int BFS()
{
    deque<int> dq;
    dq.push_back(N);
    check[N] = 1;

    while(!dq.empty())
    {
        int locate = dq.front();
        dq.pop_front();

        if (locate == K)
        {
            return check[K] - 1;
        }

        if (locate * 2 < 100001 && !check[locate * 2])
        {
            dq.push_front(locate * 2);
            check[locate * 2] = check[locate];
        }

        if (locate + 1 < 100001 && !check[locate + 1])
        {
            dq.push_back(locate + 1);
            check[locate + 1] = check[locate] + 1;
        }

        if (locate - 1 >= 0 && !check[locate - 1])
        {
            dq.push_back(locate - 1);
            check[locate - 1] = check[locate] + 1;
        }
    }
}