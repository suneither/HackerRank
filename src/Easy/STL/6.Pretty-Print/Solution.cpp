#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int T;
    cin >> T;
    cout << setiosflags(ios::uppercase);
    cout << setw(0xf) << internal;
    while (T--)
    {
        double A;
        cin >> A;
        double B;
        cin >> B;
        double C;
        cin >> C;

        cout.flags(ios::left | ios::hex | ios::showbase);
        cout << resetiosflags(ios::uppercase);
        cout << (long long)A << endl;

        cout << setw(15) << right << showpos << fixed << setprecision(2) << setfill('_');
        cout << B << endl;

        cout << resetiosflags(ios::showpos) << setiosflags(ios::uppercase) << scientific << setprecision(9);
        cout << C << endl;
    }
    return 0;
}