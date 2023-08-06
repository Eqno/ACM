#include <string>
#include <iostream>
using namespace std;

string manacher(string S) {						// manacher
	if(S.size() <= 1) return S;					// 长度小于等于1，返回串本身
	int len = S.size() * 2 + 1;					// 构造串长度 = 2*原串长度+1
	
	char *s  = new char[len];					// 申请构造串空间
	int *p = new int[len];						// 申请对称半径空间
	
	for (int i=0,j=0; i<len; i++)				// 生成构造串
		s[i] = (i&1) ? S[j++] : '#';			// 原串间隔插入'#'
		
	int R = -1, C = -1, m = 0, c = 0;			// R：对称串右端点，C：对称串中心点
	for (int i=0; i<len; i++) {					// m：最大对称半径，c：最大对称中心
		p[i] = R>i ? min(R-i, p[C*2-i]) : 1;	// 计算当前对称半径大小
		#define l i - p[i]						// 对称串左端点
		#define r i + p[i]						// 对称串右端点
		while (l>=0 && r<len && s[l]==s[r])		// 更新当前对称半径大小
			p[i] ++;
		if (r > R) R = (C = i) + p[i];			// 更新右端点和对称中心
		if (p[i] > m) m = p[i], c = C;			// 更新最大对称半径和最大对中心
	}
	return string(S.begin()+(c-m+1)/2, S.begin()+(c+m-1)/2);  // 返回答案
}

int main() {
	string s;
	getline(cin,s);
	cout << manacher(s);
}

