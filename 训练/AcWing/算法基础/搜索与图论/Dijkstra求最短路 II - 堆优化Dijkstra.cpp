//一般来说，堆优化的Dijkstra不用手写堆优化，用优先队列。
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
const int maxn = 1e6+10;
int n , m;
int h[maxn] , e[maxn] , ne[maxn] , w[maxn] ,idx;
int dist[maxn];
bool st[maxn];

void addedge(int a , int b ,int c)
{
	e[idx] = b ,w[idx] = c,ne[idx]=h[a],h[a]=idx++;
}

int dijkstra()
{
	priority_queue<PII,vector<PII>,greater<PII>>heap; //小根
	//1是距离2是编号
	memset(dist,0x3f,sizeof dist);
	dist[1]=0;
	heap.push({0,1});
	
	while(heap.size())
	{
		auto t = heap.top();
		heap.pop();
		int tid = t.second , tdist = t.first;
		
		if(st[tid]) continue;
		st[tid] = true;
		
		for(int i = h[tid] ; i != -1 ; i = ne[i])
		{
			int j = e[i];//e是编号
			if(dist[j] > tdist +w[i])
			{
				dist[j] = tdist +w[i];
				heap.push({dist[j],j});
			}
		}
	}
	
	if(dist[n] == 0x3f3f3f3f) return -1;
	else return dist[n];
}

int main()
{
	cin >> n >> m;
	int a , b , c;
	memset(h,-1,sizeof h);
	for(int i = 0 ; i < m ; i++)
	{
		cin >> a >> b >> c;
		addedge(a,b,c);
	}
	
	cout << dijkstra();
	
	return 0;
}