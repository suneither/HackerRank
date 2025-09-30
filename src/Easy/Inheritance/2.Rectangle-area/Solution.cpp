#include <iostream>
using namespace std;

class Rectangle
{
protected:
    int m_width, m_height;

public:
    virtual void display()
    {
        cout << m_width << " " << m_height << endl;
    }
};

class RectangleArea : public Rectangle
{

public:
    void readInput()
    {
        cin >> m_width >> m_height;
    }
    void display() override
    {
        cout << m_width * m_height;
    }
};

int main()
{
    RectangleArea r_area;
    r_area.readInput();
    r_area.Rectangle::display();
    r_area.display();
}