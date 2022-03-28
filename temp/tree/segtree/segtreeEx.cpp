#include <cstring>
#include <iostream>
using namespace std;

#define ll long long
const int MAXN = 5e5+10;
ll n, q, p, num[MAXN];
struct Node { ll l, r, sum, mul, add; } tree[MAXN<<2];

ll read()
{
    ll x = 0, f = 1, c = getchar();
    while (! isdigit(c)) { if (c == '-') f = -1; c = getchar(); }
    while (isdigit(c)) { x = x*10 + c-'0'; c = getchar(); }
    return x * f;
}

void build(ll i, ll l, ll r)
{
    tree[i].l = l, tree[i].r = r, tree[i].mul = 1;
    if (l == r) { tree[i].sum = num[l] % p; return; }

    ll m = (l + r) >> 1;
    build(i<<1, l, m), build(i<<1|1, m+1, r);
    tree[i].sum = (tree[i<<1].sum + tree[i<<1|1].sum) % p;
}

void push(ll i)
{
    ll j = tree[i].mul, k = tree[i].add;
    tree[i].mul = 1, tree[i].add = 0;

    tree[i<<1].sum = (j*tree[i<<1].sum + k*(tree[i<<1].r-tree[i<<1].l+1)) % p;
    tree[i<<1|1].sum = (j*tree[i<<1|1].sum + k*(tree[i<<1|1].r-tree[i<<1|1].l+1)) % p;
    
    tree[i<<1].mul = (j * tree[i<<1].mul) % p;
    tree[i<<1|1].mul = (j * tree[i<<1|1].mul) % p;

    tree[i<<1].add = (j * tree[i<<1].add + k) % p;
    tree[i<<1|1].add = (j * tree[i<<1|1].add + k) % p;
}

void mul(ll i, ll l, ll r, ll t)
{
    if (l <= tree[i].l && tree[i].r <= r)
    {
        tree[i].sum = (t * tree[i].sum) % p;
        tree[i].mul = (t * tree[i].mul) % p;
        tree[i].add = (t * tree[i].add) % p;
        return;
    }
    push(i);
    if (l <= tree[i<<1].r) mul(i<<1, l, r, t);
    if (tree[i<<1|1].l <= r) mul(i<<1|1, l, r, t);
    tree[i].sum = (tree[i<<1].sum + tree[i<<1|1].sum) % p;
}

void add(ll i, ll l, ll r, ll t)
{
    if (l <= tree[i].l && tree[i].r <= r)
    {
        tree[i].sum += (t * (tree[i].r-tree[i].l+1)) % p;
        tree[i].add = (t + tree[i].add) % p;
        return;
    }
    push(i);
    if (l <= tree[i<<1].r) add(i<<1, l, r, t);
    if (tree[i<<1|1].l <= r) add(i<<1|1, l, r, t);
    tree[i].sum = (tree[i<<1].sum + tree[i<<1|1].sum) % p;
}

ll query(ll i, ll l, ll r)
{
    if (l <= tree[i].l && tree[i].r <= r)
        return tree[i].sum;
    push(i);
    ll sum = 0;
    if (l <= tree[i<<1].r) sum += query(i<<1, l, r);
    if (tree[i<<1|1].l <= r) sum += query(i<<1|1, l, r);
    return sum % p;
}

int main()
{
    n = read(), q = read(), p = read();
    for (int i=1; i<=n; i++) num[i] = read();
    build(1, 1, n);
    while (q --)
    {
        ll c = read();
        if (c == 1)
        {
            ll l = read(), r = read(), t = read();
            mul(1, l, r, t%p);
        }
        if (c == 2)
        {
            ll l = read(), r = read(), t = read();
            add(1, l, r, t%p);
        }
        if (c == 3)
        {
            ll l = read(), r = read();
            printf("%lld\n", query(1, l, r));
        }
    }
    return 0;
}
/*
5 5
1 5 4 2 3
2 1 3
*/ 