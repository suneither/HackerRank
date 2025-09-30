#include <iostream>
#include <cstdlib>

using namespace std;

void update(int *a, int *b)
{
    int tempA = *a;

    *a += *b;
    *b = abs(tempA - *b);
}

int main()
{
    int a, b;

    cin >> a;
    cin >> b;

    update(&a, &b);

    cout << a << endl;
    cout << b << endl;
}