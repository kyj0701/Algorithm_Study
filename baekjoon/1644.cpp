#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
bool check[4000001];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    vector<int> prime;

    for (int i = 0; i <= N; i++)
    {
        check[i] = true;
    }

    for (int i = 2; i * i <= N; i++)
    {
        if (check[i])
        {
            for (int j = i + i; j <= N; j += i)
            {
                check[j] = false;
            }
        }
    }

    for (int i = 2; i <= N; i++)
    {
        if(check[i])
        {
            prime.push_back(i);
        }
    }

    int start = 0;
    int end = 0;
    int cnt = 0;
    int sum;

    if (!prime.empty()) sum = prime[0];
    else sum = 0;

    while (start <= end && end < prime.size())
    {
        if (sum == N) cnt++;

        if (sum < N)
        {
            end++;
            sum += prime[end];
        }
        else
        {
            sum -= prime[start];
            start++;
        }
    }

    cout << cnt;

    return 0;
}