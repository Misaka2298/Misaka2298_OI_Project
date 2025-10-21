// F
// expect pts = 100
// expect diff = yellow

#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000;
typedef long long LL;

LL mx[4];
struct Bucket{
	LL have[4];
};

unordered_set<int> ansst;
unordered_set<string> bst;

vector<int> ans;

string get(Bucket u)
{
	string res = "";
	
	res += to_string(u.have[1]); res += '-';
	res += to_string(u.have[2]); res += '-';
	res += to_string(u.have[3]); 
	
	return res;
}

void dfs(Bucket u)
{	
	string us = get(u);
	if(bst.count(us))
		return;
	bst.insert(us);
	
	if(u.have[1] == 0 && !ansst.count(u.have[3]))
	{
		ansst.insert(u.have[3]);
		ans.push_back(u.have[3]);
	}
	
	for(int i = 1 ; i <= 3 ; i ++)
		for(int j = 1 ; j <= 3 ; j ++)// i to j
			if(i != j)
			{	
				int sub = min(u.have[i], mx[j]-u.have[j]);
				u.have[i] -= sub, u.have[j] += sub;
				dfs(u);
				u.have[i] += sub, u.have[j] -= sub;
			}
}

signed main()
{
	freopen("milk.in", "r", stdin);
	freopen("milk.out", "w", stdout);
	Bucket b;
	for(int i = 1 ; i <= 3 ; i ++)
		cin >> mx[i], b.have[i] = 0;
	b.have[3] = mx[3];
	dfs(b);
	
	sort(ans.begin(), ans.end());
	for(int i : ans)
		cout << i << ' ';
	
}