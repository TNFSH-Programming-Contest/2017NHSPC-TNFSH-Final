#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <deque>
#include <iomanip>

using namespace std;

typedef long long LL;
const double PI = acos(-1.0);

double toDeg(double t){ return t*180.0/PI; };

struct Vec2
{
	LL x,y;
	
	LL mag()const{ return sqrt(x*x+y*y); };
	
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
	return
		toDeg(
			abs( atan2((double)v1.y, (double)v1.x) - atan2((double)v2.y, (double)v2.x) )
		);
}


int n;
double D;
int h[10003];
int v[10003][10003];
vector<int> in[10003];
bool blocked[10003][10003];

inline Vec2 P(int i){ return Vec2(i,h[i]); };


void CalculateBlocking()
{
	for(int i=0; i<n; i++)
	{
		int high = i+1;
		for(int j=i+1; j<n; j++)
			blocked[i][j] = blocked[j][i] = ( ((P(high)-P(i)) ^ (P(j)-P(i))) < 0 );
	}
}

void sol_DP(int n)
{ 
	// |  |  |
	// k  i  j
	
	// v[0][i] = 2 ,   (not blocked)
	// v[0][i] = -1 ,  (blocked)
	// v[i][j] = max{ v[k][i] | deg(k,i,j)<=D }
	
	CalculateBlocking();
	
	memset(v,-1,sizeof(v));
	
	for(int i=1; i<n; i++)
		v[0][i] = blocked[0][i] ? (-1) : 2;
	
	for(int i=1; i<n; i++)
	{
	//	cout << "i = " << i <<endl;
		int kr=0;
		deque<int> k_que;
		for(int j=i+1; j<n; j++)
		{
		//	cout << "  j = " << j <<endl;
			if( blocked[i][j] )
				continue;
			
		//	cout << "   front angle : ";
			while( !k_que.empty() && Angle( P(k_que.front()), P(i), P(j)) > D )
			{
//				cout << Angle( P(k_que.front()), P(i), P(j)) << " ";
				k_que.pop_front();
			}
			/*
			if(k_que.size())
				cout << Angle( P(k_que.front()), P(i), P(j));
			cout << endl;
			//	*/
			
			while( kr<i )
			{
			//	cout << "   k = " << kr << ", angle = " << Angle(P(kr), P(i), P(j)) << endl;
				if( blocked[kr][i] )
				{
					kr++;
					continue;
				}
				else if( Angle(P(kr), P(i), P(j)) <= D)
				{
					while( !k_que.empty() && v[kr][i] > v[k_que.back()][i] )
						k_que.pop_back();
						
				//	cout << "   push(" << kr << "), angle = " << setprecision(10) <<Angle(P(kr), P(i), P(j)) <<endl;
				
					k_que.push_back(kr);
					kr++;
				}
				else
					break;
			}
			
			if(!k_que.empty())
				v[i][j] = v[k_que.front()][i]+1;
			else
				v[i][j] = (-1);
			
			/*
			printf("   que : ");
			for(auto it=k_que.begin(); it!=k_que.end(); it++)
				cout << *it << ", ";
			cout <<endl;
			// */
		}
	}
	
}

int main()
{
	cin >> n >> D;
	for(int i=0; i<n; i++)
		cin >> h[i];
	
	
	sol_DP(n);
	
	/*
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
			cout << v[i][j] << ", ";
		cout <<endl;
	}
	// */
	
	int ans = -1;
	for(int i=0; i<n; i++)
		ans = max(ans,v[i][n-1]);
	
	cout << ans << endl;
	
	return 0;
}



