#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Student
{
private:
    int m_age, m_standart;
    string m_first_name, m_last_name;

public:
    int getAge()
    {
        return m_age;
    }
    void setAge(int age)
    {
        m_age = age;
    }
    int getStandart()
    {
        return m_standart;
    }
    void setStandart(int standart)
    {
        m_standart = standart;
    }
    string getFirstName()
    {
        return m_first_name;
    }
    void setFirstName(string first_name)
    {
        m_first_name = first_name;
    }
    string getLastName()
    {
        return m_last_name;
    }
    void setLastName(string last_name)
    {
        m_last_name = last_name;
    }

    string toString()
    {
        stringstream ss;
        char comma = ',';
        ss << m_age << comma
           << m_first_name << comma
           << m_last_name << comma
           << m_standart;
        return ss.str();
    }
};

int main()
{
    int age, standart;
    string first_name, last_name;

    cin >> age >> first_name >> last_name >> standart;

    Student student;
    student.setAge(age);
    student.setFirstName(first_name);
    student.setLastName(last_name);
    student.setStandart(standart);

    cout << student.getAge() << endl;
    cout << student.getLastName() << ", " << student.getFirstName() << endl;
    cout << student.getStandart() << endl;

    cout << endl
         << student.toString();
}