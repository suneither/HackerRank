#include <iostream>
#include <string>

using namespace std;

class Person
{
protected:
    int m_cur_id;
    string m_name;
    int m_age;

public:
    virtual void getData() = 0;
    virtual void putData() = 0;
};

class Professor : public Person
{
private:
    int m_publications;
    static int id_tracker;

public:
    Professor()
    {
        m_cur_id = ++id_tracker;
    }
    void getData() override
    {
        cin >> m_name;
        cin >> m_age;
        cin >> m_publications;
    }
    void putData() override
    {
        cout << m_name << " "
             << m_age << " "
             << m_publications << " "
             << m_cur_id << endl;
    }
};

int Professor::id_tracker = 0;

class Student : public Person
{
private:
    int m_marks[6];
    static int id_tracker;

private:
    int sumOfMarks()
    {
        int sum = 0;
        for (int i = 0; i < 6; i++)
            sum += m_marks[i];
        return sum;
    }

public:
    Student()
    {
        m_cur_id = ++id_tracker;
    }
    void getData() override
    {
        cin >> m_name;
        cin >> m_age;
        for (int i = 0; i < 6; i++)
        {
            int mark;
            cin >> mark;
            m_marks[i] = mark;
        }
    }
    void putData() override
    {
        cout << m_name << " "
             << m_age << " "
             << sumOfMarks() << " "
             << m_cur_id << endl;
    }
};

int Student::id_tracker = 0;

// Locked code part bu HackerRank
int main()
{

    int n, val;
    cin >> n; // The number of objects that is going to be created.
    Person *per[n];

    for (int i = 0; i < n; i++)
    {

        cin >> val;
        if (val == 1)
        {
            // If val is 1 current object is of type Professor
            per[i] = new Professor;
        }
        else
            per[i] = new Student; // Else the current object is of type Student

        per[i]->getData(); // Get the data from the user.
    }

    for (int i = 0; i < n; i++)
        per[i]->putData(); // Print the required output for each object.

    return 0;
}
// Locked code part bu HackerRank
