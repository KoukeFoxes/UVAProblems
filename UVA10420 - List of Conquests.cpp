#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>


using namespace std;

int main2() {
  int n, i, j, count;
  vector<string> CountryName;
  string line;

  cin >> n;

  for (i = 0; i < n; i++) {
    cin >> line;
    CountryName.push_back(line);
    getline(cin, line);
  }

  sort(CountryName.begin(), CountryName.end());

  i = 0;
  while (i < n) {
    cout << CountryName[i] << " ";
    count = 1;
    for (j = i + 1; j < n; j++) {
      if (CountryName[j] != CountryName[i])
        break;
      else
        count++;
    }
	i += count;
	cout << count << endl;
  }

  return 0;
}

int main(){
	int times;
	cin >> times;
	vector<string> country;
	while(times--){
		string temp;
		cin >> temp;
		country.push_back(temp);
		getline(cin,temp);
	}
	sort(country.begin(),country.end());

	int counter = 1;
	for(int i = 0 ; i < country.size();i++){
		if(i == country.size()-1){
			cout << country[i] << " " << counter << endl; 
		}else if(country[i] != country[i+1]){
			cout << country[i] << " " << counter << endl; 
			counter = 0;
		}
		counter++;
	}
}
