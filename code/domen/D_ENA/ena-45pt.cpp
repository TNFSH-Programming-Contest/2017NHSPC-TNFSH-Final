#include <iostream>
#include <iomanip>
#include <complex>
#include <cmath>
#include <cassert>
#define X real()
#define Y imag()
#define INF 1000000
#define MAXN 10000
using namespace std;
typedef complex<double> Point;
double dot(Point a, Point b)
{
	return a.X*b.X + a.Y*b.Y;
}
double cross(Point a, Point b)
{
	return a.X*b.Y - a.Y*b.X;
}
double cross3(Point a, Point b, Point c)
{
	return cross(b-a, c-b);
}
//double toDeg(double t){ return t*180.0/acos(-1); };
double calc_degree(Point a, Point b, Point c)
{
	//Point v1 = b-a;
	//Point v2 = c-b;
	//return
	//	toDeg(
	//		abs( atan2((double)v1.Y, (double)v1.X) - atan2((double)v2.Y, (double)v2.X) )
	//	);

	double cosx = dot(a-b, c-b) / (abs(a-b) * abs(c-b));
	if(cosx<-1) cosx=-1;
	else if(cosx>1) cosx=1;
	double degree = acos(cosx)*180/acos(-1);
	//cout<<fixed<<setprecision(180)<<cosx+1<<' '<<-1<<endl;
	//cout<<cosx<<' '<<degree<<' '<<acos(cosx)<<' '<<acos(-1)<<endl;
	assert(!std::isnan(degree));
	return 180-degree;
	//if(cross(b-a, c-b)>0) return 180 - degree;
	//else return -180 + degree;
}
int h[MAXN];
int dp[MAXN][MAXN];
bool conn[MAXN][MAXN];
//pair<int,int> from[MAXN][MAXN];
Point p(int i)
{return Point(i,h[i]);}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n,d;
	cin>>n>>d;
	for(int i=0;i<n;i++)
		cin>>h[i];

	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			bool ok=1;
			for(int k=i+1;k<j;k++)
				if(cross3(p(i), p(k), p(j)) < 0)
					{ok=0; break;}
			conn[i][j]=conn[j][i]=ok;
		}
	}

	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(!conn[i][j])
				dp[i][j]=-INF-2;
			else if(j==0)
				dp[i][j]=2;
			else
			{
				dp[i][j]=-INF;
				for(int k=0;k<j;k++)
					if(conn[j][k])
					{
						if(calc_degree(p(k), p(j), p(i)) < d)
						{
							//if(dp[j][k] + 1 > dp[i][j])
							//	from[i][j] = {j,k};
							dp[i][j] = max(dp[i][j], dp[j][k] + 1);
						}
					}
			}
		}
	}

	//for(int i=1;i<n;i++)
	//{
	//	cout<<i<<"   ";
	//	for(int j=0;j<i;j++)
	//		cout<<dp[i][j]<<' ';
	//	cout<<endl;
	//}
	//for(int i=1;i<n;i++)
	//{
	//	if(dp[i][i-1]!=i+1)
	//	{
	//		cout<<i<<' '<<dp[i][i-1]<<endl;
	//		break;
	//	}
	//}

	int ans=-INF;
	for(int i=0;i<n-1;i++)
		ans=max(ans, dp[n-1][i]);
	
	//pair<int,int> now;
	//for(int i=0;i<n-1;i++)
	//	if(dp[n-1][i] == ans)
	//	{
	//		now={n-1,i};
	//		break;
	//	}
	//while(now.first!=0)
	//{
	//	cout<<now.first<<endl;
	//	now = from[now.first][now.second];
	//}

	if(ans<0) cout<<-1<<endl;
	else cout<<ans<<endl;
}
