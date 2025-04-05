//T1AC
#include<bits/stdc++.h>
using namespace std;
const int maxn=1000010;
int d[maxn], s[maxn], t[maxn], a[maxn];
int n, m, R[maxn], l, r;
bool check(int x){
    memset(a,0,sizeof(0));//差分数组 
    for(int i=1;i<=x;i++){
        a[s[i]]+=d[i];
        a[t[i]+1]-=d[i];    
    }
    for(int i=1;i<=n;i++)
	    a[i]+=a[i-1];
    for(int i=1;i<=n;i++)
	    if(a[i]>R[i])return false;//无法满足 
    return true;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
	    scanf("%d",&R[i]);
    for(int i=1;i<=m;i++)
	    scanf("%d%d%d",&d[i],&s[i],&t[i]);
    if(check(m)){
    	puts("0");
    	return 0;
    }
    l=0,r=m;  //可能一个订单都无法满足 
    while(l<r){
        int mid=l+r+1>>1;
        if(check(mid)) l=mid;
        else r=mid-1;
    }
    cout<<-1<<endl<<l+1;
    return 0; 
}