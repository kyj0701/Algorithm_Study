#include <iostream>
#include <algorithm>

using namespace std;

int N;
int sol[100001];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    
    for (int i = 0; i < N; i++)
    {
        cin >> sol[i];
    }

    sort(sol, sol + N);

    int start = 0;
    int end = N - 1;
    int min = 2000000000;
    int tmp;
    int sol1, sol2;

    while(start < end)
    {
        tmp = sol[start] + sol[end];

        if (abs(tmp) < min) 
        {
            min = abs(tmp);
            sol1 = sol[start];
            sol2 = sol[end];
            if (tmp == 0) break;
        }

        if (tmp > 0) end--;
        else start++;
    }

    cout << sol1 << ' ' << sol2;

    return 0;
}