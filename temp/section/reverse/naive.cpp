#include <iostream>
using namespace std;

const int MAXN = 1e5+10;
int n, q, num[MAXN];

int main()
{
    scanf("%d%d", &n, &q);
    for (int i=1; i<=n; i++)
        scanf("%d", &num[i]);
    while (q --)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        for (int i=l; i<=r; i++)
            num[i] = ! num[i];
    }
    for (int i=1; i<=n; i++)
        printf("%d ", num[i]);
    return 0;
}

/*
8 3
1 1 1 1 1 1 1 1
1 3
2 6 
5 8

8 6
1 1 1 1 1 1 1 1
1 3
1 2
2 3
4 4
4 8
6 8

8 3
1 1 1 1 1 1 1 1
1 3
5 8
2 6
*/