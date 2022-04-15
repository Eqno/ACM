#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    for (int i=0; i<=25; i++)
    {
        int num = i, gray = 0;
        vector<int> d;
        while (num)
        {
            d.push_back(num & 1);
            num >>= 1;
        }
        if (d.empty()) goto nextLoop;
        for (size_t j=0; j<d.size()-1; j++)
            d[j] ^= d[j+1];
        reverse(d.begin(), d.end());
        for (auto j: d) gray = gray*10 + j;
nextLoop:
        printf("%05d\n", gray);
    }
    return 0;
}