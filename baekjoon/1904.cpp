#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    long long tiles[1000001];
    tiles[0] = 1;
    tiles[1] = 2;

    cin >> N;

    for (int i = 2; i < N; i++)
    {
        long long tmp;
        tmp = tiles[i-1] + tiles[i-2];
        tiles[i] = tmp % 15746;
    }

    cout << tiles[N-1];

    return 0;
}