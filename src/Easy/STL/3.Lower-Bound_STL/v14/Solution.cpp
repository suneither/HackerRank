#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> sorted_array;

    while (n > 0)
    {
        int number;
        cin >> number;
        sorted_array.push_back(number);
        n--;
    }

    int q;
    cin >> q;

    while (q > 0)
    {
        int y;
        cin >> y;

        vector<int>::iterator low_bound = lower_bound(sorted_array.begin(), sorted_array.end(), y);
        int idx = (low_bound - sorted_array.begin()) + 1;

        if (*low_bound == y)
            cout << "Yes " << idx << endl;
        else
            cout << "No " << idx << endl;

        q--;
    }
}