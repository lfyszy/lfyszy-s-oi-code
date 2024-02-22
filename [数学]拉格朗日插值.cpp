void exgcd(int a, int b, int &x, int &y) {if(b == 0) {x = 1, y = 0; return ;} exgcd(b, a % b, y, x); y -= a / b * x;}
int inv(int a, int p) {int x, y; exgcd(a, p, x, y); return (x % p + p) % p;}
int gety(int x[], int y[], int n, int k, int mod)
{
    int res = 0;
    for(int i = 1; i <= n; i ++)
    {
        int a = 1, b = 1;
        for(int j = 1; j <= n; j ++) if(i != j)
            a = a * (((k - x[j]) % mod + mod) % mod) % mod,
            b = b * (((x[i] - x[j]) % mod + mod) % mod) % mod;
        res = (res + y[i] * a % mod * inv(b, mod) % mod) % mod;
    }
    return res;
}