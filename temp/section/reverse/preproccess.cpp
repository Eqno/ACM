#include <iostream>
using namespace std;

const int MAXN = 1e5+10;
int n, q, num[MAXN], lft[MAXN], rgt[MAXN];

int main()
{
    scanf("%d%d", &n, &q);
    for (int i=1; i<=n; i++)
        scanf("%d", &num[i]);
    while (q --)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        lft[l] = ! lft[l];
        rgt[r] = ! rgt[r];
    }
    bool flag = false;
    for (int i=1; i<=n; i++)
    {
        if (lft[i]) flag = ! flag;
        if (flag) num[i] = ! num[i];
        if (rgt[i]) flag = ! flag;
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

1 1 1 1 1 1 1 1
l l r x l r x r

0 0 0 1 1 1 1 1
0 1 1 0 0 0 1 1
0 1 1 0 1 1 0 0

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