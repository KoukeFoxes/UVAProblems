#include "bits/stdc++.h"
using namespace std;
int main(){
    int N;
    while(cin >> N){
        
        string str;
        getline(cin, str);

        istringstream iss;
        iss.str(str);
        vector<int> v;

        int n;
        while(iss >> n){
            v.push_back(n);
        }
        
        vector<int> diff;
        for(int i = 0 ; i < v.size() - 1 ; i++){
            diff.push_back(abs(v[i] - v[i+1]));
        }

        sort(diff.begin() , diff.end());

        bool isJolly = true;
        
        for(int i = 0 ; i < diff.size() - 1 ; i++){
            if(diff[i] != diff[i+1] - 1){
                isJolly = false;
                break;
            }
        }
        
        if(isJolly)
            cout << "Jolly" << endl;
        else
            cout << "Not jolly" << endl;     
    
    }
}
