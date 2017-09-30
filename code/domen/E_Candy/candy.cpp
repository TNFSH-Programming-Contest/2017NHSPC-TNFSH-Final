#include <iostream>
#include <cassert>
using namespace std;
int a[200000];
int seg[800000];
void build(int L,int R,int idx)
{
	if(L==R) seg[idx]=a[L];
	else
	{
		int mid=(L+R)/2;
		build(L,mid,idx*2);
		build(mid+1,R,idx*2+1);
		seg[idx]=max(seg[idx*2],seg[idx*2+1]);
	}
}
void add(int i,int x,int L,int R,int idx)
{
	if(L==R) seg[idx]+=x;
	else
	{
		int mid=(L+R)/2;
		if(i<=mid) add(i,x,L,mid,idx*2);
		else add(i,x,mid+1,R,idx*2+1);
		seg[idx]=max(seg[idx*2],seg[idx*2+1]);
	}
}
void mod(int l,int r,int x,int L,int R,int idx)
{
	if(seg[idx]<x) return;
	if(L==R) seg[idx]%=x;
	else
	{
		int mid=(L+R)/2;
		if(r<=mid) mod(l,r,x,L,mid,idx*2);
		else if(l>mid) mod(l,r,x,mid+1,R,idx*2+1);
		else mod(l,mid,x,L,mid,idx*2), mod(mid+1,r,x,mid+1,R,idx*2+1);
		seg[idx]=max(seg[idx*2],seg[idx*2+1]);
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin>>n;
	assert(n<=200000 && n>0);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		assert(a[i]<=100'000'000 && a[i]>=1);
	}
	build(0,n-1,1);

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
			add(i,x,0,n-1,1);
		}
		else if(k==2)
		{
			int l,r,v;
			cin>>l>>r>>v;
			assert(l>=0&&r>=0&&l<n&&r<n&&v>0&&v<=1'000'000);
			mod(l,r,v,0,n-1,1);
		}
		else if(k==3)
		{
			cout<<seg[1]<<endl;
		}
		else assert(0);
	}
}