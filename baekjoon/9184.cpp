#include <iostream>

using namespace std;

int nums[21][21][21];

int wfun(int a, int b, int c);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int a, b, c;

    while(true)
    {
        cin >> a >> b >> c;

        if (a == -1 && b == -1 && c == -1)
        {
            break;
        }

        cout << "w(" << a << ", " << b << ", " << c << ") = " << wfun(a, b, c) << '\n';
    }

    return 0;
}

int wfun(int a, int b, int c)
{
    if (a <= 0 || b <= 0 || c <= 0) return 1;

    if (a > 20 || b > 20 || c > 20) return wfun(20, 20, 20);

    if (nums[a][b][c] != 0) return nums[a][b][c];

    
    if (a < b && b < c) 
    {
        nums[a][b][c] = wfun(a, b, c-1) + wfun(a, b-1, c-1) - wfun(a, b-1, c);
        return nums[a][b][c];
    }

    nums[a][b][c] = wfun(a-1, b, c) + wfun(a-1, b-1, c) + wfun(a-1, b, c-1) - wfun(a-1, b-1, c-1);
    return nums[a][b][c];
}