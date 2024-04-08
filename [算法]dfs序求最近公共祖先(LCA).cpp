const int N = /* max_num */;
vector<int> e[N];
int f[N][30], dfn[N], idx;
int get(int u, int v) {return dfn[u] < dfn[v] ? u : v;}
void dfs(int u, int fa)
{
    f[dfn[u] = ++ idx][0] = fa, st[u] = 1;
    for(auto v : e[u]) if(v != fa) dfs(v, u);
}
void init(int n)
{
    for(int i = 1; i <= __lg(n); i ++)
        for(int j = 1; j + (1 << i) - 1 <= n; j ++)
            f[j][i] = get(f[j][i - 1], f[j + (1 << i - 1)][i - 1]);
}
int lca(int u, int v)
{
    if(u == v) return u;
    if((u = dfn[u]) > (v = dfn[v])) swap(u, v);
    int d = __lg(v - u ++);
    return get(f[u][d], f[v - (1 << d) + 1][d]);
}