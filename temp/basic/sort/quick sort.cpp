#include <vector>
#include <iostream>
using namespace std;

void sort(vector<int> &num, int l, int r)
{
    int i = l, j = r, base = num[l];
    if (l > r) return;
	while (i != j)
	{
		while (i<j && num[j]>=base) j --;
		while (i<j && num[i]<=base) i ++;
		if (i < j) swap(num[i], num[j]);
    }
	num[l] = num[i], num[i] = base;
	sort(num, l, i-1);
	sort(num, i+1, r);
}

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> num(n);
    for (int i=0; i<n; i++)
        scanf("%d", &num[i]);
    sort(num, 0, n-1);
    for (int i=0; i<n; i++)
        printf("%d ", num[i]);
    return 0;
}

/*
10
3 1 6 7 2 8 9 10 4 5
*/