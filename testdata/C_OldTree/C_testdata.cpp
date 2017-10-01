#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "../testlib.h"
using namespace std;

int tests[] = {0, 33, 33, 34};
int data[] = {0, 10000, 1000, 10000};

//#define ISTREE

struct Edge {
	int a,b;
};

bool g[10003][10003];
vector<Edge> e;

void AddEdge(int a, int b)
{
	g[a][b] = g[b][a] = true;
	e.push_back({a,b});
}

/* Disjoint Set */
static int pre[10011];
int Find(int a)
{
	if(pre[a]==a)
		return a;
	return pre[a] = Find(pre[a]);
}
void Union(int a, int b)
{
	pre[Find(a)] = Find(b);
}
	
void MakeTree (int n)
{
	for(int i=0; i<n; i++)
		pre[i] = i;
	
	int edge_cnt=0;
	while(edge_cnt < n-1)
	{
		int a = rnd.next(0, n);
		int b = rnd.next(0, n);
		
		//cout << "a=" << a << ", find(a)=" << Find(a) << endl;
		//cout << "b=" << b << ", find(b)=" << Find(b) << endl;
		if(Find(a) != Find(b))
		{
			AddEdge(a,b);
			Union(a,b);
			edge_cnt++;
		}
	}
}

int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);
	int l;
	for(int q=1; q<=3; q++) {
		for(int w=1; w<=tests[q]; w++) {
			stringstream ss;
			ss<<"data/"<<setfill('0')<<setw(2)<<q<<setw(2)<<w<<".in";
			cout<<ss.str()<<endl;
			fstream f;
			f.open(ss.str().c_str(), ios::binary|ios::out);

			memset(g,0,sizeof(g));
			e.clear();

			int n = rnd.next(1, data[q]);
			int m = rnd.next(n, max(n, min(n*5, n*(n+1)/2)));
			
			cout<<n<<" "<<m<<endl;
			
			MakeTree(n+1);
			
			if(q==1) {
				m = n;
			} else {
				for(int i=n; i<m; )
				{
					int a = rnd.next(0, n+1);
					int b = rnd.next(0, n+1);
					if( g[a][b] )
					{
						AddEdge(a,b);
						i++;
					}
				}
				m = min(m,(n+1)*n/2);
			}
			
			f << n << " " << m << endl;
			l = rnd.next(0, 10000);
			f << l;
			for(int i=1; i<n; i++) {
				l = rnd.next(0, 10000);
				f << " " << l;
			}
			f << endl;
			for(size_t i=0; i<e.size(); i++)
				f << e[i].a << " " << e[i].b << endl;
			
			f.close();
		}
	}
	
	return 0;
}



