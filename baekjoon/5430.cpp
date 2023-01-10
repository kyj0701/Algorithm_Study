#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T, len;
    bool rflag, error;
    string p;
    string s;
    string buffer;
    deque<int> nums;

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        rflag = false;
        error = false;
        cin >> p;
        cin >> len;
        cin >> s;

        buffer = "";

        for (int j = 0; j < s.length(); j++) 
        {
            if (isdigit(s[j])) buffer += s[j];
            else {
                if (!buffer.empty()) 
                {
                    nums.push_back(stoi(buffer));
                    buffer = "";
                }
            }
        }

        for (char c : p)
        {
            if (c == 'R') rflag = !rflag;
            else if (c == 'D')
            {
                if (len == 0)
                {
                    cout << "error" << "\n";
                    error = true;
                    break;
                }

                if (rflag) nums.pop_back();
                else nums.pop_front();
                len--;
            }
        }

        if (!error) cout << '[';

        if (len != 0)
        {
            if (rflag)
            {
                for (auto l = nums.rbegin(); l != nums.rend(); l++)
                {
                    if (l == nums.rend() - 1) cout << *l;
                    else cout << *l << ',';
                }
            }
            else
            {
                for (auto l = nums.begin(); l != nums.end(); l++)
                {
                    if (l == nums.end() - 1) cout << *l;
                    else cout << *l << ',';
                }
            }
        }
        
        if (!error) cout << "]\n";

        nums.clear();
    }
    
    return 0;
}