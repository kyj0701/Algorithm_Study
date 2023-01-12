#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T, num;
    long long cases[101];
    cases[0] = 1;
    cases[1] = 1;
    cases[2] = 1;
    cases[3] = 2;
    cases[4] = 2;

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> num;

        if (num < 5)
        {
            cout << cases[num-1] << '\n';
            continue;
        }

        for (int j = 5; j < num; j++)
        {
            cases[j] = cases[j-1] + cases[j-5];
        }
        cout << cases[num-1] << '\n';
    }

    return 0;
}