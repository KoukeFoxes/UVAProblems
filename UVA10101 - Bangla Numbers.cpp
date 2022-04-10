#include "bits/stdc++.h"

using namespace std;
void prgress(long long int input){
		if(input/10000000){
			prgress(input/ 10000000);
			cout << " kuti ";
			input%= 10000000;
		}
		if(input / 100000){
			prgress(input/ 100000);
			cout << " lakh ";
			input%= 100000;
		}
		if(input / 1000){
			prgress(input/ 1000);
			cout << " hajar ";
			input%= 1000;
		}
		if(input / 100){
			prgress(input/ 100); 
			cout << " shata ";
			input%= 100;
		}
		if(input)
			cout << input;
}
int main() {
	long long int input;
	cout.setf(ios::right);
  	cout.width(4);
	int index = 0;
	while(cin >> input){
		cout << ++index << ". ";
		prgress(input);
	}
} 
