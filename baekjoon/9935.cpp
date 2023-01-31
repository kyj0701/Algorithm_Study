#include <iostream>
#include <stack>

using namespace std;

string str;
string ex;
string res;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    bool check;

    res = "";

    cin >> str;
    cin >> ex;

    for (int i = 0; i < str.size(); i++)
    {
        res += str[i];

        if (res.back() == ex.back())
        {
            check = true;
            for (int j = 0; j < ex.size(); j++)
            {
                if (res[res.size() - ex.size() + j] != ex[j])
                {
                    check = false;
                    break;
                }
            }

            if (check)
            {
                for (int j = 0; j < ex.size(); j++) res.pop_back();
            }
        }
    }

    if (!res.size()) cout << "FRULA";
    else cout << res;

    return 0;
}