#include <iostream>
using namespace std;

// ax + by = g, g -> gcd(a, b)
// return g, &x, &y
int exgcd(int a, int &x, int b, int &y)
{
	if (b == 0) { x = 1, y = 0; return a; }
	int g = exgcd(b, y, a%b, x);
	y -= a / b * x;
	return g;
}

int main()
{
	int a, b, x, y;
	cin >> a >> b;
	int g = exgcd(a, x, b, y);  // calculate x, y, g
	printf("%d*%d+%d*%d=%d\n", a, x, b, y, g);
	return 0;
}
