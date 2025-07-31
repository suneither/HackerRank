#include <iostream>
using namespace std;

class Box
{
private:
    int m_length, m_breadth, m_height;

public:
    Box()
    {
        m_length = 0;
        m_breadth = 0;
        m_height = 0;
    }
    Box(int length, int breadth, int height)
    {
        m_length = length;
        m_breadth = breadth;
        m_height = height;
    }
    Box(Box &box)
    {
        m_length = box.getLength();
        m_breadth = box.getBreadth();
        m_height = box.getHeight();
    }
    int getLength()
    {
        return m_length;
    }
    int getBreadth()
    {
        return m_breadth;
    }
    int getHeight()
    {
        return m_height;
    }
    long long calculateVolume()
    {
        // using 1LL to force calculation to be performed in 64bit instead 32bit
        // calculation between only int values might cause overflow
        // even if return type is of 64 bits calculation is made in 32 bits
        // causing overflow at large numbers, 1LL prevents overflowing by forcing
        // calculation to be done in 64 bits
        return 1LL * m_length * m_breadth * m_height;
    }
    bool operator<(Box &box)
    {
        if (m_length < box.getLength())
        {
            return true;
        }
        else if (m_breadth < box.getBreadth() &&
                 m_length == box.getLength())
        {
            return true;
        }
        else if (m_height < box.getHeight() &&
                 m_breadth == box.getBreadth() &&
                 m_length == box.getLength())
        {
            return true;
        }

        return false;
    }
};

ostream &operator<<(ostream &out, Box &box)
{
    return out << box.getLength() << " " << box.getBreadth() << " " << box.getHeight() << endl;
};

void check2()
{
    int n;
    cin >> n;
    Box temp;
    for (int i = 0; i < n; i++)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            cout << temp << endl;
        }
        if (type == 2)
        {
            int l, b, h;
            cin >> l >> b >> h;
            Box NewBox(l, b, h);
            temp = NewBox;
            cout << temp << endl;
        }
        if (type == 3)
        {
            int l, b, h;
            cin >> l >> b >> h;
            Box NewBox(l, b, h);
            if (NewBox < temp)
            {
                cout << "Lesser\n";
            }
            else
            {
                cout << "Greater\n";
            }
        }
        if (type == 4)
        {
            cout << temp.calculateVolume() << endl;
        }
        if (type == 5)
        {
            Box NewBox(temp);
            cout << NewBox << endl;
        }
    }
}

int main()
{
    check2();
}