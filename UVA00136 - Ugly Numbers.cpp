#include "bits/stdc++.h"
using namespace std;

int main(){
	vector<long long int> ugly;
	int n = 1500;
	long long int a,b,c,m = INT_MAX;
	for(a = 1 ; a <= m ; a*=2)
		for(b = a; b <= m ; b *= 3)
			for(c = b ; c <= m ; c *= 5)
				ugly.push_back(c);
	sort(ugly.begin(), ugly.end());
	cout << "The 1500'th ugly number is " << ugly[1500-1] << ".";
}
