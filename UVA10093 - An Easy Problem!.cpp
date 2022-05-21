#include "bits/stdc++.h"
using namespace std;
int main(){
	string str;
	string base_index = "0123456789"
					"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
					"abcdefghijklmnopqrstuvwxyz";
	while(cin >> str){
		int min = 0;
		bool isFound = false;
		
		//find the minimum possible base
		for(char c : str)
			min = (base_index.find(c) > min) ? base_index.find(c) : min;
		min++;

		//如果一個N進位制的數 (abc)是 (N-1) 的倍數，則 (a + b + c) 也是(N-1) 的倍數。
		int sum = 0;
		for(char c: str)
			sum += base_index.find(c);

		//mod
		int base = min;
		for(; base <= 62; base++){
			if(sum%(base-1)==0){
				isFound = true;
				break;
			}
		}
		
		cout << ((isFound) ? to_string(base) : "such number is impossible!") << endl;
	}
}
