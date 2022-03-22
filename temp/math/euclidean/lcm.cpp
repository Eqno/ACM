#include <iostream>
using namespace std;

int gcd(int a, int b) { return !b ? a : gcd(b, a%b); }
int lcm(int a, int b) { return a / gcd(a, b) * b; }

int main()
{
	int a, b;
	cin >> a >> b;
	cout << lcm(a, b) << endl;
	return 0;
}
