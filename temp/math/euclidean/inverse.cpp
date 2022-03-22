#include <iostream>
using namespace std;

int exgcd(int a, int &x, int b, int &y)  // exgcd
{
	if (b == 0) { x = 1, y = 0; return a; }
	int g = exgcd(b, y, a%b, x);
	y -= a / b * x;
	return g;
}

// inverse: when mod p -> "b / a" can translate to "b * inverse(a)"

// ax = 1(mod n)
// return x, notexist -> -1
int inverse(int a, int p)
{
	int x, y;
	int g = exgcd(a, x, p, y);
	return g==1 ? (x%p+p)%p : -1;
}

// can only be used when a<p and coprime(a, p)
int briefInverse(int a, int p)
{ return a==1 ? 1 : briefInverse(p%a, p)*(p-p/a)%p; }

int main()
{
	int a, p;
	cin >> a >> p;
	int x = briefInverse(a, p);  // calculate inverse
	printf("%d*%d=1(mod %d)\n", a, x, p);
	return 0;
}

