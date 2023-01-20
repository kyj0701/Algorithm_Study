#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> nums;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, num, x;
    int cnt = 0;

    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        nums.push_back(num);
    }

    cin >> x;

    sort(nums.begin(), nums.end());

    int i = 0;
    int j = n-1;
    int sum = 0;

    while(true)
    {
        if (i >= j) break;

        sum = nums[i] + nums[j];

        if (sum == x) 
        {
            cnt++;
            i++;
            j--;
        }
        else if (sum > x) j--;
        else i++;
    }

    cout << cnt;

    return 0;
}
