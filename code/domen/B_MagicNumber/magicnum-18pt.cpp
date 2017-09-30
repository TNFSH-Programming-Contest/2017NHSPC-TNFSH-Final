#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
int main()
{
	int n;
	cin>>hex>>n;
	int radix=1;
	for(int i=1;radix<=n;i++)
	{
		radix<<=1;
		vector<int> v;
		int t=n;
		while(t>0)
		{
			v.push_back(t%radix);
			t/=radix;
		}
		bool ok=0;
		for(int j=0;j+2<(int)v.size();j++)
			if(v[j]==1&&v[j+1]==1&&v[j+2]==1)
				ok=1;
		if(ok) cout<<i<<endl;
	}
}