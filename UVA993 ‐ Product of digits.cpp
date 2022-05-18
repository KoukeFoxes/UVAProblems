#include "bits/stdc++.h"
using namespace std;
int main()
{
  int cases;
  cin >> cases;
  while (cases--)
  {
    long N;
    cin >> N;
    int origin = N;
    string ans = "";
    for (int i = 9; i >= 2;)
    {
      if (N % i == 0)
      {
		N /= i;
	    ans = to_string(i) + ans;
        
      }else if (N == 1 && ans == ""){
        ans = "1" + ans;
        break;
      }
	  else
        i--;
    }
	int check = 1;
	for(int i : ans)
		check*= i - '0';
    if(check != origin){
		cout << "-1" << endl;
	}else{
		cout << ans << endl;
	}
  }
}
