#include <iostream>

using namespace std;

void solveWithArrays();
void solveWithVectors();

int main()
{
    solveWithArrays();
}

void solveWithArrays()
{
    int n, q;
    cin >> n >> q;

    int **sequences = new int *[n];
    int **queries = new int *[q];

    for (int si = 0; si < n; si++)
    {
        int k;
        cin >> k;

        int *sequence = new int[k];

        for (int ki = 0; ki < k; ki++)
        {
            cin >> sequence[ki];
        }

        sequences[si] = sequence;
    }

    for (int qi = 0; qi < q; qi++)
    {
        int *query = new int[2];
        cin >> query[0] >> query[1];
        queries[qi] = query;
    }

    for (int qi = 0; qi < q; qi++)
    {
        cout << sequences[queries[qi][0]][queries[qi][1]] << endl;
    }
}

void solveWithVectors()
{
}