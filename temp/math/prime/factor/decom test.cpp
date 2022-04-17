#include "./euclidean.cpp"
#include "./pollardRho.cpp"

int main()
{
	ll n;
	cin >> n;  // n -> the num you want to decomPrimeFactor
	vector <ll> factor;  // to store the prime factors
	decomEuclidean(n, factor);  // decomPrimeFactor
	// decomPollardRho(n, factor);
	for (auto i: factor) cout << i << " ";  // print factor
	cout << endl;
	return 0;
}


