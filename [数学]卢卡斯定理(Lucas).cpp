const int N = /*max num*/;
int fac[N];
void exgcd(int a, int b, int &x, int &y) {if(b == 0) {x = 1, y = 0; return ;} exgcd(b, a % b, y, x); y -= a / b * x;}
int inv(int a, int p) {int x, y; exgcd(a, p, x, y); return (x % p + p) % p;}
int C(int n, int m, int p) {if(m > n) return 0; return fac[n] * inv(fac[m], p) % p * inv(fac[n - m], p) % p;}
void facinit(int p) {fac[0] = 1; for(int i = 1; i < p; i ++) fac[i] = fac[i - 1] * i % p;}
int lucas(int n, int m, int p) {facinit(p); if(!m) return 1; return C(n % p, m % p, p) * lucas(n / p, m / p, p) % p;}