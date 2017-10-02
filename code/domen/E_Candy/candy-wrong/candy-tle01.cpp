#include <iostream>
#include <cassert>
#include <set>
using namespace std;
int a[200000];
multiset<int> st;
int main()
{
	int n;
	cin>>n;
	assert(n<=200000 && n>0);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		assert(a[i]<=100000000 && a[i]>=1);
		st.insert(a[i]);
	}

	int m;
	cin>>m;
	assert(m>0 && m<=100000);
	while(m--)
	{
		int k;
		cin>>k;
		if(k==1)
		{
			int x,i;
			cin>>x>>i;
			assert(i<n&&i>=0 && x>=1&&x<=10000);
			st.erase(st.find(a[i]));
			a[i]+=x;
			st.insert(a[i]);
		}
		else if(k==2)
		{
			int l,r,v;
			cin>>l>>r>>v;
			assert(l>=0&&r>=0&&l<n&&r<n&&v>0&&v<=1000000);
			for(int i=l;i<=r;i++)
				if(a[i]>=v)
				{
					st.erase(st.find(a[i]));
					a[i]%=v;
					st.insert(a[i]);
				}
		}
		else if(k==3)
		{
			cout<<*(--st.end())<<endl;
		}
		else assert(0);
	}
}