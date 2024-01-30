unordered_map<int, int> mp;
int BSGS(int a, int b, int p)
{
    mp.clear();
    int t = ceil(sqrt(p)), val = 1;
    for(int i = 0; i < t; i ++) mp[b * val % p] = i, val = val * a % p;
    if(!(a = val)) return b == 0 ? 1 : -1;
    for(int i = 1, val = 1; i <= t; i ++)
    {
        val = a * val % p;
        int j = mp.count(val) ? mp[val] : -1;
        if(j >= 0 && i * t - j >= 0) return i * t - j;
    }
    return -1;
}