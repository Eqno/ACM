#include <cstring>
#include <string>
#include <iostream>
using namespace std;

int *getNext(const string &t) {
    int *next = new int[t.size()] {-1};
    int j = 0, k = -1;
    while (j < t.size()-1) {
        if (k==-1 || t[j]==t[k]) {
            if (t[++j] == t[++k]) {
                next[j] = next[k];
            } else next[j] = k;
        } else k = next[k];
    }
    return next;
}

int kmp(const string &s, const string &t) {
    int i = 0, j = 0, *next = getNext(t);
    while (i<int(s.size()) && j<int(t.size())) {
        if (j==-1 || s[i]==t[j]) {
            i++, j++;
        } else j = next[j];
    }
    return (j==t.size()) ? (i-j) : -1;
}

int main() {
    string a = "hello", b = "ll";
    cout << kmp(a, b) << endl;
    return 0;
}