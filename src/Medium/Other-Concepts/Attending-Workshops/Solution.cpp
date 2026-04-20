// hackerrank locked code
#include<bits/stdc++.h>

using namespace std;

// hackerrank locked code

struct Workshop
{
    int start_time{};
    int duration{};
    int end_time{};
    Workshop()= default;
    Workshop(const int start_time, const int duration):
    start_time(start_time), duration(duration), end_time(start_time + duration){}

    bool operator<(const Workshop& b) const
    {
        return end_time < b.end_time && start_time < b.start_time;
    }
};

struct Available_Workshops
{
    int n;
    vector<Workshop> workshops;
    Available_Workshops(const int n): n(n) {}

};

Available_Workshops* initialize (int start_time[], int duration[], int n)
{
    Available_Workshops* available_workshops = new Available_Workshops(n);
    for (int i = 0; i < n; i++)
    {
        Workshop workshop(start_time[i],duration[i]);
        available_workshops->workshops.push_back(workshop);
    }
    return available_workshops;
}

int CalculateMaxWorkshops(Available_Workshops* ptr)
{
    int result = 0;
    sort(ptr->workshops.begin(), ptr->workshops.end());
    for (int i = 0; i < ptr->n - 1; i++)
    {
        if (ptr->workshops[i].end_time <= ptr->workshops[i+1].end_time)
        {
            result++;
        }
    }
    return result;
}

//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops

// hackerrank locked code
int main(int argc, char *argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}

// hackerrank locked code