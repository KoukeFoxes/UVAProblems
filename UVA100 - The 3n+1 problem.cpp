#include "bits/stdc++.h"

using namespace std;
int getLen(int N){
	int length = 1;
	while(N != 1){
		if (N % 2 == 0){
			N /= 2;
		}else{
			N = 3*N + 1;
		}
		length++;
	}
	return  length;
}
int main() {
	int A, B ;
	while(cin >> A >> B){
		int ans = 0;
		
		for(int i = A ; i <= B ; i++)
			ans = max(ans, getLen(i));
		
		cout << ans;
	}
} 
