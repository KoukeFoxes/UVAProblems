#include "bits/stdc++.h"
using namespace std;

int main(){
	string str;
	while(getline(cin, str) && str != "0:00"){
		double h, m;
		
		for(int i = 0 ; i < str.length() ; i++)
			if(str[i] == ':'){
				h = stod(str.substr(0,i));
				m = stod(str.substr(i+1));
				break;
			}
		// cout << h << " " << m << endl;
		
		double angle_m = 360*(m/60);
		if(h >= 12)
			h -= 12;
		double angle_h = 30*h + 30*(m/60);

		// cout << angle_h << " " << angle_m << endl;

		double angle = abs(angle_h - angle_m);
		if(angle_m > 180 && angle_h < 180)
			angle = abs(360 - angle_m + angle_h);
		if(angle > 180)
			angle = 360 - angle;
		cout << fixed << setprecision(3) << angle << endl;

	}
}
