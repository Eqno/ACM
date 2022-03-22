#include <stack>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 5e5+10;  // O(nlogn) and stable

long long inv = 0;
// inversion -> how many operations does it take to swap sort
int num[MAXN], res[MAXN];
// num -> the original array, res -> store ori-array temporarily

void merge(int l, int mid, int r)  // merge
{
	int i = l, j = mid+1, k = 0;
	while (i<=mid && j<=r)  // always take the lower number.
	{
		if (num[i] <= num[j]) res[k++] = num[i++];
		else res[k++] = num[j++], inv += mid-i+1;  // inversion
	}
	while (j <= r) res[k++] = num[j++];  // take the rest 
	while (i <= mid) res[k++] = num[i++];
	for (k=0; k<r-l+1; k++) num[l+k] = res[k];
	// rebuild ori-array with tmp-array
}

void mergeSort(int l, int r)  // divide
{
	if (l >= r) return;  // couldn't be divided any more
	int mid = (l+r)>>1;  // find the mid coord
	mergeSort(l, mid);  // recurve to sort left-sub and right-sub
	mergeSort(mid+1, r);
	merge(l, mid, r);  // merge the sorted subs
}

void mergeSortEx(int L, int R)
{
	#define pii pair <int, int>
	queue <pii> q;
	stack <pii> s;
	q.push({L, R});
	s.push({L, R});
	while (q.size())
	{
		const pii &p = q.front(); q.pop();
		int l = p.first, r = p.second;
		if (l >= r) continue;
		int mid = (l+r) >> 1;
		q.push({l, mid});
		q.push({mid+1, r});
		s.push({l, mid});
		s.push({mid+1, r});
	}
	int lastdel = 1;
	while (s.size())
	{
		const pii &p = s.top(); s.pop();
		int l = p.first, r = p.second;
		int del = r - l;
		if (del > lastdel)
		{
			for (int i=L; i<=R; i++)
				printf("%d ", num[i]);
			putchar('\n');
			lastdel = del;
		}
		int mid = (l+r) >> 1;
		merge(l, mid, r);
	}
	#undef pii
}

int main()
{
	int n;
	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> num[i];  // read the ori-array in
	mergeSortEx(1, n);  // mergeSort(begin, end);
	cout << num[1];
	for (int i=2; i<=n; i++)  // print the sorted array
		cout << " " << num[i];  // array in order
	cout << endl << inv << endl;  // print the inversion
	return 0;
}
/*
6
5 6 3 4 2 1

10
62 33 84 12 61 90 17 97 75 53

10
10 9 8 7 6 5 4 3 2 1
*/