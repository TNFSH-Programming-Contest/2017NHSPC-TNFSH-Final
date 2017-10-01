#include <iostream>
#include <complex>
#include <cmath>
#include <cassert>
#define X real()
#define Y imag()
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
double calc_degree(Point a, Point b, Point c)
{
	double cosx = dot(a-b, c-b) / (abs(a-b) * abs(c-b));
	double degree = acos(cosx)*180/acos(-1);
	if(cross(b-a, c-b)>0) return 180 - degree;
	else return -180 + degree;
}
int h[10010];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n,d;
	cin>>n>>d;
	assert(2<=n && n<=10000 && 0<d && d<=180);
	for(int i=0;i<n;i++)
	{
		cin>>h[i];
		assert(h[i]<=100 && h[i]>0);
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<i;j++)
			for(int k=i+1;k<n;k++)
			{
				double deg = abs(calc_degree(Point(j,h[j]), Point(i,h[i]), Point(k,h[k])));
				if(abs(d-deg)<1e-6)
				{
					cerr<<j<<' '<<i<<' '<<k<<' '<<deg<<endl;
					assert(0);
				}
			}
}
