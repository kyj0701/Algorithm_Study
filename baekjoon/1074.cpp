#include <iostream>

using namespace std;

int N, r, c;
int res;

void Z(int y, int x, int size);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> r >> c;

    Z(0, 0, (1 << N));

    return 0;
}

void Z(int y, int x, int size)
{
    if (y == r && x == c)
    {
        cout << res << '\n';
        return;
    }

    if (r < y + size && r >= y && c < x + size && c >= x)
    {
        Z(y, x, size / 2);
        Z(y, x + size / 2, size / 2);
        Z(y + size / 2, x, size / 2);
        Z(y + size / 2, x + size / 2, size / 2);
    }
    else
    {
        res += size * size;
    }
}