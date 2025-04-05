/*
谁寻思出来的这题这么难写。。。
哪看出来是哈希了？
我咋瞅着像DP呢。。。
时间还够，好好寻思寻思。
哎呦T3T4太简单了大家肯定都一眼出，我得把这题做出来啊
旁边红衣小孩的键盘声音怪好听的，等会去问问什么轴。
那个壁纸是列宁的哥们怎么还不写题？

考虑反对称串的性质
010101，00001111
能看出来啥呢...
哦双指针？不行这样包TLE的啊，时限就给了1sec

看看阳历吧。
11001011 7
至少得想出来一个O(nlogn)的做法
难不成我真得枚举一遍arr的所有子串？会超时的吧？会的吧！
光遍历就O(nlogn)了...哦好像还真行？(upd:遍历好像不止nlogn)
行吧，现在我们得到了一个子串，需要在O(1)的复杂度下求出他是不是反对称
还好题目提示了是hash题，往hash想想。
不管了先把想出来的思路打完。

反对称串一个比较明显的性质是arr[i] != arr[n-i+1]
哎好消息是剪枝蛮好剪的，上面的性质不成立就能直接continue
但是容易被出题人卡数据，题目没说数据随机就算了吧。
实际上每次朴素判定是否为反对称的时候都重复遍历了好几次...
或许优化思路就在这里？不管了先把朴素的打出来。
唉我去朴素都打不出来，写T6去了。

唉我去有部分分啊！
红红火火恍恍惚惚哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈
有部分分还怕什么，管他正解是什么，搜！

哎我，我刚才咋没想到按宽度搜遍历子串啊，这多好写啊
暴力写完了，嘻嘻

ok，暴力没问题，考虑优化
算了，写暴力就已经耗干我的脑细胞了，这场就这样吧。
T5不爆零我就已经心满意足了。

算算复杂度吧。
算了算不过来，不算了。

*/
#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5+10;

int n;
int arr[maxn];

signed main()
{
	cin.tie(0);
	cin >> n;
	string str;
	cin >> str;
	//cout << str << endl;
	for(int i = 0 ; i < n ; i++)
	{
		if(str[i] == '0') arr[i+1] = 0;
		else arr[i+1] = 1;
	}
	
		
	int ans = 0;

	for(int i = 2 ; i <= n ; i+=2)//宽度
	{
		for(int j = 1 ; j+i-1 <= n ; j++)//左端点
		{
			bool flag = true;
			for(int k = 0 ; k < i/2 ; k++)
			{
				if(arr[j+k] == arr[j+i-1-k])
				{
					flag = false;
					break;
				}
			}
			if(flag) ans++;
		}
	}
	cout << ans;
	return 0;
}

/*
	for(int i = n ; i >= 2 ; i--)
		for(int j = 1 ; j <= i ; j ++)//到这里是O(nlogn)
		{
			bool flag = true;//是否反对称
			for(int k = 1 ; k <= j/2 ; k++)
			{
				
				if(arr[k] == arr[j-k+1]) 
				{
					flag = false;
					break;
				}
				
			}
			if(flag) ans++;
		}
*/