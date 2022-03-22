#include <stack>
#include <vector>
#include <iostream>
using namespace std;

const int MAXN = 1e5 + 10;
vector<int> vertex, bridge;
int from[MAXN], to[MAXN<<1], nxt[MAXN<<1];
int num = 1, tim, dfn[MAXN], low[MAXN], bdg[MAXN<<1];

void addEdge(int u, int v)
{
    to[++ num] = v;
    nxt[num] = from[u];
    from[u] = num;
}

void tarjan(int u, int e)
{
    dfn[u] = low[u] = ++ tim;
    for (int i=from[u]; i; i=nxt[i])
    {
        int v = to[i];
        if (! dfn[v])
        {
            tarjan(v, i);
            low[u] = min(low[u], low[v]);
            printf("%d %d\n", low[v], dfn[u]);
            if (low[v] > dfn[u])
                bdg[i] = bdg[i^1] = 1;
        }
        else if (i != (e^1))
            low[u] = min(low[u], dfn[v]);
    }
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i=1; i<=m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        addEdge(u, v);
        addEdge(v, u);
    }
    puts("");
    for (int i=1; i<=n; i++)
        if (! dfn[i]) tarjan(i, 0);
    for (int i=2; i<num; i+=2)
        if (bdg[i])
        {
            bridge.push_back(i);
            vertex.push_back(to[i]);
            vertex.push_back(to[i^1]);
        }
    puts("vertex: ");
    for (auto i: vertex)
        printf("%d ", i);
    puts("\nbridge: ");
    for (auto i: bridge)
        printf("%d %d\n", to[i], to[i^1]);
    return 0;
}

/*
4 4
0 1
1 2
2 0
1 3
*/