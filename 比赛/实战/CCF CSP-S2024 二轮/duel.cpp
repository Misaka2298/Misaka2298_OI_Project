//love ljy forever.
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;

long long ans;
int n;
//vector<int> arr[maxn];
int arr[maxn];//所有怪兽的攻防
bool isdie[maxn]={false};//记录怪兽死亡情况
bool isuse[maxn]={false};
bool isspecial=true; //r小于等于2吗
long long cnt1,cnt2;

/*
bool check(int a ,int b)
{
    return b<a;
}
*/

int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%d",&arr[i]);
        if(arr[i] == 1 )cnt1++;
        if(arr[i] == 2 )cnt2++;
        if(arr[i]!= 1 && arr[i]!= 2) isspecial=false;
    }

    if(isspecial)
    {
        if(cnt1>cnt2) cout << cnt1;
        else if(cnt1 == cnt2)cout << cnt1;
        else if(cnt1 < cnt2) cout << cnt2;
        return 0;
    }
    sort(arr,arr+n);
    int lastdie = 0 ,lastuse = 0;
    for(int m = 0 ; m<n ; m++)
    {
        int i = lastdie , j = lastuse;
        while(isdie[i]) i++;
        while(arr[i] >= arr[j] || isdie[j] || isuse[j])
        {
            j++;
            if(j>n)break;
        }
        if(arr[i] < arr[j])
        {
            isdie[i] = true;
            lastdie = i;
            isuse[j] = true;
            lastuse = j;
        }
    }
    for(int i = 0 ; i < n ;i++) if(!isdie[i]) ans++;
    cout <<ans;

    return 0;
}
/*
freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i++) scanf("%d",&arr[i]);
    //string usei,usej;
    sort(arr,arr+n);
    for(int m = 0 ; m<n ; m++)
    {
        int i = 0 , j = 0;
        while(isdie[i]) i++;
        while(arr[i] >= arr[j] || isdie[j] || isuse[j])
        {
            j++;
            if(j>n)break;
        }
        if(arr[i] < arr[j] && !isdie[i] && !isdie[j] && !isuse[j] && j!=n && i!=n)
        {
            isdie[i] = true;
            //usei+=to_string(i);
            isuse[j] = true;
            //usej+=to_string(j);
        }
    }
    for(int i = 0 ; i < n ;i++) if(!isdie[i]) ans++;
    cout <<ans;
    return 0;
*/
