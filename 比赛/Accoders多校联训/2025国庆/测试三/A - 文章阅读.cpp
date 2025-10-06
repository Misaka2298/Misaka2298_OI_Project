// A
// expect pts = 100
// expect diff = red
// 咋这么水。。。
// 我啥时候才能不被突如其来的声音吓得半死

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+10;
#define endl '\n'

int T;
int n;
string s;

//11011020000000111000000000
//abcdefghijklmnopqrstuvwxyz 
int lower[27] = {1, 1, 0, 1, 1, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0};
//12010000000000111100000000
//ABCDEFGHIJKLMNOPQRSTUVWXYZ
int upper[27] = {1, 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0};

int check(char x)
{
	if(islower(x))
		return lower[x - 'a'];
	else
		return upper[x - 'A'];
}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	freopen("paper.in", "r", stdin);
	freopen("paper.out", "w", stdout);
	cin >> T;
	while(T --)
	{
		int ans = 0;
		cin >> n;
		while(n --)
		{
			cin >> s;
			for(int i = 0 ; i < s.size() ; i ++)
				ans += check(s[i]);
		}
				
		cout << ans << endl;

	}
}