#include "bits/stdc++.h"
using namespace std;

int main2() {
  string week[7] = {"Monday", "Tuesday",  "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
  int doomsday[12] = {10, 21, 7, 4, 9, 6, 11, 8, 5, 10, 7, 12};
  int N, M, D, i, index;

  cin >> N;

  for( int i = 0 ; i < 8 ; i ++){
	cin >> M >> D;
	index = D - doomsday[M-1];
	if(index < 0)
		index+=7;
	else
		while (index < 0)
        index += 7;
      index %= 7;
	  
	cout << week[index] << endl;  
  }
} 

int main(){
	string week[] = {"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
	int month_days[] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int cases; cin >> cases;
	while(cases--){
		
		int M,D;
		cin >> M >> D;
		//2020/12/31 is Friday, so 2021/1/1 is Saturday, index is 5
		int w = 4;
		for(int temp = 0; temp < M-1 ; temp++){
			w += month_days[temp];
		}
		
		w = (w + D) % 7;

		cout << week[w] << endl;
	}

}
