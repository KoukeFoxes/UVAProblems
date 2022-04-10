include "bits/stdc++.h"


int main() {
  int r;
  int temp;
  std::vector<int> v;
  std::cin >> r;
  for (int i = 0; i < r ; i++){ // case
	  v.clear();
	  int number;
	  std::cin >> number;
	  while(number--){
		  std::cin >> temp;
		  v.push_back(temp);
	  }
	  sort(v.begin(),v.end());
	  int mid = v[v.size()/2];
	int ans = 0;
	  for(int i = 0 ; i < v.size() ; i++){
		  ans+= abs(mid-v[i]);
	  }
	  std::cout << ans << std::endl;

  }

} 
