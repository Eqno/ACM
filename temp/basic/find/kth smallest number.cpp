#include <vector>
#include <iostream>
using namespace std;

int find(vector<int> &num, int k, int l, int r)
{
    int i = l, j = r, base = num[l];
    if (l > r) return -1;
	while (i != j)
	{
		while (i<j && num[j]>=base) j --;
		while (i<j && num[i]<=base) i ++;
		if (i < j) swap(num[i], num[j]);
    }
	num[l] = num[i], num[i] = base;
    if (i == k - 1) return num[i];
    if (i > k) return find(num, k, l, i-1);
    return find(num, k, i+1, r);
}

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    vector<int> num(n);
    for (int i=0; i<n; i++)
        scanf("%d", &num[i]);
    int ans = find(num, k, 0, n-1);
    printf("%d\n", ans);
    return 0;
}

/*
10 4
3 1 6 7 2 8 9 10 4 5
*/