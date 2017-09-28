#include<bits/stdc++.h>
#include "../testlib.h"
using namespace std;
//mt19937 g1(11037);
int RAND(int a, int b){
//	return g1()%(b-a+1)+a;
	return rnd.next(a, b);
}
int tests[]={0, 33, 33, 34};
int data[]={0, 5, 1000, 1000000};
char clist []="0123456789abcdef";
int main(int argc, char* argv[]){
	registerGen(argc, argv, 1);
	for(int q=1;q<=3;q++){
		for(int w=1;w<=tests[q];w++){
			stringstream ss;
			ss<<(q<10?"0":"")<<q<<(w<10?"0":"")<<w<<".in";
			fstream f;
			f.open(ss.str().c_str(), ios::out);
			
			int t=RAND(1, data[q]);
			f<<clist[RAND(1, 15)];
			for(int e=2;e<=t;e++){
				f<<clist[RAND(0, 15)];
			}
			f<<endl;
			
			f.close();
		}
	}
}

