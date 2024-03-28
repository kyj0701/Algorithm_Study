#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int x[1000001];
vector<int> v;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> x[i];
        v.push_back(x[i]);
    }

    sort(v.begin(),  v.end());
    v.erase(unique(v.begin(),  v.end()), v.end());

    for (int i = 0; i < N; i++)
    {
        int idx = lower_bound(v.begin(),  v.end(), x[i]) - v.begin();
        cout << idx << ' ';
    }

    return 0;   
}