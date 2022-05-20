#include "bits/stdc++.h"
using namespace std;

int main() {

	int cases;
	cin >> cases;
	while(cases--){

		int n; //player_counter
		cin >> n;
		
		double p;
		cin >> p; //win
		double q = 1 - p; //lose

		int k; //times
		cin >> k;

		double r = pow(q, n);
		double a0 = pow(q, k-1) * p;

		//無限等比級數 a0/1-r
		double sum = a0 / ( 1 - r);

		if(p==0)
			cout << "0.0000" << endl;
		else
			cout << fixed << setprecision(4) << sum << endl;
		
		
	}
}
