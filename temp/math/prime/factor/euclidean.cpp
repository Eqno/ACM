#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

// construction -> O(n), decomposition -> O(logn)

#define ll long long
const int MAXN = 1e5+10;
const int SIEVERANGE = 1e5;
ll minp[MAXN];  // minp -> mininum prime factor
bool flag[MAXN];

// sieve mininum prime factor
void minPrimeSieve(ll n)
{
	vector <ll> prime;
	for (ll i=2; i<=n; i++)
	{
		if (! flag[i])
		{
			minp[i] = i;  // minp = i when i is a prime
			prime.push_back(i);
		}
		for (auto j: prime)
		{
			if (i*j > n) break;
			minp[i*j] = j;  // minp = j when setting flag as true 
			flag[i*j] = true;
			if (i%j == 0) break;
		}
	}
}

// decom prime factor
void decomEuclidean(ll n, vector<ll> &factor) {
	minPrimeSieve(SIEVERANGE);  // generate minp
	while (n > 1) {
		factor.push_back(minp[n]);  // take down minp
		n /= minp[n];  // euclidean algorithm
	}
	return ;
}
