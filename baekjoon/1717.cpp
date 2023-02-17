#include <iostream>

using namespace std;

int nums[1000001];

int find(int x)
{
    if (nums[x] == x) return x;
    return nums[x] = find(nums[x]);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    int num, a, b;

    cin >> n >> m;

    for (int i = 0; i <= n; i++)
    {
        nums[i] = i;
    }

    for (int i = 0; i < m; i++)
    {
        cin >> num >> a >> b;

        if (num == 0)
        {
            if (a > b) nums[find(a)] = find(b);
            else nums[find(b)] = find(a);
        }
        else
        {
            if (nums[find(a)] == nums[find(b)]) cout << "YES\n";
            else cout << "NO\n";
        }

    }

    return 0;
}