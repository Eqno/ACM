#include <iostream>
#include <algorithm>
using namespace std;

// O(pow(n, 1./4)) -> random algorithm -> can judge 2^63

#define ll long long
const int RANDTIME = 10;  // random time while 8～10 is enough

// calculate res = (a*b)%c -> a,b,c < 2^63
ll mulMod(ll a, ll b, ll c)
{
	a %= c, b %= c;
	ll res = 0, tmp = a;
	while (b)
	{
		if (b & 1)
		{
			res += tmp;
			if (res > c) res -= c;  // % is much slower
		}
		tmp <<= 1;
		if (tmp > c) tmp -= c;
		b >>= 1;
	}
	return res;
}

// calculate res = (a^b)%c
ll powMod(ll a, ll b, ll c)
{
	ll res = 1, tmp = a % c;
	while (b)
	{
		if (b & 1) res = mulMod(res, tmp, c);
		tmp = mulMod(tmp, tmp, c);
		b >>= 1;
	}
	return res;
}

// judge whether n is prime -> a^(n-1) = 1(mod n)
// judge again -> n-1 = x*(2^t)
// return true if n is composite false if n dosen't have to be composite
bool check(ll a, ll n, ll x, ll t)
{
	ll res = powMod(a, x, n), last = res;
	for (int i=1; i<=t; i++)
	{
		res = mulMod(res, res, n);
		if (res==1 && last!=1 && last!=n-1) return true;  // composite
		last = res;
	}
	if (res != 1) return true;
	return false;
}

// millerRabin: prime -> true (may be pseudoprime), not prime -> false
bool millerRabin(ll n)
{
	if (n < 2) return false;
	if (n == 2) return true;
	if ((n&1) == 0) return false;
	ll x = n-1, t = 0;
	while ((x&1) == 0) x >>= 1, t ++;

	srand(time(NULL));  // important !

	for (int i=1; i<=RANDTIME; i++)
	{
		ll a = rand()%(n-1)+1;
		if (check(a, n, x, t)) return false;
	}
	return true;
}
