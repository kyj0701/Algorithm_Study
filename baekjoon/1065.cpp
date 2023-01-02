#include <iostream>

using namespace std;

bool oneNum(int x);

int main(void)
{
    int N;
    int count = 0;

    cin >> N; // N <= 1000

    for (int i = 1; i <= N; i++)
    {
        if (oneNum(i)) count++;
    }

    cout << count;

    return 0;
}

bool oneNum(int x)
{
    if (x < 100) return true;
    else
    {
        int hundred = x / 100;
        int ten = (x % 100) / 10;
        int one = x % 10;

        if (2 * ten == hundred + one) return true;
        else
        {
            return false;
        }
    }
}