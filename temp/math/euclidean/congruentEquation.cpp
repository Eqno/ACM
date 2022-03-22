#include <iostream>
#include <vector>
using namespace std;

int exgcd(int a, int &x, int b, int &y)  // exgcd
{
	if (b == 0) { x = 1, y = 0; return a; }
	int g = exgcd(b, y, a%b, x);
	y -= a / b * x;
	return g;
}

// x = 2(mod 3)
// x = 3(mod 5)
// x = 2(mod 7)
// x = ???
bool solve(int &r0, int &p0, int r, int p)
{
	int x, y, g = exgcd(p0, x, p, y);
	if (abs(r-r0) % g) return false;
	x *= (r-r0) / g;
	r0 += (x%=p/g) * p0;
	r0 %= (p0*=p/g);
	if (r0 < 0) r0 += p0;
	return true;
}
pair <int, int> MLES(vector <int> &r, vector <int> &p)
{
	int r0 = 0, p0 = 1;
	for (int i=0; i<r.size(); i++)
		if (! solve(r0, p0, r[i], p[i]))
			return make_pair(-1, -1);  // no solution
	return make_pair(r0, p0);
}

int main()
{
	vector <int> r, p;   // x = r(mod p) -> get x
	int n;
	cin >> n;
	for (int i=1; i<=n; i++)
	{
		int a, b;
		cin >> a >> b;
		r.push_back(a);
		p.push_back(b);
	}
	auto pa = MLES(r, p);
	int r0 = pa.first, p0 = pa.second;  // fi -> r0, se -> p0
	if (r0 == -1 && p0 == -1)
		cout << "no solution" << endl;
	else printf("x = %d + %d*k\n", r0, p0);
	// The general solution has the following form:
	// x = r0 + p0 * k  (k = 1,2,3...)
}
