// A
// expect pts = 100

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+20, emp = 1e6+5;
typedef long long LL;
#define endl '\n'

int n;
struct Node{
	int a, b, sub;
}nodes[maxn];
bool ans[maxn];
vector<int> aset, bset;

/*
bool acmp(int a, int b)
{
	if(nodes[a].a != nodes[b].a)
		return nodes[a].a > nodes[b].a;
	return nodes[a].b < nodes[b].b;
}

bool bcmp(int a, int b)
{
	if(nodes[a].b != nodes[b].b)
		return nodes[a].b > nodes[b].b;
	return nodes[a].a < nodes[b].a;
}
*/

bool subcmp(int a, int b)
{
	return nodes[a].sub < nodes[b].sub;
}

bool inccmp(int a, int b)
{
	return a < b;
	//return nodes[a].id < nodes[b].id;
}

/*
void debug(int opt)
{
	vector<int> a, b;
	a = aset, b = bset;
	if(opt == 1)
	{
		sort(a.begin(), a.end(), inccmp);
		sort(b.begin(), b.end(), inccmp);
	}
	for(auto i : a)
		cout << i << ' ';
	cout << endl;
	for(auto i : b)
		cout << i << ' ';
	cout << endl;
}
*/

int pre_selecter(int u)
{
	int a = nodes[u].a, b = nodes[u].b;
	if(a == b) // 1-switch-1-up
	{
		if(aset.size() < bset.size())
			return 1;
		else
			return 2;
	}
	else// 1-switch-1-down
	{
		if(a > b)// 1-switch-2-up
			return 2;
		else// 1-switch-2-down
			return 1;
	}
}


void init()
{
	nodes[emp] = {0, 0, 0};
	cin >> n;
	n *= 2;
	for(int i = 1 ; i <= n ; i ++)
		cin >> nodes[i].a;
	for(int i = 1 ; i <= n ; i ++)
		cin >> nodes[i].b;
	for(int i = 1 ; i <= n ; i ++)
		nodes[i].sub = abs(nodes[i].a - nodes[i].b);
}

void pre_select()
{
	for(int i = 1 ; i <= n ; i ++)
	{
		int goal = pre_selecter(i);
		if(goal == 1)
			aset.push_back(i);
		else
			bset.push_back(i);
	}
	sort(aset.begin(), aset.end(), subcmp);
	sort(bset.begin(), bset.end(), subcmp);
}

void outans()
{
	LL res = 0;
	for(int i : aset)
	{
		int u = i;
		ans[u] = 0;
		res += nodes[u].a;
	}
	for(int i : bset)
	{
		int u = i;
		ans[u] = 1;
		res += nodes[u].b;
	}
	cout << res << endl;
	for(int i = 1 ; i <= n ; i ++)
		cout << ans[i] << ' ';
	cout << endl;
}

void a_overflow()
{
	int len = aset.size() - (n/2);
	for(int i = 0 ; i < len ; i ++)
	{
		int u = aset[i];
		aset[i] = emp;
		bset.push_back(u);
	}
	outans();
}

void b_overflow()
{
	int len = bset.size() - (n/2);
	for(int i = 0 ; i < len ; i ++)
	{
		int u = bset[i];
		bset[i] = emp;
		aset.push_back(u);
	}
	outans();
}

void solve()
{
	pre_select();
	
	//debug(0);
	
	
	if(aset.size() == bset.size() && aset.size() == (n / 2))
		outans();
	else if(aset.size() > bset.size())
		a_overflow();
	else if(aset.size() < bset.size())
		b_overflow();
	//debug(1);
	// 其实我觉得这两个 overflow 函数可以写成一个的，但是我懒得改了。
}

void fileio()
{
	freopen("stairs.in", "r", stdin);
	freopen("stairs.out", "w", stdout);
}

void fstio()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
}

signed main()
{
	//double begin = clock();
	//fileio();
	fstio();
	init();
	
	solve();
	//double end = clock();
	//cout << endl << "use:" << (end - begin) << "ms";
	//debug();
}