#include "bits/stdc++.h"
using namespace std;

int main() {
	int Li, Hi, Ri;
	vector<int> skyline;
	int min_ = 999999;
	string str;
	while(getline(cin, str) && str != ""){
		istringstream iss;
		iss.str(str);
		iss >> Li >> Hi >> Ri;
		min_ = min(Li, min_);
		
		while(Ri >= skyline.size())
			skyline.push_back(0);

		
		for(int i = Li; i < Ri; i++){
			skyline[i] = max(skyline[i], Hi);
		}
			
	}
	int last = -1;
	for(int i = min_ ; i < skyline.size(); i++){
		if(last == skyline[i])
			continue;
		cout << i << " " << skyline[i] << " ";
		last = skyline[i];
	}
	cout << endl;
}
