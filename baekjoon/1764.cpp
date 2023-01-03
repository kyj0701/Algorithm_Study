#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int main(void)
{
    int N, M;

    cin >> N >> M;

    string name;

    set<string> humans;

    vector<string> result;
    int cnt = 0;

    for (int i = 0; i < N + M; i++)
    {
        cin >> name;
        if (humans.find(name) != humans.end())
        {
            result.push_back(name);
            cnt++;
        }
        else
        {
            humans.insert(name);
        }

    }

    sort(result.begin(), result.end());

    cout << cnt << endl;

    for (string val : result)
    {
        cout << val << endl;
    }

    return 0;
}