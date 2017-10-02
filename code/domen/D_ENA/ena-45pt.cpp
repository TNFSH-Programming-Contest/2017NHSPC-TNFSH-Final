#include <iostream>
#include <iomanip>
#include <complex>
#include <cmath>
#include <cassert>
#define X real()
#define Y imag()
#define INF 1000000
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
double calc_degree(Point a, Point b, Point c)
{
	double cosx = dot(a-b, c-b) / (abs(a-b) * abs(c-b));
	double degree = acos(cosx+1e-10)*180/acos(-1);
	//cout<<fixed<<setprecision(180)<<cosx+1<<' '<<-1<<endl;
	//cout<<cosx<<' '<<degree<<' '<<acos(cosx)<<' '<<acos(-1)<<endl;
	assert(!isnan(degree));
	return 180-degree;
	//if(cross(b-a, c-b)>0) return 180 - degree;
	//else return -180 + degree;
}
int h[10000];
int dp[10000][10000];
bool conn[10000][10000];
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
			{
				dp[i][j]=-INF-2;
				//assert(j!=i-1);
			}
			else if(j==0)
				dp[i][j]=2;
			else
			{
				dp[i][j]=-INF;
				for(int k=0;k<j;k++)
				{
					if(conn[j][k])
					{
						if(calc_degree(p(k), p(j), p(i)) < d)
							dp[i][j] = max(dp[i][j], dp[j][k] + 1);
						//cout<<calc_degree(p(k), p(j), p(i))<<endl;
					}
					//else if(j==i-1 && k==j-1)
					//	cout<<k<<' '<<i<<' '<<j<<endl;
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
	if(ans<0) cout<<-1<<endl;
	else cout<<ans<<endl;
}
