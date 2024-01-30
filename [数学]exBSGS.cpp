unordered_map<int, int> mp;
void exgcd(int a, int b, int &x, int &y) {if(b == 0) {x = 1, y = 0; return ;} exgcd(b, a % b, y, x); y -= a / b * x;}
int inv(int a, int p) {int x, y; exgcd(a, p, x, y); return (x % p + p) % p;}
int BSGS(int a, int b, int p)
{
    mp.clear();
    int t = ceil(sqrt(p)), val = 1;
    for(int i = 0; i < t; i ++)
        mp[b * val % p] = i, val = val * a % p;
    if(!(a = val)) return b == 0 ? 1 : -1;
    for(int i = 1, val = 1; i <= t; i ++)
    {
        val = a * val % p;
        int j = mp.count(val) ? mp[val] : -1;
        if(j >= 0 && i * t - j >= 0) return i * t - j;
    }
    return -1;
}
int exBSGS(int a, int b, int p)
{
    a %= p, b %= p;
    if(b == 1 || p == 1) return 0;
    int g = __gcd(a, p), na = 1, cnt = 0;
    while(g > 1)
    {
        if(b % g != 0) return -1;
        b /= g, p /= g, na = na * (a / g) % p, cnt ++;
        if(na == b) return cnt;
        g = __gcd(a, p);
    }
    int ans = BSGS(a, b * inv(na, p) % p, p);
    return ans == -1 ? -1 : ans + cnt;
}