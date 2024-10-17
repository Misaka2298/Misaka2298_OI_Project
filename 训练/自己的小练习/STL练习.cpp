/*

vector动态数组
queue队列
deque双端队列
stack栈
pair对
string字符串
priority_queue优先队列(大根)
priority_queue<int,vector<int>,greater<int>>a;(小根)

set/multiset
集合
set元素唯一，multiset可不唯一

map/multimap
图，存储pair，first映射second，可以用来做离散化？
可以像数组一样用map，e.g.
map<string,int>a;
a["yxc"]=1;
cout << a["yxc"];
结果为1
当然，multimap不能这么干。
那multimap还有什么用呢？


*/

#include <bits/stdc++.h>
using namespace std;


int main()
{
	multiset<int>a;
	for(int i = 0 ; i < 10 ;i ++) a.insert(i);
	
	for(int i = 1 ; i <= 3 ;i++) a.insert(5);
	
	cout << a.count(5);
}