#include <iostream>
#include <vector>
using namespace std;

class Student
{
private:
    vector<int> scores;
    const int exam_count = 5;

public:
    void input()
    {
        int score;

        for (int i = 0; i < exam_count; i++)
        {
            cin >> score;
            scores.push_back(score);
        }
    }

    int calculateTotalScore()
    {
        int total_score = 0;
        for (int i = 0; i < scores.size(); i++)
        {
            total_score += scores[i];
        }
        return total_score;
    }
};

int main()
{
    int n;
    cin >> n;

    Student *stundents = new Student[n];

    for (int i = 0; i < n; i++)
    {
        stundents[i].input();
    }

    int kristens_score = stundents[0].calculateTotalScore();
    int higher_score_count = 0;

    for (int i = 1; i < n; i++)
    {
        if (stundents[i].calculateTotalScore() > kristens_score)
            higher_score_count++;
    }

    cout << higher_score_count;
}