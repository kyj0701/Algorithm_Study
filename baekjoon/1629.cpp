#include <iostream>

using namespace std;

long long power(long long b);

long long a, b, c, t;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b >> c;

    cout << power(b);

    return 0;
}

long long power(long long b)
{
    if (b == 0 || a == 1) return 1;
    if (b == 1) return a % c;

    t = power(b / 2) % c;

    if (b % 2 == 0) return t * t % c;
    else return t * t % c * a % c;
}