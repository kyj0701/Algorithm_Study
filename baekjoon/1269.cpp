#include <iostream>
#include <set>

using namespace std;

int main(void)
{
    int a, b;
    int num;
    set<int> nums;

    cin >> a >> b;

    for (int i = 0; i < a + b; i++)
    {
        cin >> num;

        if (nums.find(num) != nums.end())
        {
            nums.erase(num);
        }
        else
        {
            nums.insert(num);
        }
    }

    cout << nums.size() << endl;

    return 0;
}