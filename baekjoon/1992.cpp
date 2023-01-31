#include <iostream>

using namespace std;

void solve(int x, int y, int size);

string quadtree[64];

int main(void)
{
    int N;
    
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> quadtree[i];
    }

    solve(0, 0, N);

    return 0;
}

void solve(int x, int y, int size)
{
    char check = quadtree[x][y];

    for (int i = x; i < x + size; i++)
    {
        for (int j = y; j < y + size; j++)
        {
            if (check != quadtree[i][j])
            {
                cout << '(';
                solve(x, y, size / 2);
                solve(x, y + size / 2, size / 2);
                solve(x + size / 2, y, size / 2);
                solve(x + size / 2, y + size / 2, size / 2);
                cout << ')';
                return;
            }
        }
    }

    cout << check;
}