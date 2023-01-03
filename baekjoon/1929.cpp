#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int arr[1000001];

int main(void)
{
    int M, N;

    // cin >> M >> N;
    scanf("%d %d", &M, &N);

    for (int i = 2; i <= N; i++)
    {
        arr[i] = i;
    }

    for (int i = 2; i * i <= N; i++)
    {
        if (arr[i] == 0) continue;
        for (int j = i * 2; j <= N; j += i)
        {
            if (arr[j] == 0) continue;
            else arr[j] = 0;
        }
    }

    for (int i = M; i <= N; i++)
    {
        if (arr[i] != 0) printf("%d\n", arr[i]);
        // cout << arr[i] << endl;
    }
}