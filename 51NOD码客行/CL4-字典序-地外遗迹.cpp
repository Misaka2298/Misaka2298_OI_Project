#include <bits/stdc++.h>
using namespace std;
bool cmp(string dict,string word1,string word2)
{
	if(word1==word2) return false; //相等特判
	//cout << word1<<endl<<word2<<endl; //debug line
	//uvwxyzabcdefghijklmnopqrst
	long long aposi=0,bposi=0,minleng=0; //不开longlong一场空
	if(word1.size()<word2.size()) minleng=word1.size();
	else minleng=word2.size();
	for(int i=0;i<=minleng;i++){//遍历词语中每一个字符
		for(int j=0;j<=25;j++){//遍历字典
			if(word1[i]==int(dict[j])) aposi=j;//word1[i]在字典中的位置，下同
			if(word2[i]==int(dict[j])) bposi=j;
			}
			if (aposi<bposi) {//同下，检测字符大小
				//cout <<i<<" "<< aposi << " " <<bposi<<endl; //debug line
				return true;
			}
			else if(aposi>bposi) {
				//cout <<i<<" "<< aposi << " " <<bposi<<endl; //debug line
				return false;
		}
	}
	//cout << word1 << " " << word2<<endl;//debug line
	if(word1.size()>word2.size()) return false;//如果上面的for没有return,说明所有字符都相等，判断字符串长度
	else return true;
	return false;
}
int main()
{
	string dict,word1,word2;
	getline(cin,dict);
	long long num;
	cin >> num;
	for(long long i=0;i<num;i++) {
		//getline(cin,word1);
		//getline(cin,word2);
		cin>>word1;
		cin>>word2;
		if(cmp(dict,word1,word2)) cout << "green" << endl;
		else cout << "red" << endl;
	}
	return 0;
}