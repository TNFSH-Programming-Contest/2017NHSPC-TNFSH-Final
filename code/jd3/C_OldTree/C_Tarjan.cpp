#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

#define ll long long
#define endl '\n'


int w[100011];
vector<int> g[100011];

int dfn[100011];
int low[100011];
int sum[100011];

int next_dfn()
{
	static int _next_dfn = 0;
	return _next_dfn++;
}

void DFS(int i, int father)
{
	low[i] = dfn[i] = next_dfn();
	for(int k=0; k<g[i].size(); k++)
	{
		int j = g[i][k];
		
		if(j==father)
			continue;
		
		if(dfn[j]==(-1))
		{
			DFS(j,i);
			low[i] = min( low[i], low[j] );
			sum[i] += w[j];
		}
		else
			low[i] = min(low[i], dfn[j]);
	}
	sum[i] += w[i];
}

void Tarjan(int n, int st)
{
	memset(dfn,-1,sizeof(dfn));
	dfn[0] = next_dfn();
	DFS(st,st);
}

int main()
{
	int n,m;
	cin >>n >> m;
	for(int i=1; i<=n; i++)
		cin >> w[i];
	
	int a,b;
	for(int i=0; i<m; i++)
	{
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	
	Tarjan(n+1,0);
	
	int max_sum = 0;
	int max_id = 0;
	for(int i=1; i<=n; i++)
	{
		if(low[i] >= dfn[i])
		{
			if(sum[i]>max_sum)
			{
				max_sum = sum[i];
				max_id = i;
			}
		}
		else if(w[i]>max_sum)
		{
			max_sum = w[i];
			max_id = i;
		}
	}
	
	cout << max_id << endl;	
	
	return 0;
}



