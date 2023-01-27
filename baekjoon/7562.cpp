#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

bool check[301][301];
int dirX[8] = {2, 1, -2, -1, -2, -1, 1, 2};
int dirY[8] = {1, 2, 1, 2, -1, -2, -2, -1};
queue <tuple<int,int,int>> q;


void reset()
{
    while (!q.empty()) q.pop();
    for (int i = 0; i < 301; i++)
    {
        for (int j = 0; j < 301; j++)
        {
            check[i][j] = false;
        }
    }

}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T, I;
    int answer;
    int cnt;
    int curX, curY;
    int tarX, tarY;
    int tmpX, tmpY;
    
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        reset();

        cin >> I;
        cin >> curX >> curY;
        cin >> tarX >> tarY;
        answer = 0;
        cnt = 0;

        q.emplace(curX, curY, 0);
        check[curX][curY] = true;

        while (!q.empty())
        {
            tmpX = get<0>(q.front());
            tmpY = get<1>(q.front());
            cnt = get<2>(q.front());
            q.pop();

            if (tmpX == tarX && tmpY == tarY)
            {
                cout << cnt << '\n';
                break;
            }
            
            for (int i = 0; i < 8; i++)
            {
                if (tmpX + dirX[i] >= 0 && tmpY + dirY[i] >= 0 && tmpX + dirX[i] < I && tmpY + dirY[i] < I && !check[tmpX + dirX[i]][tmpY + dirY[i]])
                {
                    q.emplace(tmpX + dirX[i], tmpY + dirY[i], cnt + 1);
                    check[tmpX + dirX[i]][tmpY + dirY[i]] = true;
                }
            }
        }
    }

    return 0;
}