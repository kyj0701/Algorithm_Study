#include <iostream>
#include <utility>

using namespace std;

int main(void)
{
    int N;
    int rank = 1;
    pair<int, int> p[50];

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int weight, height;
        cin >> p[i].first >> p[i].second;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i != j && p[i].first < p[j].first && p[i].second < p[j].second) rank++;
        }
        cout << rank << " ";
        rank = 1;
    }

    return 0;
}