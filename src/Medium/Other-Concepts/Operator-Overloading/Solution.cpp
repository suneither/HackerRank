// locked by HackerRank
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
// locked by HackerRank

class Matrix
{
public:
    vector<vector<int>> a;
    Matrix operator+(const Matrix& b) const
    {
        Matrix ans;
        for (int i = 0; i < a.size(); i++)
        {
            const vector<int>& aRow = a[i];
            const vector<int>& bRow = b.a[i];

            vector<int> sum;
            sum.reserve(a.size());

            for (int j = 0; j < aRow.size(); j++)
            {
                sum.push_back(aRow.at(j) + bRow.at(j));
            }
            ans.a.push_back(sum);
        }
        return ans;
    }
};

// locked by HackerRank
int main () {
    int cases,k;
    cin >> cases;
    for(k=0;k<cases;k++) {
        Matrix x;
        Matrix y;
        Matrix result;
        int n,m,i,j;
        cin >> n >> m;
        for(i=0;i<n;i++) {
            vector<int> b;
            int num;
            for(j=0;j<m;j++) {
                cin >> num;
                b.push_back(num);
            }
            x.a.push_back(b);
        }
        for(i=0;i<n;i++) {
            vector<int> b;
            int num;
            for(j=0;j<m;j++) {
                cin >> num;
                b.push_back(num);
            }
            y.a.push_back(b);
        }
        result = x+y;
        for(i=0;i<n;i++) {
            for(j=0;j<m;j++) {
                cout << result.a[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
// locked by HackerRank