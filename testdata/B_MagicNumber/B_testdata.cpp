#include <iostream>
#include <iomanip>
#include "../testlib.h"
using namespace std;
int tests[] = {0, 33, 33, 34};
int data[] = {0, 20, 4000, 4000000};
char clist[] = "0123456789abcdef";
bool x[4000000] = {};
int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);
	for(int q=1; q<=3; q++) {
		for(int w=1; w<=tests[q]; w++) {
			stringstream ss;
			ss<<"data/"<<setfill('0')<<setw(2)<<q<<setw(2)<<w<<".in";
			fstream f;
			f.open(ss.str().c_str(), ios::binary|ios::out);

			memset(x, 0, sizeof(x));
			for(int e=0; e<data[q]; e++) {
				int s = (data[q]-e)/3;
				if(s<= 1) break;
				int c = rnd.next(1, s);
				e += c - e%c;
				x[e] = 1;
				x[e+c] = 1;
				x[e+2*c] = 1;
				e += c*3;
			}
			int e=data[q]-1;
			while(x[e]+x[e-1]+x[e-2]+x[e-3]==0) {
				e-=4;
			}
			for(; e>=0; e-=4) {
				f<<clist[x[e]*8+x[e-1]*4+x[e-2]*2+x[e-3]];
			}
			f<<endl;

			f.close();
		}
	}
}
