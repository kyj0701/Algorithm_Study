#include <iostream>

using namespace std;

void solve(int x, int y, int size);

int paper[128][128];
int white;
int blue;

int main(void)
{
    int N;
    white = 0;
    blue = 0;
    
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> paper[i][j];
        }
    }

    solve(0, 0, N);

    cout << white << endl;
    cout << blue;

    return 0;
}

void solve(int x, int y, int size)
{
    int check = paper[x][y];

    for (int i = x; i < x + size; i++)
    {
        for (int j = y; j < y + size; j++)
        {
            if (check == 0 && paper[i][j] == 1) check = 2;
            else if (check == 1 && paper[i][j] == 0) check = 2; 

            if (check == 2)
            {
                solve(x, y, size / 2);
                solve(x, y + size / 2, size / 2);
                solve(x + size / 2, y, size / 2);
                solve(x + size / 2, y + size / 2, size / 2);
                return;
            }
        }
    }

    if (check == 0) white++;
    else blue++;
}