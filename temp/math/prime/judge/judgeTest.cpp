#include "./judgePrime.cpp"
#include "./millerRabin.cpp"

int main()
{
	ll n;
	cin >> n;
	if (judgePrime(n)) cout << "yes" << endl;
	// if (millerRabin(n)) cout << "yes" << endl;
	else cout << "no" << endl;
	return 0;
}

