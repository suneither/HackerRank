#include <iostream>
using namespace std;

struct Student
{
    int age;
    string first_name;
    string last_name;
    int standart;
};

int main()
{
    Student student;
    cin >> student.age;
    cin >> student.first_name;
    cin >> student.last_name;
    cin >> student.standart;

    cout << student.age << " "
         << student.first_name << " "
         << student.last_name << " "
         << student.standart;
}