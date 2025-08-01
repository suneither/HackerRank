#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> numbers;

    while (n > 0)
    {
        int number;
        cin >> number;
        numbers.push_back(number);
        n--;
    }

    sort(numbers.begin(), numbers.end());

    for (int number : numbers)
        cout << number << " ";
}