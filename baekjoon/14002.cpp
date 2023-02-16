#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int A[1001];
int DP[1001];
vector<int> LIS;
int result;
int len;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int index;

    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cin >> A[i];
        len = 0;

        for (int j = 1; j < i; j++)
        {
            if (A[i] > A[j])
            {
                len = max(DP[j], len);
            }
        }
        DP[i] = len + 1;

        if (result < len + 1)
        {
            result = len + 1;
            index = i;
        }
    }

    for (int i = index; i > 0; i--)
    {
        if (DP[i] == result)
        {
            LIS.push_back(A[i]);
            result--;
        }
    }

    int size = LIS.size();

    cout << size << '\n';

    for(int i = 0; i < size; i++)
    {
        cout << LIS.back() << ' ';
        LIS.pop_back();
    }

    return 0;
}