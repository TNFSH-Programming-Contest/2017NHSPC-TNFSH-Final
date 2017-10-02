#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

#define ll long long
#define endl '\n'

int w[100001];
vector<int> g[100001];
bool vist[100001];
int DFS(int i)
{
	vist[i] = true;
	int ans = w[i];
	for(int j=0; j<g[i].size(); j++)
	{
		int nxt = g[i][j];
		if(!vist[nxt])
			ans += DFS(nxt);
	}
	
	return ans;
}

int main()
{
	int n,m;
	cin >> n >>m;
	for(int i=1; i<=n; i++)
		cin >> w[i];
	
	int a,b;
	for(int i=0; i<m; i++)
	{
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	
	int min_sum = 2147483647;
	int min_id = 0;
	for(int i=1; i<=n; i++)
	{
		memset(vist,false,sizeof(vist));
		vist[i] = true;
		int sum = DFS(0);
		
		if(sum<min_sum)
		{
			min_sum = sum;
			min_id = i;
		}
	}
	
	cout << min_id <<endl;
	
	return 0;
}



