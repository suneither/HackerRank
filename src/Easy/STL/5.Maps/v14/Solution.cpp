#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    int q;
    cin >> q;

    map<string, int> students_marks;

    while (q--)
    {
        int type;
        cin >> type;

        string x;
        cin >> x;

        switch (type)
        {
        case 1:
        {
            int y;
            cin >> y;

            auto pair = students_marks.insert(make_pair(x, y));
            if (!pair.second)
                pair.first->second += y;

            break;
        }

        case 2:
        {
            students_marks.erase(x);

            break;
        }
        default:
        {
            if (students_marks.find(x) != students_marks.end())
                cout << students_marks.at(x) << endl;
            else
                cout << 0 << endl;

            break;
        }
        }
    }
}