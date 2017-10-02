#include <iostream>
#include <iomanip>
#include "../testlib.h"
using namespace std;
int tests[] = {0, 20, 20, 30, 30};
int data[] = {0, 10000, 15, 100, 10000};
const int maxl = 1000;
int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);
	int l, sl, c, x;
	for(int q=1; q<=4; q++) {
		for(int w=1; w<=tests[q]; w++) {
			stringstream ss;
			ss<<"data/"<<setfill('0')<<setw(2)<<q<<setw(2)<<w<<".in";
			fstream f;
			f.open(ss.str().c_str(), ios::binary|ios::out);

			int n = rnd.next(2, data[q]);
			int d;
			if(q==1) d = 180;
			else d = rnd.next(1, 180);
			f<<n<<" "<<d<<endl;
			
			if(q != 2 && w <= 3) {
				sl = rnd.next(2, maxl);
				f<<sl;
				for(int e=1; e<n-1; e++) {
					c = rnd.next(1, 5);
					if(c<=1){
						l = rnd.next(1, sl-1);
					} else {
						l = sl;
					}
					f<<" "<<l;
				}
				f<<" "<<sl;
			} else if(q != 2 && w <= 6) {
				int min = rnd.next(n/4, n/4*3);
				int d = rnd.next(1, 100);
				int r = rnd.next(n, n*4);
				
				for(int e=0; e<n; e++) {
					if(e) f<<" ";
					x = abs(min - e);
					if(x>=r) {
						l = r+d;
					} else {
						l = (int)(r-sqrt(r*r-x*x)+d);
					}
					f<<l;
				}
			} else {
				l = rnd.next(1, maxl);
				f<<l;
				for(int e=1; e<n; e++) {
					l = rnd.next(1, maxl);
					f<<" "<<l;
				}
			}
				
			f<<endl;

			f.close();
		}
	}
}
