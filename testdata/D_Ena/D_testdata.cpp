#include <iostream>
#include <iomanip>
#include "../testlib.h"
using namespace std;
int tests[] = {0, 20, 20, 30, 30};
int data[] = {0, 15, 15, 100, 10000};
int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);
	int l;
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
			l = rnd.next(1, 100);
			f<<l;
			for(int e=1; e<n; e++) {
				l = rnd.next(1, 100);
				f<<" "<<l;
			}
			f<<endl;

			f.close();
		}
	}
}
