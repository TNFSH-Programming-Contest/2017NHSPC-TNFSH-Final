#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

#define ll long long
#define endl '\n'

struct STNode
{
	int max, min;
	STNode( int x=0 ){ this->max = this->min = x; }
};

STNode operator + ( const STNode& A, const STNode& B)
{
	STNode C;
	C.max = max(A.max, B.max);
	C.min = min(A.min, B.min);
	return C;
}

struct SegTree
{
	int count = 0;
	int width = 0;
	STNode *a;
	
	int leaf(int i){ return width+i; };
	int lch(int i){ return (i<<1); }
	int rch(int i){ return (i<<1)+1; }
	
	int GetMax(){ return a[1].max; }
	
	void Up(int i){
		a[i] = a[lch(i)]+a[rch(i)];
	};
	
	void UpAll()
	{
		for(int i=width-1; i>=1; i--)
			Up(i);
	}
	
	
	void Init(int n)
	{
		width = 1;
		while(width < n)
			width <<= 1;
		count = width*2-1;
		a = new STNode[count+1];
		
		for(int i=1; i<=count; i++)
			a[i] = 0;
	}
	
	void Add(int x, int i)
	{
		i = leaf(i);
		a[i] = a[i].max + x;
		while(i>1)
		{
			i>>=1;
			Up(i);
		}
	}
	
	void _Mod(int i, int L, int R, int l, int r, int v)
	{
		if(L==l && R==r)
		{
			if(a[i].max < v)
				return;
			if(L==R)
			{
				a[i] = a[i].max%v;
				return;
			}
		}
		
		int M = ((L+R)>>1);
		if(r<=M)
			_Mod(lch(i), L,M, l,r, v);
		else if(M<l)
			_Mod(rch(i), M+1,R, l,r, v);
		else
		{
			_Mod(rch(i), L,M, l,M, v);
			_Mod(lch(i), M+1,R, M+1,r, v);
		}
		
		Up(i);
		
		return;
	}
	
	void Mod(int L, int R, int v)
	{
		_Mod(0, 0,width,L,R,v);
	}
};


int main()
{
	SegTree ST;
	
	int n;
	cin >> n;
	
	ST.Init(n);
	
	int a;
	for(int i=0; i<n; i++)
	{
		cin >> a;
		ST.a[ST.leaf(i)] = a;
	}
	
	ST.UpAll();
	
	int m;
	cin >> m;
	while(m--)
	{
		int K;
		cin >> K;
		if(K==1)
		{
			int x,i;
			cin >> x >> i;
			ST.Add(x,i);
		}
		else if(K==2)
		{
			int L,R,v;
			cin >> L >> R >> v;
			ST.Mod(L,R,v);
		}
		else // K==3
		{
			cout << ST.GetMax() << endl;
		}
	}
	
	return 0;
}



