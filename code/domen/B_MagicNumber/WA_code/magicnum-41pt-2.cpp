#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <cstring>
using namespace std;
int n;
vector<bool> str,tmp;
int zero[4000010];
char hexc[]="0123456789abcdef";
int chex[128];
int main()
{
	string s;
	cin>>s;
	assert(s.size()<=1000000 && s.size()>0);
	assert(s[0]!='0');
	memset(chex,-1,sizeof chex);
	for(int i=0;i<16;i++)
		chex[hexc[i]]=i;
	for(char c:s)
	{
		int t=chex[c];
		assert(t>=0);
		str.push_back((t>>3)&1);
		str.push_back((t>>2)&1);
		str.push_back((t>>1)&1);
		str.push_back((t>>0)&1);
	}
	reverse(str.begin(),str.end());

	for(int i=1; ; i++)
	{
		bool ok=0;
		for(int j=2;j<str.size();j++)
			if(str[j-2]&&str[j-1]&&str[j])
				{ok=1; break;}
		if(ok) cout<<i<<endl;

		tmp.clear();
		if(str.size()%2!=0) str.push_back(0);
		for(int i=0;i<(int)str.size();i+=2)
			tmp.push_back(str[i]&&!str[i+1]);
		tmp.swap(str);
		if(str.size()==1) break;
	}
}
