#include "bits/stdc++.h"
using namespace std;

bool isSame(int a, int b, string str){
	if(a > b){
		a = a + b;
		b = a - b;
		a = a - b;
		}
	b -= a;
	string temp = str.substr(a, ++b);
	map<char, int> counter;
	for(char c : temp)
		counter[c]++;
	if(counter.size()>1)
		return false;
	return true;
}


int main() {
	string str;
	int index = 1;
	while(getline(cin, str) && str != ""){
		cout << "Case " << index++ <<":" << endl;
		int n;
		cin >> n;
		while(n--){
			int a, b;
			cin >> a >> b;
			cout << (isSame(a, b, str) ? "Yes" : "No" )<< endl;
		}
		cin.ignore();
	}
}
