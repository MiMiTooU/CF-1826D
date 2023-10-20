#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	int t;
	cin >> t;
	if (t >= 1 && t <= 1e5)
	{
		for (int i = 0; i < t; i++)
		{
			int n = 0;
			bool chk = 0;
			cin >> n;
			if (n >= 3 && n <= 1e5)
			{
				map<int, __int64> b;
				map<int, __int64>l, r;
				__int64 ans=0;
				for (int i = 1; i < n + 1; i++)
				{
					__int64 input;
					cin >> input;
					if (input >= 1 && input <= 1e8)
					{
						chk = 0;
						b[i] = input;
					}
					else
					{
						chk = 1;
						break;
					}
				}
				if (chk)
				{
					break;
				}
				for (int p = 1; p < n + 1; p++)
				{
					l.insert(make_pair(p, (b[p] + p)));
				}
				for (int q = n; q > 0; q--)
				{
					r.insert(make_pair(q, (b[q] - q)));
				}
				for (int i = 2; i < n; ++i) 
				{
					l[i] = max(l[i], l[i - 1]);
				}
				for (int i = n - 1; i >= 0; --i) 
				{
					r[i] = max(r[i], r[i + 1]);
				}
				auto it_l = l.begin(), it_r = r.end();it_r--;
				for (int i = 2; i < n; i++)
				{
					ans = max(ans, l[i - 1] + r[i + 1] + b[i]);
				}
				cout << ans << endl;
 				l.clear(); r.clear(); 
				b.clear();
			}
		}
	}
	return 0;
}