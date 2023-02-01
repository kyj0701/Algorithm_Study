#include <iostream>
#include <algorithm>

using namespace std;

int N;
int red, green, blue;
int cost[1001][3];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    cost[0][0] = 0;
    cost[1][0] = 0;
    cost[2][0] = 0;

    for (int i = 1; i <= N; i++)
    {
        cin >> red >> green >> blue;
        cost[i][0] = min(cost[i-1][1], cost[i-1][2]) + red;
        cost[i][1] = min(cost[i-1][0], cost[i-1][2]) + green;
        cost[i][2] = min(cost[i-1][0], cost[i-1][1]) + blue;
    }

    cout << min(cost[N][0], min(cost[N][1], cost[N][2]));

    return 0;
}