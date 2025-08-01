#include <iostream>
#include <vector>

using namespace std;

int indexify(int i);

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

    int element_nr;
    cin >> element_nr;

    numbers.erase(numbers.begin() + indexify(element_nr));

    int start, end;
    cin >> start >> end;

    numbers.erase(numbers.begin() + indexify(start), numbers.begin() + indexify(end));

    cout << numbers.size() << endl;
    for (int i = 0; i < numbers.size(); i++)
        cout << numbers[i] << " ";
}

int indexify(int i)
{
    return --i;
}
