#include <iostream>
using namespace std;

template <class T>
class AddElements
{
private:
    T element;

public:
    AddElements(T element) : element(element) {}
    T add(T arg) { return element + arg; }
};

template <>
class AddElements<string>
{
private:
    string element;

public:
    AddElements(const string &element) : element(element) {}
    string concatenate(const string &arg) { return element + arg; }
};

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string type;
        cin >> type;
        if (type == "float")
        {
            double element1, element2;
            cin >> element1 >> element2;
            AddElements<double> myfloat(element1);
            cout << myfloat.add(element2) << endl;
        }
        else if (type == "int")
        {
            int element1, element2;
            cin >> element1 >> element2;
            AddElements<int> myint(element1);
            cout << myint.add(element2) << endl;
        }
        else if (type == "string")
        {
            string element1, element2;
            cin >> element1 >> element2;
            AddElements<string> mystring(element1);
            cout << mystring.concatenate(element2) << endl;
        }
    }
    return 0;
}
