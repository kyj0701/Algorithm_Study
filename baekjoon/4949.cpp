#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while (true)
    {
        stack<int> st;
        string input;

        getline(cin, input);

        if (input == ".") break;

        bool flag = false;
        for (int i = 0; i < input.length(); i++)
        {
            if (input[i] == '(')
            {
                st.push(0);
            }
            else if (input[i] == '[')
            {
                st.push(1);
            }
            else if (input[i] == ')')
            {
                if (!st.empty() && st.top() == 0) st.pop();
                else
                {
                    flag = true;
                    break;
                }
            }
            else if (input[i] == ']')
            {
                if (!st.empty() && st.top() == 1) st.pop();
                else
                {
                    flag = true;
                    break;
                }
            }
        }

        if (!flag && st.empty()) cout << "yes\n";        
        else cout << "no\n";
    }

    return 0;
}