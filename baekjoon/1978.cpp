#include <cstdio>
#include <vector>

using namespace std;

int arr[1001];

int main(void)
{
    int N;
    int cnt = 0;

    // cin >> M >> N;
    scanf("%d", &N);

    int nums[N];

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &nums[i]);
    }

    for (int i = 2; i <= 1000; i++)
    {
        arr[i] = i;
    }

    for (int i = 2; i * i <= 1000; i++)
    {
        if (arr[i] == 0) continue;
        for (int j = i * 2; j <= 1000; j += i)
        {
            if (arr[j] == 0) continue;
            else arr[j] = 0;
        }
    }

    for (auto val : nums)
    {
        if (arr[val] != 0) cnt++;
    }

    printf("%d", cnt);
}