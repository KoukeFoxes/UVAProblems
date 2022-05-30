#include "bits/stdc++.h"
using namespace std;

int findX(int x, vector<int> v){
	for(int i = 0 ; i < v.size() ; i++){
		if(v[i] == x)
			return i;
	}
	return -1;
}

int main() {
	int N, Q;
	int cases = 1;
	while(cin >> N >>Q && (N != Q != 0)){
		vector<int> Ns(N);
		
		for (int &i : Ns)
			cin >> i;
		sort(Ns.begin(), Ns.end());

		vector<int> find_(Q);
		for(int &i : find_){
			cin >> i ;
		}

		int atIndex = -1;
		cout << "CASE# " << cases++ <<":" << endl; 
		for(int i = 0 ; i < Q ; i++){
			atIndex = findX(find_[i], Ns);
			if(atIndex != -1){
				cout << find_[i] << " found at " << atIndex + 1 << endl;
			}else{
				cout << find_[i] << " not found" << endl;
			}

		}
		
		
		
	}
}
