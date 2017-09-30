#include <iostream>
#include <cassert>
using namespace std;
int a[200000];
int mx=0;
int main()
{
	int n;
	cin>>n;
	assert(n<=200000 && n>0);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		assert(a[i]<=100'000'000 && a[i]>=1);
		mx=max(mx,a[i]);
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
			a[i]+=x;
			mx=max(mx,a[i]);
		}
		else if(k==2)
		{
			int l,r,v;cin>>l>>r>>v;
		}
		else if(k==3)
		{
			cout<<mx<<endl;
		}
		else assert(0);
	}
}