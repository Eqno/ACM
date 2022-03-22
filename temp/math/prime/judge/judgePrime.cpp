#include <iostream>
#include <cmath>
using namespace std;

// O(nsqrt(n))

bool judgePrime(int n)
{
	if (n < 2) return false;
	int sq = sqrt(n);
	for (int i=2; i<=sq; i++)
		if (n % i == 0) return false;
	return true;
}
