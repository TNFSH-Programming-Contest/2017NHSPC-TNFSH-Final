#include<bits/stdc++.h>
#include "../testlib.h"
using namespace std;
//mt19937 g1(11037);
int pow10[]={1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};
int RAND(int a, int b){
//	return g1()%(b-a+1)+a;
	return rnd.next(a, b);
}
int main(int argc, char* argv[]){
	registerGen(argc, argv, 1);
	for(int q=1;q<=2;q++){
		for(int w=1;w<=25;w++){
			stringstream ss;
			ss<<(q<10?"0":"")<<q<<(w<10?"0":"")<<w<<".in";
			fstream f;
			f.open(ss.str().c_str(), ios::out);
			
			f<<RAND(1,pow10[RAND(1,8)]-1)<<" "<<RAND(1,pow10[RAND(1,4)]-1)<<endl;
			
			f.close();
		}
	}
}

