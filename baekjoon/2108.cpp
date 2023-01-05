#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

bool compare(pair<int,int> p1, pair<int,int> p2)
{
    if (p1.second == p2.second)
    {
        return p1.first < p2.first;
    }
    return p1.second > p2.second;
}

int main(void)
{
    int N;
    int num;
    vector<int> numList;
    vector<pair<int,int>> numMany;

    double avg = 0;
    int mid = 0; 
    int many = 0; 
    int ran = 0;


    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> num;
        numList.push_back(num);
        avg += num;

        if (i == 0)
        {
            numMany.push_back(make_pair(num, 1));
        }
        else
        {
            bool flag = true;

            for (int j = 0; j < numMany.size(); j++)
            {
                if (numMany[j].first == num)
                {
                    numMany[j].second++;
                    flag = false;
                    break;
                }
            }

            if (flag) numMany.push_back(make_pair(num, 1));
        }
    }

    sort(numMany.begin(), numMany.end(), compare);

    many = numMany[0].first;
    if (numMany[0].second == numMany[1].second) many = numMany[1].first;

    avg /= N;

    sort(numList.begin(), numList.end());

    mid = numList[N/2];

    ran = numList[N-1] - numList[0];

    int mean = round(avg);
    cout << mean << endl;
    cout << mid << endl;
    cout << many << endl;
    cout << ran << endl;

    return 0;
}