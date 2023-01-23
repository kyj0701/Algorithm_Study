#include <iostream>
#include <vector>

using namespace std;

string S;
string tmp;
vector<int> subsum[26];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int q, l, r;
    char a;

    cin >> S >> q;

    for (int i = 0; i < S.size(); i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (i == 0)
            {
                if (S[i] - 'a' == j) subsum[j].push_back(1);
                else subsum[j].push_back(0);
            }
            else
            {
                if (S[i] - 'a' == j) subsum[j].push_back(subsum[j][i - 1] + 1);
                else subsum[j].push_back(subsum[j][i - 1]);
            }
        }
    }

    for (int i = 0; i < q; i++)
    {
        cin >> a >> l >> r;
        
        if (l == 0) cout << subsum[a - 'a'][r] << '\n';
        else cout << subsum[a - 'a'][r] - subsum[a - 'a'][l - 1] << '\n';
    }

    return 0;
}


// #include <iostream>
// #include <vector>

// using namespace std;

// string S;
// string tmp;
// vector<int> subsum[26];

// int main(void)
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);

//     int q, l, r;
//     char a;

//     cin >> S >> q;

//     for (int i = 0; i < S.size(); i++)
//     {
//         for (int j = 0; j < 26; j++)
//         {
//             if (i == 0)
//             {
//                 if (S[i] - 'a' == j) subsum[j].push_back(1);
//                 else subsum[j].push_back(0);
//             }
//             else
//             {
//                 if (S[i] - 'a' == j) subsum[j].push_back(subsum[j][i - 1] + 1);
//                 else subsum[j].push_back(subsum[j][i - 1]);
//             }
//         }
//     }

//     for (int i = 0; i < q; i++)
//     {
//         cin >> a >> l >> r;
        
//         if (l == 0) cout << subsum[a - 'a'][r] << '\n';
//         else cout << subsum[a - 'a'][r] - subsum[a - 'a'][l - 1] << '\n';
//     }

//     return 0;
// }