#include <cstdio>
#include <climits>

using namespace std;

int main(void)
{
    int N, K, num;
    int sum = 0;
    int max = INT_MIN;

    scanf("%d %d", &N, &K);

    int nums[N];

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &num);
        sum += num;
        nums[i] = sum;

        if (i == K-1)
        {
            if (nums[i] >= max) max = nums[i];
        }
        else if (i > K-1)
        {
            int tmp = nums[i] - nums[i-K];
            if (tmp >= max) max = tmp;
        }
    }

    printf("%d", max);

    return 0;
}