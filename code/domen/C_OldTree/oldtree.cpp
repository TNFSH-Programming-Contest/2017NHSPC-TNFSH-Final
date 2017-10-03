#include <iostream>
#include <cstring>
#include <vector>
#include <cassert>
#include <algorithm>
#include <stack>
using namespace std;
const int MAXV = 100001;
int n;
int vit[MAXV];
vector<int> g[MAXV];
vector<pair<int,int>> es; // for checking connectivity

int dfn[MAXV]={};
int sz[MAXV];
int dfs(int i)
{
	dfn[i]=1;
	sz[i]=vit[i];
	for(int j:g[i])
		if(!dfn[j])
			sz[i]+=dfs(j);
	return sz[i];
}
pair<int,int> ans;
int sum=0;
int tarjan(int i,int p,int d)
{
	int low=dfn[i]=d;
	int csz=vit[i];
	bool ap=false;
	for(int j:g[i])
	{
		if(j==p) continue;
		if(dfn[j]==-1)
		{
			int t=tarjan(j,i,d+1);
			if(t>=d)
			{
				ap=true;
				csz+=sz[j];
			}
			low=min(low,t);
		}
		else
			low=min(low,dfn[j]);
	}
	if(ap&&i!=0)
	{
		ans=min(ans,{sum-csz,i});
	}
	return low;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int m;
	cin>>n>>m;
	assert(n<=100000 && m<=(long long)n*(n+1)/2 && m<=1000000 && n>=1 && m>=n);
	for(int i=1;i<=n;i++)
	{
		cin>>vit[i];
		assert(vit[i]<=10000);
	}
	while(m--)
	{
		int a,b;
		cin>>a>>b;
		assert(a>=0 && b>=0 && a<=n && b<=n && a!=b);
		g[a].push_back(b);
		g[b].push_back(a);
		if(a>b)swap(a,b);
		es.push_back({a,b});
	}

	sort(es.begin(), es.end());
	for(int i=1;i<(int)es.size();i++)
		assert(es[i]!=es[i-1]);

	for(int i=1;i<=n;i++)
		sum+=vit[i];
	ans={sum,0};
	for(int i=1;i<=n;i++)
		ans=min(ans,make_pair(sum-vit[i],i));

	dfs(0);
	memset(dfn,-1,sizeof dfn);
	tarjan(0,-1,0);
	for(int i=1;i<=n;i++)
		assert(dfn[i]!=-1);

	cout<<ans.second<<endl;
}