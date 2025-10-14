#include <iostream>
#include <deque>
#include <vector>
using namespace std;

void printKMax(const vector<int>& arr, const int n, const int k)
{
    deque<int> dq;
    for (int i = 0; i < n; i++)
    {
        if (!dq.empty() && dq.front() == i - k)
            dq.pop_front();

        while (!dq.empty() && arr.at(dq.back()) < arr.at(i))
            dq.pop_back();

        dq.push_back(i);

        if (i >= k - 1)
            cout << arr[dq.front()] << " ";
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t > 0)
    {
        int n, k;
        cin >> n >> k;
        vector<int> arr;
        for (int i = 0; i < n; i++)
        {
            int ai;
            cin >> ai;
            arr.push_back(ai);
        }
        printKMax(arr, n, k);
        t--;
    }
    return 0;
}