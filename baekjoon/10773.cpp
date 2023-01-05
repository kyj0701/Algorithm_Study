#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
    int K;
    stack<int> st;
    int sum = 0;
    int num;

    cin >> K;

    for (int i = 0; i < K; i++)
    {
        cin >> num;
        if (num == 0)
        {
            st.pop();
        }
        else
        {
            st.push(num);
        }
    }

    while (!st.empty())
    {
        sum += st.top();
        st.pop();
    }

    cout << sum;

    return 0;
}