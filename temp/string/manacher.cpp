#include <iostream>
using namespace std;

int manacher(string S) {					// manacher
	if(S.size() == 0) return 0;				// 空串返回0。
	
	int len = S.size() * 2 + 1;				// 构造串长度。
	
	char *s  = new char[len];				// 构造串。
	int *p = new int[len];					// 对称半径。
	
	for (int i=0, j=0; i<len; i++)
		s[i] = (i&1) ? S[j++] : '#';		// 构造串。
		
	int R=-1, C=-1, ans=0;
	for (int i=0; i<len; i++)
	{
		p[i] = R>i ? min(R-i, p[C*2-i]) : 1;
		#define l i-p[i]
		#define r i+p[i]
		while (l>=0 && r<len && s[l]==s[r]) 
			p[i] ++;
		if (r > R) R = (C=i) + p[i];
		ans = max(ans, p[i]);
	}
	
	delete[] s; 
	delete[] p;
	
	return ans - 1;
}

int main()
{
	string s;
	getline(cin,s);
	cout << manacher(s);
}

