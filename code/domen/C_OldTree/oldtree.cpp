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

int dfn[MAXV], did=0;
bool ap[MAXV]={};
int tarjan(int i,int p,int d)
{
	int low=dfn[i]=d;
	for(int j:g[i])
	{
		if(j==p) continue;
		if(dfn[j]==-1)
		{
			int t=tarjan(j,i,d+1);
			if(t>=d) ap[i]=1;
			low=min(low,t);
		}
		else
			low=min(low,dfn[j]);
	}
	return low;
}
bool u[MAXV];
pair<int,int> ans;
int sum=0;
int dfs(int i)
{
	u[i]=true;
	int sz=vit[i];
	for(int j:g[i])
		if(!u[j])
			sz+=dfs(j);
	if(ap[i])
		ans=min(ans, {sum-sz, i});
	return sz;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int m;
	cin>>n>>m;
	assert(n<=100000 && m<=n*(n+1)/2 && m<=1000000 && n>=1 && m>0);
	for(int i=1;i<=n;i++)
	{
		cin>>vit[i];
		assert(vit[i]<=10000);
	}
	while(m--)
	{
		int a,b;
		cin>>a>>b;
		assert(a>=0 && b>=0 && a<=n && b<=n);
		g[a].push_back(b);
		g[b].push_back(a);
		if(a>b)swap(a,b);
		es.push_back({a,b});
	}

	// check connectivity
	sort(es.begin(), es.end());
	for(int i=1;i<(int)es.size();i++)
		assert(es[i]!=es[i-1]);

	memset(dfn,-1,sizeof dfn);
	tarjan(1,-1,0);
	ap[0]=0;

	for(int i=1;i<=n;i++)
		sum+=vit[i];
	ans={sum,0};
	for(int i=1;i<=n;i++)
		ans=min(ans,make_pair(sum-vit[i],i));
	memset(u,0,sizeof u);
	dfs(0);
	cout<<ans.second<<endl;
}