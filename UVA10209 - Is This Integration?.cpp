#include "bits/stdc++.h"
using namespace std;

int main(){
	double W;
	while(cin >> W){
		double square = W*W  - (W*W*sqrt(3)/4) - (W*W*M_PI/6);
		double dot = W*W - (W*W*M_PI/4) - (2*square);
		double slash = W*W - 4*dot - 4*square;
		cout << fixed << setprecision(3) << slash << " " << 4*dot << " " << 4*square;
	}
}
