#include <iostream>

using namespace std;

int N;
int board[15];
int count = 0;

bool check(int index)
{
    for (int i = 0; i < index; i++)
    {
        if (board[index] == board[i] || index - i == abs(board[index] - board[i]))
        {
            return false;
        }
    }
    return true;
}

void n_queen(int index)
{
    if (index == N)
    {
        count++;
        return;
    }

    for (int i = 0; i < N; i++)
    {
        board[index] = i;

        if (check(index))
        {
            n_queen(index + 1);
        } 
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    n_queen(0);

    cout << count;

    return 0;   
}