#include "bits/stdc++.h"
using namespace std;

int main(){
	int cases;
	cin >> cases;
	while(cases--){
		int N;
		cin >> N;
		string str = "";
		for(int i = 1; i <= N; i++)
			str += to_string(i);

		int table[10] = {};
		for(char c : str)
			table[c - '0']++;

		for(int i : table)
			cout << i << " ";

		cout << endl;
	}
}
