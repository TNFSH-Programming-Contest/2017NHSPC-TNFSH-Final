#include <iostream>
#include <cassert>
using namespace std;
int main()
{
	// (L*(1/2)^N)^2 <= A
	// L*L/A <= 2^N
	int A,L;
	cin>>A>>L;
	assert(A<=100000000 && L<=10000);
	int tn=1; // 2^N
	for(int i=0;;i++)
	{
		if(L*L <= A*tn)
		{
			cout<<i<<endl;
			break;
		}
		tn<<=1;
	}
}
