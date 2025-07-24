#include <iostream>

using namespace std;

int max_of_four(int a, int b, int c, int d);
int greaterOfTwo(int a, int b);

int main()
{
    int a, b, c, d;

    cin >> a;
    cin >> b;
    cin >> c;
    cin >> d;

    cout << max_of_four(a, b, c, d);
}

int max_of_four(int a, int b, int c, int d)
{
    int max = 0;
    max = greaterOfTwo(a, b);
    max = greaterOfTwo(max, c);
    max = greaterOfTwo(max, d);
    return max;
}

int greaterOfTwo(int a, int b)
{
    return a > b ? a : b;
}
