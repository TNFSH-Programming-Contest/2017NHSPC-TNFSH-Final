#include <iostream>
#include <iomanip>
#include "../testlib.h"
using namespace std;
int _pow10[]={1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};
int main(int argc, char* argv[]){
	registerGen(argc, argv, 1);
	for(int q=1;q<=2;q++){
		for(int w=1;w<=25;w++){
			stringstream ss;
			ss<<"data/"<<setfill('0')<<setw(2)<<q<<setw(2)<<w<<".in";
			fstream f;
			f.open(ss.str().c_str(), ios::out);
			
			int range1 = _pow10[rnd.next(1,8)]-1;
			int range2 = _pow10[rnd.next(1,4)]-1;
			f<<rnd.next(1,range1)<<" "<<rnd.next(1,range2)<<endl;
			
			f.close();
		}
	}
}
