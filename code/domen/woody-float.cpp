#include <iostream>
#include <cmath>
#include <cassert>
using namespace std;
int main()
{
	// (L*(1/2)^N)^2 <= A
	// L*L/A <= 2^N
	float A,L;
	cin>>A>>L;
	cout<<max((int)ceil(log2(L*L/A)),0)<<endl;
}
