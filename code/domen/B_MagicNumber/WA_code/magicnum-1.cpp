#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <cstring>
using namespace std;
vector<bool> str;
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
	int n=str.size();
	str.push_back(1);
	reverse(str.begin(),str.end());

	zero[0]=0;
	for(int i=1;i<=n;i++)
		zero[i] = str[i]?0:zero[i-1]+1;
	/*for(int i=1;i<=n;i++)
		cout<<zero[i];
	cout<<endl;
	for(int i=0;i<=n;i++)
		cout<<str[i];
	cout<<endl;*/
	for(int i=1; i<=n; i++)
	{
		int cnt=0;
		bool succ=0;
		for(int j=i;j-i+1<=n;j+=i)
		{
			if(str[j-i+1] && zero[j]>=i-1) cnt++;
			else cnt=0;
			if(cnt>=3)
			{
				succ=1;
				break;
			}
		}
		if(succ) cout<<i<<endl;
	}
}
