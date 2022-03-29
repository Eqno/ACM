#include <iostream>
using namespace std;

#define ll long long
const int MAXN = 5e5+10;
ll n, q, num[MAXN];
struct Node { ll l, r, rev; } tree[MAXN<<2];

ll read()
{
    ll x = 0, f = 1, c = getchar();
    while (! isdigit(c)) { if (c == '-') f = -1; c = getchar(); }
    while (isdigit(c)) { x = x*10 + c-'0'; c = getchar(); }
    return x * f;
}

void build(ll i, ll l, ll r)
{
    tree[i].l = l, tree[i].r = r;
    if (l == r) { tree[i].rev = 0; return; }

    ll m = (l + r) >> 1;
    build(i<<1, l, m), build(i<<1|1, m+1, r);
    tree[i].rev = tree[i<<1].rev & tree[i<<1|1].rev;
}

void push(ll i)
{
    if (tree[i].rev) tree[i<<1].rev = ! tree[i<<1].rev;
    if (tree[i].rev) tree[i<<1|1].rev = ! tree[i<<1|1].rev;
    tree[i].rev = 0;
}

void rev(ll i, ll l, ll r)
{
    if (l <= tree[i].l && tree[i].r <= r)
    {
        tree[i].rev = ! tree[i].rev;
        return;
    }
    push(i);
    if (l <= tree[i<<1].r) rev(i<<1, l, r);
    if (tree[i<<1|1].l <= r) rev(i<<1|1, l, r);
    tree[i].rev = tree[i<<1].rev & tree[i<<1|1].rev;
}

bool query(ll i, ll l, ll r)
{
    if (l <= tree[i].l && tree[i].r <= r)
        return tree[i].rev;
    push(i);
    ll sum = 0;
    if (l <= tree[i<<1].r) sum |= query(i<<1, l, r);
    if (tree[i<<1|1].l <= r) sum |= query(i<<1|1, l, r);
    return sum;
}

int main()
{
    n = read(), q = read();
    for (int i=1; i<=n; i++)
        num[i] = read();
    build(1, 1, n);
    while (q --)
    {
        int l = read(), r = read();
        rev(1, l, r);
    }
    for (int i=1; i<=n; i++)
        printf("%d ", ! query(1, i, i));
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