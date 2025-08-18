/* Enter your macros here */
#define toStr(str) #str
#define io(v) cin >> v
#define FUNCTION(name, op)   \
    void name(int &a, int b) \
    {                        \
        if (b op a)          \
            a = b;           \
    }
#define foreach(v, i) for (int i = 0; i <= v.size() - 1; i++)
#define INF 2147483646

#include <iostream>
#include <vector>
using namespace std;

#if !defined toStr || !defined io || !defined FUNCTION || !defined INF
#error Missing preprocessor definitions
#endif

FUNCTION(minimum, <)
FUNCTION(maximum, >)

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    foreach (v, i)
    {
        io(v)[i];
    }
    int mn = INF;
    int mx = -INF;
    foreach (v, i)
    {
        minimum(mn, v[i]);
        maximum(mx, v[i]);
    }
    int ans = mx - mn;
    cout << toStr(Result =) << ' ' << ans;
    return 0;
}
