#include <iostream>

using namespace std;

void solve(int x, int y, int size);

int paper[2188][2188];
int p1;
int p2;
int p3;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    p1 = 0;
    p2 = 0;
    p3 = 0;
    
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> paper[i][j];
        }
    }

    solve(0, 0, N);

    cout << p1 << '\n';
    cout << p2 << '\n';
    cout << p3;

    return 0;
}

void solve(int x, int y, int size)
{
    int check = paper[x][y];

    for (int i = x; i < x + size; i++)
    {
        for (int j = y; j < y + size; j++)
        {
            if (check != paper[i][j]) check = 2;

            if (check == 2)
            {
                solve(x, y, size / 3);
                solve(x, y + size / 3, size / 3);
                solve(x, y + size * 2 / 3, size / 3);
                solve(x + size / 3, y, size / 3);
                solve(x + size * 2 / 3, y, size / 3);
                solve(x + size / 3, y + size / 3, size / 3);
                solve(x + size * 2 / 3, y + size * 2 / 3, size / 3);
                solve(x + size / 3, y + size * 2 / 3, size / 3);
                solve(x + size * 2 / 3, y + size / 3, size / 3);
                return;
            }
        }
    }

    if (check == -1) p1++;
    else if (check == 0) p2++;
    else p3++;
}