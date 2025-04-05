#include<bits/stdc++.h>
using namespace std;
const int N=1000010;
struct Node{
	int t,w;
	bool operator<(const Node &W) const{
	   return w>W.w;
	}
}a[N];
bool st[N],stt[N];
int n,ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) 
	   scanf("%d%d",&a[i].t,&a[i].w);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		bool flag=false;     
		for(int k=a[i].t;k>=1;k--){
			if(stt[k]) break;  //time之前没有可以安排的时刻 
			if(!st[k]){
		    	flag=true;  
		    	st[k]=true;
		    	ans+=a[i].w;
		    	break;
		    }
		} 
		if(!flag) stt[a[i].t]=true;  //a[i].t前都无法安排 
	}
	cout<<ans<<endl;
	return 0;
}