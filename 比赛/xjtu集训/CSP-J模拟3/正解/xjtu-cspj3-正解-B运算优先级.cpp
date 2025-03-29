#include<bits/stdc++.h>
using namespace std;

int n;
string a;
int k = 1,l = 1;

int main(){
	cin>>n>>a;
	a = ' ' + a;
	for(int i = 1;i <= n;i++){
		if(a[i] == '*' || a[i] == '/') l++;
	}
	for(int i = 1;i <= n;i++){
		cout<<a[i];
		if(a[i] == '*' || a[i] == '/'){
			cout<<'['<<k<<']';
			k++;
		}else if(a[i] == '+' || a[i] == '-'){
			cout<<'['<<l<<']';
			l++;
		}
	}
}