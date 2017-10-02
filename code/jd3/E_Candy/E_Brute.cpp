#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

#define ll long long
#define endl '\n'


int a[200011];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	for(int i=0; i<n; i++)
		cin >> a[i];
	
	int m;
	cin >> m;
	while(m--)
	{
		int cmd;
		cin >> cmd;
		if(cmd==1)
		{
			int x,i;
			cin >> x >> i;
			a[i] += x;
		}
		else if(cmd==2)
		{
			int L, R, v;
			cin >> L >> R >> v;
			for(int i=L; i<=R; i++)
				a[i] %= v;
		}
		else
		{
			int max_a = 0;
			for(int i=0; i<n; i++)
				max_a = max(max_a, a[i]);
			cout << max_a << endl;
		}
	}
	
	
	
	return 0;
}



