#include <iostream>
#include <algorithm>
#include <vector>
#include "../judge/millerRabin.cpp"
using namespace std;

#define ll long long
const int FINDTIME = 107;

// absgcd
ll gcd(ll a, ll b) { return !b ? (a<0?-a:a) : gcd(b, a%b); }

// find a factor
ll pollardRho(ll x, ll c)
{
	ll i = 1, k = 2;
	srand(time(NULL));
	ll t = rand()%(x-1)+1, y = t;
	while (i ++)
	{
		t = (mulMod(t, t, x)+c)%x;
		ll g = gcd(y-t, x);
		if (g!=1 && g!=x) return g;
		if (y == t) return x;
		if (i == k) y = t, k <<= 1;
	}
	return -1;
}

// decomposition -> set FINDTIME to 107 or so
void decomPollardRho(ll n, vector <ll> &factor)
{
	if (n == 1) return ;
	if (millerRabin(n))
	{
		factor.push_back(n);
		return ;
	}
	ll p = n, c = FINDTIME;
	// make sure c changing to prevent an endless loop
	while (p >= n) p = pollardRho(p, c--);
	decomPollardRho(p, factor);
	decomPollardRho(n/p, factor);
}
