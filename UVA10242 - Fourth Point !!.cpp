#include "bits/stdc++.h"
using namespace std;

double points[4][2];
double same[2];
bool foundtheSame;
int size;

bool isSame(double point[2]){
	for(int i = 0 ; i < size ; i++){
		if(point[0] == points[i][0] && point[1] == points[i][1])
			return true;
	}
	return false;
}

int main(){
	string str;
	while(getline(cin, str) && str != ""){
		size = 0;
		foundtheSame = false;
		stringstream ss(str);
		
		for(size = 0 ; size < 4 ; size++){
			ss >> points[size][0] >> points[size][1];
			if(size > 0 && isSame(points[size]) && !foundtheSame){
				same[0] = points[size][0];
				same[1] = points[size][1];
				foundtheSame = true;
			}
		}

		// for(int i = 0 ; i < 4 ; i++)
		// 	cout << fixed << setprecision(3) << points[i][0] << " " << points[i][1] << endl;

		// cout << endl << same[0] << " " << same[1] << endl;
		
		double x = 0, y = 0;
		for(int i = 0 ; i < 4 ; i++ ){
			x += points[i][0];
			y += points[i][1];
		}

		x -= 3* same[0];
		y -= 3* same[1];

		cout << fixed << setprecision(3) << x << " " << y << endl;
		
	}
}



