#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int,int>> v;
int DP[101];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    int A, B;
    int result = 0;

    cin >> N;

    for(int i = 0; i < N; i++)
    {
        cin >> A >> B;
        v.push_back({A, B});
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < N; i++)
    {
        DP[i] = 1;

        for (int j = 0; j < i; j++)
        {
            if (v[i].second > v[j].second) DP[i] = max(DP[i], DP[j] + 1);
        }

        result = max(result, DP[i]);
    }

    cout << N - result;

    return 0;
}