/*
	pB. MagicNumber
	jd3 0930 update
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;


bool isNum(char c) {
	return '0'<=c && c<='9';
}

bool b[5000000];
	
int main()
{
	string s;
	cin >> s;
	
	int n = s.size()*4;
	for(int i=0; i<s.size(); i++)
	{
		int value;
		if( isNum(s[i]) )
			value = s[i]-'0';
		else
			value = s[i]+10-'a';
		
		b[n-i*4-1] = ((value>>3) & 1 );
		b[n-i*4-2] = ((value>>2) & 1 );
		b[n-i*4-3] = ((value>>1) & 1 );
		b[n-i*4-4] = (value & 1 );
	}
	b[n] = 1;
	
	/*
	for(int i=0; i<n; i++)
		cout << b[i];
	cout << endl;
	*/
	
	vector<int> len;
	vector<int> pos;
	for(int i=0; i<n; )
	{
		if(b[i]==1)
		{
			pos.push_back(i);
			int k=1;
			while(b[i+k]==0)
				k++;
			len.push_back(k);
			i += k;
		}
		else
			i++;
	}
	len.back() = len[len.size()-2];
	
	/*
	for(int i=0; i<len.size(); i++)
		cout << len[i] << " ";
	cout << endl;
	*/
	
	set<int> ans;
	for(int i=0; i+2<len.size(); i++)
	{
		if( len[i]==len[i+1] && len[i+1]<=len[i+2] && pos[i]%len[i] == 0 )
			ans.insert( len[i] );
	}
	
	for(auto it=ans.begin(); it!=ans.end(); it++)
		cout << *it << endl;
	
	return 0;
}



