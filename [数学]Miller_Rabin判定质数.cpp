int qmul(int a, int b, int p) {return (a * b - (int)((long double) a / p * b) * p + p) % p;}
int qpow(int a, int b, int p) {int res = 1; while(b) {if(b & 1) res = qmul(res, a, p); a = qmul(a, a, p); b >>= 1;} return res;}
bool miller_rabin(int p)
{
	if(p < 3 || p % 2 == 0) return p == 2;
	int u = p - 1, t = 0;
	while(u % 2 == 0) u /= 2, t ++;
	int used[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
	for(auto a : used)
	{
		if(a >= p) break;
		int v = qpow(a, u, p);
		if(v == 1 || v == p - 1) continue;
		for(int j = 1; j <= t; j ++)
		{
			v = qmul(v, v, p);
			if(v == p - 1 && j != t) {v = 1; break;}
			if(v == 1) return false;
		}
		if(v != 1) return false;
	}
	return true;
}