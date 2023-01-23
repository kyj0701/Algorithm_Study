#include <iostream>
#include <vector>

using namespace std;

int arr[250000];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    int cnt = 0;

    for (int i = 2; i < 250000; i++)
    {
        arr[i] = i;
    }

    for (int i = 2; i * i <= 250000; i++)
    {
        if (arr[i] == 0) continue;
        for (int j = i * 2; j <= 250000; j += i)
        {
            if (arr[j] == 0) continue;
            else arr[j] = 0;
        }
    }

    while(true)
    {
        cin >> n;

        if (n == 0) break;

        for (int i = n + 1; i <= n * 2; i++)
        {
            if (arr[i] != 0) cnt++;
        }

        cout << cnt << '\n';
        cnt = 0;
    }

    return 0;
}