#include <iostream>
#include <iomanip>
#include <cassert>
#include "../testlib.h"
using namespace std;
int tests[] = {0, 33, 33, 34};
int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);
	int l, x, i, L, R, v, a, b, c;
	for(int q=1; q<=3; q++) {
		for(int w=1; w<=tests[q]; w++) {
			stringstream ss;
			ss<<"data/"<<setfill('0')<<setw(2)<<q<<setw(2)<<w<<".in";
			fstream f;
			f.open(ss.str().c_str(), ios::binary|ios::out);

			int n = 200000;
			if(q==1) n = 100;
			n = rnd.next(1, n);
			f<<n<<endl;
			l = rnd.next(1, 100000000);
			f<<l;
			for(int e=1; e<n; e++) {
				l = rnd.next(1, 100000000);
				f<<" "<<l;
			}
			f<<endl;

			int m = rnd.next(1, 100000);
			f<<m<<endl;

			a = rnd.next(1, 10); // K=1
			c = rnd.next(1, 10); // K=2
			b = rnd.next(1, (a+c)/2); // K=3
//			cout<<a<<" "<<b<<" "<<c<<endl;
			b += a;
			c += b;
			int k = c;
//			cout<<a<<" "<<b<<" "<<c<<endl;
			if(q==2) k = b;

			for(int e=0; e<m; e++) {
				l = rnd.next(1, k);
				if(l<=a) {
					x = rnd.next(1, 10000);
					i = rnd.next(0, n-1);
					f<<1<<" "<<x<<" "<<i<<endl;
				} else if(l<=b) {
					f<<3<<endl;
				} else if(l<=c) {
					L = rnd.next(0, n-1);
					R = rnd.next(L, n-1);
					v = rnd.next(1, 1000000);
					f<<2<<" "<<L<<" "<<R<<" "<<v<<endl;
				} else {
					assert(false);
				}
			}

			f.close();
		}
	}
}
