#include "bits/stdc++.h"
using namespace std;

int main() {
	int w, h;
	
	while(cin >> w >> h){
		map<int,int> counter;
		counter[w]++;
		counter[h]++;
		for(int i = 1 ; i < 6 ; i++){
			cin >> w >> h;
			counter[w]++;
			counter[h]++;
		}

		if(counter.size() > 3)
			cout << "IMPOSSIBLE" << endl;
		else{
			bool flag = true;
			for(auto i : counter)
				if(i.second % 4 != 0){
					flag = false;
					break;
				}
			if(flag)
				cout << "POSSIBLE" << endl;
			else
				cout <<"IMPOSSIBLE" << endl;
		}
		
			
	}
}
