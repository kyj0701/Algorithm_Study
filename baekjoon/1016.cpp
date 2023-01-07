#include <cstdio>

using namespace std;

typedef long long ll;

int arr[1000001];
ll min, max;

int main(void)
{
	scanf("%lld %lld", &min, &max);

    for (int i = 0; i <= max - min; i++)
    {
        arr[i] = 1;
    }

	for(ll i = 2; i * i <= max; i++) {
        ll num = min / (i * i);

        if (min % (i * i)) num++;

        while (num * (i * i) <= max)
        {
            arr[num * (i * i) - min] = 0;
            num++;
        }
	}

    int cnt = 0;

    for (int i = 0; i <= max - min; i++)
    {
        if (arr[i] != 0) cnt++;
    }

	printf("%d", cnt);

	return 0;
}