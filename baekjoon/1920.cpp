#include <cstdio>
#include <algorithm>

using namespace std;

int N, M;
int nums[100001];
int num;

// void binarySearch(int n, int key)
// {
//     int start = 0;
//     int end = n-1;
//     int mid;

//     while (end - start >= 0)
//     {
//         mid = (start + end) / 2;

//         if (nums[mid] == key) printf("1\n");
//         else if (nums[mid] > key) end = mid - 1;
//         else start = mid + 1;
//     }

//     printf("0\n");

//     return;
// }

int main(void)
{
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &nums[i]);
    }
    
    sort(nums, nums + N);

    scanf("%d", &M);

    for (int i = 0; i < M; i++)
    {
        scanf("%d", &num);

        if (binary_search(nums, nums + N, num)) printf("1\n");
        else printf("0\n");
    }
    return 0;
}