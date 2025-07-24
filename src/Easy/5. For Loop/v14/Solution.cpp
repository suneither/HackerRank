#include <iostream>

using namespace std;

void printNumberRepresentation(int n);
bool isEven(int n);

int main()
{
    unsigned int a, b;
    cin >> a;
    cin >> b;

    for (int n = a; n <= b; n++)
    {
        printNumberRepresentation(n);
    }
}

void printNumberRepresentation(int n)
{
    switch (n)
    {
    case 1:
        cout << "one";
        break;
    case 2:
        cout << "two";
        break;
    case 3:
        cout << "three";
        break;
    case 4:
        cout << "four";
        break;
    case 5:
        cout << "five";
        break;
    case 6:
        cout << "six";
        break;
    case 7:
        cout << "seven";
        break;
    case 8:
        cout << "eight";
        break;
    case 9:
        cout << "nine";
        break;
    default:
    {
        if (isEven(n))
            cout << "even";
        else
            cout << "odd";
        break;
    }
    }
    cout << endl;
}

bool isEven(int n)
{
    return n % 2 == 0 ? true : false;
}