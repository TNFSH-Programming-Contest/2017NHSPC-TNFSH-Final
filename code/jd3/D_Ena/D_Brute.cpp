#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;
const double PI = acos(-1.0);

double toDeg(double t){ return t*180.0/PI; };

struct Vec2
{
	LL x,y;
	
	Vec2(){ x=y=0; };
	Vec2(LL _x, LL _y){ x=_x; y=_y; };
};

inline Vec2 operator + (const Vec2 &A, const Vec2 &B){ return Vec2(A.x+B.x, A.y+B.y); }
inline Vec2 operator - (const Vec2 &A, const Vec2 &B){ return Vec2(A.x-B.x, A.y-B.y); }
inline LL operator * (const Vec2 &A, const Vec2 &B){ return A.x*B.x + A.y*B.y; }
inline LL operator ^ (const Vec2 &A, const Vec2 &B){ return A.x*B.y - A.y*B.x; }

double Angle(const Vec2& A, const Vec2& B, const Vec2& C) {
	Vec2 v1 = B-A;
	Vec2 v2 = C-B;
	return toDeg( atan2((double)v2.y, (double)v2.x) - atan2((double)v1.y, (double)v1.x) );
}



int n;
double D;
LL h[10003];
int v[10003][10003];
vector<int> in[10003];
bool blocked[10003][10003];

inline Vec2 P(int i){ return Vec2(i,h[i]); };


void CalculateBlocking()
{
	memset(blocked,false,sizeof(blocked));
	for(int i=0; i<n; i++)
	{
		int high = i+1;
		for(int j=i+1; j<n; j++)
		{
			if( ((P(high)-P(i)) ^ (P(j)-P(i))) < 0 )
				blocked[i][j] = blocked[j][i] = true;
			else
				high = j;
		}
	}
}


int DFS(int i, int j)
{ 
	if(j==(n-1))
		return 2;
	
	int ans = -1;
	for(int k=j+1; k<n; k++)
	{
		if(blocked[j][k])
			continue;
		if( abs(Angle(P(i),P(j),P(k))) <= D )
		{
			int res = DFS(j,k);
			if(res!=(-1))
				ans = max(ans,res+1);
		}
	}
	
	return ans;
}

int main()
{
	cin >> n >> D;
	
	for(int i=0; i<n; i++)
		cin >> h[i];
	
	CalculateBlocking();
	
	int ans = (-1);
	for(int i=1; i<n; i++)
	{
		if(!blocked[0][i])
			ans = max(ans,DFS(0,i));
	}
	cout << ans << endl;
	
	return 0;
}



