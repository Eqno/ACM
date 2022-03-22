#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAXN = 1e5+10;  // O(n) and stable
bool flag[MAXN];  // true -> not prime

void primeSieve(int n, vector <int> &prime)
{
	for (int i=2; i<=n; i++)  // check from 2 to n
	{
		if (! flag[i]) prime.push_back(i);  // is prime
		for (auto j: prime)  // for all primes
		{
			if (i*j > n) break;  // stop if over n
			flag[i*j] = true;  // set primes' mul to true
			if (i%j == 0) break;  // keep stable
		}
	}
}

int main()
{
	int n;
	cin >> n;  // the range
	vector <int> prime;  // sieve primes to this vector
	primeSieve(n, prime);  // sieve the primes
	for (auto i: prime)  // print the primes
		cout << i << " ";
	cout << endl;
	return 0;
}
