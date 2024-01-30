int qmul(int a, int b, int p) {return (a * b - (int)((long double) a / p * b) * p + p) % p;}
int qpow(int a, int b, int p) {int res = 1; while(b) {if(b & 1) res = qmul(res, a, p); a = qmul(a, a, p); b >>= 1;} return res;}
struct prime {int val, cnt;};
vector<prime> dip;
void divide(int n)
{
    dip.clear();
    for(int i = 2;i <= n / i; i ++)
        if(n % i == 0)
        {
            int s = 0;
            while(n % i == 0)
                n /= i, s ++;
            dip.push_back({i, s});
        }
    if(n > 1) dip.push_back({n, 1});
}
void exgcd(int a, int b, int &x, int &y) {if(b == 0) {x = 1, y = 0; return ;} exgcd(b, a % b, y, x); y -= a / b * x;}
int inv(int a, int p) {int x, y; exgcd(a, p, x, y); return (x % p + p) % p;}
int exCRT(vector<int> c, vector<int> mod)
{
    int c1 = c[0], m1 = mod[0];
    for(int i = 1; i < c.size(); i ++)
    {
        int c2 = c[i], m2 = mod[i], d = __gcd(m1, m2);
        if((c2 - c1) % d != 0) return -1;
        c1 = (qmul(qmul(inv(m1 / d, m2 / d), (c2 - c1) / d, m2 / d), m1, m1 / d * m2) + c1) % (m1 / d * m2), m1 = m1 / d * m2;
    }
    return c1;
}
int fac(int n, int p, int pa)
{
    if(n == 0) return 1;
    int c = 1, r = 1;
    for(int i = 1; i <= pa; i ++) if(i % p) c = qmul(c, i, pa);
    for(int i = pa * (n / pa); i <= n; i ++) if(i % p) r = qmul(i, r, pa);
    return fac(n / p, p, pa) * qpow(c, n / pa, pa) % pa * r % pa;
}
int cntfac(int n, int p) {return n >= p ? cntfac(n / p, p) + n / p : 0;}
int C(int n, int m, int p, int pa)
{
    int f1 = fac(n, p, pa), f2 = fac(m, p, pa), f3 = fac(n - m, p, pa);
    int px = qpow(p, cntfac(n, p) - cntfac(m, p) - cntfac(n - m, p), pa);
    return f1 * inv(f2, pa) % pa * inv(f3, pa) % pa * px % pa;
}
int exlucas(int n, int m, int p)
{
    divide(p); vector<int> c, mod;
    for(int i = 0; i < dip.size(); i ++)
        mod.push_back(qpow(dip[i].val, dip[i].cnt, 1e9)),
        c.push_back(C(n, m, dip[i].val, mod[i]));
    return exCRT(c, mod);
}