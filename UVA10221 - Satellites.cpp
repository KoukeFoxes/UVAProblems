#include "bits/stdc++.h"
using namespace std;

int main(){
	long double arc, chord, distance, angle;
	string unit;
	while(cin >> distance >> angle >> unit){
		
		if(unit == "min")
			angle /= 60;
		
		if(angle > 180)
			angle = 360 - angle;

		angle = angle*M_PI/180;

		arc = (6440+distance)*angle;
		chord = 2.0 * (6440+distance) * sin(angle/2.0);

		cout << fixed << setprecision(6) << arc << " " << chord << endl;
		
	}
}
