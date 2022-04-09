#include "bits/stdc++.h"
using namespace std;
int main2() {
	long long int S, D;
	int temp = 0;
	while(cin >> S >> D){
		for(int i = S ;; i ++){
			S+=(i+1);
			if(S>=D){
				cout << i+1 << endl;
				break;
			}
		}

	}
} 
