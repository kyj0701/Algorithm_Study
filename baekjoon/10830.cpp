#include <iostream>

using namespace std;

long long N, B;
long long A[5][5];
long long tmp[5][5];
long long res[5][5];

void print_matrix(long long arr[5][5])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << arr[i][j] << ' ';
		cout << '\n';
	}
}

void Multiply_Matrix(long long X[5][5], long long Y[5][5])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            tmp[i][j] = 0;
            for(int k = 0; k < N; k++)
            {
                tmp[i][j] += X[i][k] * Y[k][j];
            }

            tmp[i][j] %= 1000;
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            X[i][j] = tmp[i][j];
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> B;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> A[i][j];
        }
        res[i][i] = 1;
    }

    while (B > 0)
    {
        if (B % 2 == 1)
        {
            Multiply_Matrix(res, A);
        }
        Multiply_Matrix(A, A);
        B /= 2;
    }

    print_matrix(res);

    return 0;   
}