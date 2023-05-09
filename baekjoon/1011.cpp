#include <iostream>
#include <cmath>

using namespace std;

int T;
double x, y;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> x >> y;

        double dist = y - x;
        double distRoot = sqrt(dist);
        int roundDist = round(distRoot);

        if (distRoot <= roundDist) cout << roundDist * 2 - 1 << '\n';
        else cout << roundDist * 2 << '\n';
    }

    return 0;   
}