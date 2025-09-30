#include <iostream>
#include <vector>

using namespace std;

void solveWithArrays();
void solveWithVectors();

int main()
{
    solveWithVectors();
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
    int n, q;
    cin >> n >> q;

    vector<vector<int>> sequences;
    vector<vector<int>> queries;

    while (n > 0)
    {
        int k;
        cin >> k;

        vector<int> sequence;
        while (k > 0)
        {
            int element;
            cin >> element;
            sequence.push_back(element);
            k--;
        }
        sequences.push_back(sequence);

        n--;
    }

    while (q > 0)
    {
        int i, j;
        cin >> i >> j;
        vector<int> query;
        query.push_back(i);
        query.push_back(j);
        queries.push_back(query);
        q--;
    }

    for (vector<int> query : queries)
        cout << sequences[query[0]][query[1]] << endl;
}