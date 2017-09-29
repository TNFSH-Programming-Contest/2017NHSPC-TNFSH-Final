/* jd3 0927 */

#include <iostream>


using namespace std;

int main()
{
	int A,L;
	
	cin >> A >> L;
	
	int AWood = L*L;
	int j=0;
	while( A < AWood )
	{
		j++;
		A *= 2;
	}
	
	cout << j << endl;
	
	return 0;
}



