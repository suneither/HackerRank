#include <iostream>
#include <set>

using namespace std;

int main()
{
    int q;
    cin >> q;

    set<int> set;

    while (q > 0)
    {
        int y, x;
        cin >> y >> x;

        switch (y)
        {
        case 1:
        {
            set.insert(x);
            break;
        }
        case 2:
        {
            set.erase(x);
            break;
        }
        default:
            if (set.end() != set.find(x))
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
            break;
        }

        q--;
    }
}