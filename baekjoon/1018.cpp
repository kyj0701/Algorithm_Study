#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

int count_BW(int x, int y);
int count_WB(int x, int y);

string BW[8] =
{
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB"
};

string WB[8] =
{
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW"
};

string board[50];

int main(void)
{
    int N, M;
    int cnt = 0;
    int min = 10000;

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> board[i];
    }

    for (int i = 0; i + 8 <= N; i++)
    {
        for (int j = 0; j + 8 <= M; j++)
        {   
            int tmp;
            int tmp_BW = count_BW(i,j);
            int tmp_WB = count_WB(i,j);

            if (tmp_BW < tmp_WB) tmp = tmp_BW;
            else tmp = tmp_WB;

            if (tmp < min) min = tmp;
        }
    }

    cout << min;

    return 0;
}

int count_BW(int x, int y)
{
    int cnt = 0;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (board[x + i][y + j] != BW[i][j]) cnt++;
        }
    }

    return cnt;
}

int count_WB(int x, int y)
{
    int cnt = 0;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (board[x + i][y + j] != WB[i][j]) cnt++;
        }
    }

    return cnt;
}