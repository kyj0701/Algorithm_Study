#include <cstdio>
#include <numeric>

using namespace std;

int main(void)
{
    int N, M, num;
    int start, end;

    scanf("%d %d", &N, &M);

    int nums[N];
    int sums[M];
    int sum = 0;

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &num);
        sum += num;
        nums[i] = sum;
    }

    for (int i = 0; i < M; i++)
    {
        scanf("%d %d", &start, &end);
        if (start == 1) sums[i] = nums[end-1];
        else sums[i] = nums[end-1] - nums[start-2];
    }

    for (int i = 0; i < M; i++)
    {
        printf("%d\n", sums[i]);
    }

    return 0;
}