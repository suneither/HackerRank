#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str)
{
    vector<int> numbers;
    int number;
    char ch;

    stringstream ss;
    ss.str(str);

    while (ss >> number)
    {
        numbers.push_back(number);
        ss >> ch;
    }
    return numbers;
}

int main()
{
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for (int i = 0; i < integers.size(); i++)
    {
        cout << integers[i] << "\n";
    }

    return 0;
}