#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
using namespace std;

#define int long long

struct HashPair
{ 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const
    { 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
};

struct Node { int x, y; }; vector <Node> p;
unordered_map <pair <int, int>, unordered_map <pair<int, int>, int, HashPair>, HashPair> m;
int gcd(int a, int b) { return !b ? abs(a) : gcd(b, a%b); }

signed main()
{
    // freopen("a.txt", "r", stdin);
    // freopen("b.txt", "w", stdout);
    cin.sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    for (int i=0; i<n; i++)
    {
        int x, y;
        cin >> x >> y;
        p.push_back((Node) {x, y});
    }
    for (int i=0; i<n; i++)
        for (int j=i+1; j<n; j++)
        {
            int dx = p[j].x-p[i].x, dy = p[j].y-p[i].y;
            int g = gcd(dx, dy); dx /= g, dy /= g;
            m[make_pair(p[i].x, p[i].y)][make_pair(dx, dy)] ++;
            m[make_pair(p[j].x, p[j].y)][make_pair(dx, dy)] ++;
        }
    while (q --)
    {
        int x, y, ans = 0, res = 0;
        cin >> x >> y;
        unordered_map <pair <int, int>, unordered_map <pair<int, int>, int, HashPair>, HashPair> t;
        for (int i=0; i<n; i++)
        {
            int dx = p[i].x-x, dy = p[i].y-y;
            int g = gcd(dx, dy); dx /= g, dy /= g;
            ans += m[make_pair(x, y)][make_pair(-dy, dx)]
                + m[make_pair(x, y)][make_pair(dy, -dx)]
                + m[make_pair(p[i].x, p[i].y)][make_pair(-dy, dx)]
                + m[make_pair(p[i].x, p[i].y)][make_pair(dy, -dx)];
            t[make_pair(x, y)][make_pair(dx, dy)] ++;
            t[make_pair(p[i].x, p[i].y)][make_pair(dx, dy)] ++;
        }
        for (int i=0; i<n; i++)
        {
            int dx = p[i].x-x, dy = p[i].y-y;
            int g = gcd(dx, dy); dx /= g, dy /= g;
            res += t[make_pair(x, y)][make_pair(-dy, dx)]
                + t[make_pair(x, y)][make_pair(dy, -dx)]
                + t[make_pair(p[i].x, p[i].y)][make_pair(dy, -dx)]
                + t[make_pair(p[i].x, p[i].y)][make_pair(-dy, dx)];
        }
        cout << ans + res/2 << endl;
    }
    return 0;
}