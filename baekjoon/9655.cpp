#include <iostream>

using namespace std;

int N;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    if (N % 2 == 0)
    {
        cout << "CY";
    }
    else
    {
        cout << "SK";
    }

    return 0;
}