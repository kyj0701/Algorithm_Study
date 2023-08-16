#include <iostream>
#include <queue>

using namespace std;

int N, num;
int nums[100001];

priority_queue<int, vector<int>, less<int>> max_heap;
priority_queue<int, vector<int>, greater<int>> min_heap;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> num;

        if (max_heap.empty())
        {
            max_heap.emplace(num);
        }
        else if (max_heap.size() == min_heap.size())
        {
            max_heap.emplace(num);
        }
        else
        {
            min_heap.emplace(num);
        }

        if (!max_heap.empty() && !min_heap.empty() && max_heap.top() > min_heap.top())
        {
            int a = max_heap.top();
            int b = min_heap.top();

            max_heap.pop();
            min_heap.pop();

            max_heap.emplace(b);
            min_heap.emplace(a);
        }

        cout << max_heap.top() << '\n';
    }

    return 0;
}