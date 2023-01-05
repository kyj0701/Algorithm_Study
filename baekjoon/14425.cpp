#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int main(void)
{
    int N, M;
    set<string> strSet;
    vector<string> strList;
    string strInput;
    int cnt = 0;

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> strInput;
        strSet.insert(strInput);
    }

    for (int i = 0; i < M; i++)
    {
        cin >> strInput;
        strList.push_back(strInput);
    }

    for (int i = 0; i < M; i++)
    {
        if (strSet.find(strList[i]) != strSet.end()) cnt++;
    }

    cout << cnt;

    return 0;
}