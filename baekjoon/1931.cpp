#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> schedule;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    int start, end;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> start >> end;

        schedule.push_back({end, start});
    }

    sort(schedule.begin(), schedule.end());

    int time = schedule[0].first;
    int res = 1;

    for (int i = 1; i < N; i++)
    {
        if (time <= schedule[i].second)
        {
            res++;
            time = schedule[i].first;
        }
    }

    cout << res;

    return 0;
}