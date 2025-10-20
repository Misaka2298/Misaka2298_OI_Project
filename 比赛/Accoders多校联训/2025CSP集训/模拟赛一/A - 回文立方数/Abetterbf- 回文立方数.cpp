// A better bf
// expect pts = 
// expect diff = 

/*
一个LL的数字放进LL的vector里面数字竟然会不一样，闻所未闻。
然后int就不会这样，神秘。。。

哦我写错了，不要看这个
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

//-static-libstdc++
LL n;
vector<LL> ans;

unordered_set<string> mp;

void check(string str)
{
	if(str[0] == '0')
		return;
	LL x = 0;
	for(int i = 0 ; i < str.size() ; i ++)//这么转其实是倒着的，但是毕竟都回文了所以无所谓。
	{
		char chr[] = {str[i]};
		LL num = atoi(chr);
		x += (long long)pow(10, i+1) * num;
	}
	x /= 10;
	//cout << x << endl;
	long long c = x;// 必须要这样做？？？？？？？
	ans.push_back(c);
}

signed main()
{
	freopen("huiwen.out", "w", stdout);
	cin >> n;
	ans.clear();
	
	for(int len = 7 ; len <= n ; len ++)
	{
		string strnum = "0";
		for(int i = 1 ; i < len ; i ++)
			strnum += "0";
			
		for(int pos = 0 ; pos < len ; pos ++)
			for(int cgnum = 0 ; cgnum <= 9 ; cgnum ++)
			{
				strnum.replace(pos, 1, to_string(cgnum));
				strnum.replace(len-pos-1, 1, to_string(cgnum));
				
				if(!mp.count(strnum))
					check(strnum);
				mp.insert(strnum);
					
				for(int inpos = 0 ; inpos < pos ; inpos ++)
					for(int cnum = 0 ; cnum <= 9 ; cnum ++)
					{
						strnum.replace(inpos, 1, to_string(cnum));
						strnum.replace(len-inpos-1, 1, to_string(cnum));
						if(!mp.count(strnum))
							check(strnum);
						mp.insert(strnum);
					}
				
			}
	}
	
	//cout << endl << endl;
	sort(ans.begin(), ans.end());
	for(LL res : ans)
		cout << res << endl;
	
	
	
	
	
}