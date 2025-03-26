//T2
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000010;//1e6+10;

//pair<int,char> s[maxn];//first为最大差值，second为相对位置(l,r)
long long n, atk[maxn], cost;
int idx; 

struct S{
	long long div, spos, pos;//最大差值，差值相对位置，当前绝对位置
}s[maxn];

void init()
{
	if(atk[1]-atk[2] >= 0)
		s[idx++] = {atk[1]-atk[2] , 2, 1};
	if(atk[n]-atk[n-1] >= 0)
		s[idx++] = {atk[n]-atk[n-1] , n-1, n};
	
	for(int i = 2 ; i < n ; i++)
	{
		if(atk[i] - atk[i-1] > atk[i] - atk[i+1] && atk[i] - atk[i+1] >= 0)
			s[idx++] = {atk[i] - atk[i+1], i+1, i};
		else if(atk[i] - atk[i-1] >= 0)
			s[idx++] = {atk[i] - atk[i-1], i-1, i};
	}
}

bool iloveccfhhhhh(S a, S b)
{
	return a.div < b.div;
}

signed main()
{
	cin >> n;
	for(int i = 1 ; i <= n ; i++)
		cin >> atk[i];
		
	init();
	sort(s, s+idx, iloveccfhhhhh);
	
	/*
	for(int i = 0 ; i < idx ; i++)
		cout << s[i].div << ' ' << s[i].spos << ' ' << s[i].pos << endl;
	*/
	
	for(int i = 0 ; i < n ; i ++)
	{
		int sp = s[i].spos, p = s[i].pos;
		cost += atk[p];
		//atk[sp] = atk[p];
	}
	
	cout << cost;
}
/*
怎么1e6+10.

不管了，贪心！
虽然我证不出来，但是出题人一定能证出来的。

114514怎么过不去？
*/