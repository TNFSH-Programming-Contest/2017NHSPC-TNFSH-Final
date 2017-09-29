#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <cstring>
using namespace std;
int n;
vector<bool> str;
int zero[4000010];
char hexc[]="0123456789abcdef";
int chex[128];
bool check(int j,int step)
{
	if(j+step*2>n) return 0;
	bool a = str[j]&&str[j+step]&&str[j+step*2];
	if(!a) return 0;
	for(int k=j+1;k<j+step;k++)
		if(str[k]) return 0;
	for(int k=j+step+1;k<j+step*2;k++)
		if(str[k]) return 0;
	for(int k=j+step*2+1;k<=n&&k<j+step*3;k++)
		if(str[k]) return 0;
	return 1;
}
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
	n=str.size();
	str.push_back(1);
	reverse(str.begin(),str.end());

	for(int i=1; i<=n; i++)
	{
		for(int j=1;j<=n;j+=i)
		{
			if(check(j,i))
			{
				cout<<i<<endl;
				break;
			}
		}
	}
}
