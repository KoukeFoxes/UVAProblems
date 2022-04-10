#include "bits/stdc++.h"

using namespace std;

int main() {
	string A,B;
	int carr;
	int car_times;
	vector<int> ans;
	while(cin >> A >> B && (A != "0" || B != "0")){
		carr = 0;
		car_times = 0;
		int length  = A.length() > B.length() ? A.length() : B.length();
		for(int i = 0 ; i < length ; i++){
			int temp = (int)(A[A.length() - i -1] - '0') + (int)(B[B.length() - i -1] - '0') + carr;
			carr = temp / 10;
			if(carr != 0)
				car_times++;
			temp %= 10;
			ans.push_back(temp);
		}
		if(car_times == 0)
			cout << "No carry operation" << endl;
		else 	
			cout << car_times << " carry operation" << endl;
	}
} 
