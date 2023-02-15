#include <iostream>
#include <stack>

using namespace std;

int N;
int nums[1000001];
int NGE[1000001];
stack<int> s;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> nums[i];
    }

    for (int i = 0; i < N; i++)
    {
        while(!s.empty() && nums[s.top()] < nums[i])
        {
            NGE[s.top()] = nums[i];
            s.pop();
        }
        s.push(i);
    }

    while (!s.empty())
    {
        NGE[s.top()] = -1;
        s.pop();
    }

    for (int i = 0; i < N; i++)
    {
        cout << NGE[i] << ' ';
    }
    
    return 0;
}