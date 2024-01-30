int qmul(int a, int b, int p) {return (a * b - (int)((long double) a / p * b) * p + p) % p;}
void exgcd(int a, int b, int &x, int &y) {if(b == 0) {x = 1, y = 0; return ;} exgcd(b, a % b, y, x); y -= a / b * x;}
int inv(int a, int p) {int x, y; exgcd(a, p, x, y); return (x % p + p) % p;}
int exCRT(vector<int> c, vector<int> m)
{
    int c1 = c[0], m1 = m[0];
    for(int i = 1; i < c.size(); i ++)
    {
        int c2 = c[i], m2 = m[i], d = __gcd(m1, m2);
        if((c2 - c1) % d != 0) return -1;
        c1 = (qmul(qmul(inv(m1 / d, m2 / d), (c2 - c1) / d, m2 / d), m1, m1 / d * m2) + c1) % (m1 / d * m2), m1 = m1 / d * m2;
    }
    return c1;
}