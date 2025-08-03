//T3
//expect pts = 
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;

int n;
string tmp;
char str[maxn];
int wordtick[27];

//单位数字符串特判
bool isdan;
int midword;//中间的字符

signed main()
{
	cin >> tmp;
	n = tmp.length();
	if(n % 2 != 0) isdan = true;
	for(int i = 1 ; i <= n ; i ++)
		str[i] = tmp[i-1];
	
	for(int i = 1 ; i <= n ; i++)
		wordtick[str[i] - 'a'] ++;
		
	if(isdan)
	{
		midword = str[n/2+1]-'a';
		wordtick[midword] --;
	}
		
	/*
	cout << isdan << ' ' << midword << endl;
	for(int i = 0 ; i < 26 ; i ++)
		cout << wordtick[i] << ' ';
	*/
	
	
	queue<int> waitlist;
	for(int i = 0 ; i < 26 ; i++)
		if(wordtick[i] % 2 != 0 )
			waitlist.push(i);
			
	while(waitlist.size())
	{
		
	}
}