#include "bits/stdc++.h"
using namespace std;
// #include "/Users/doeshing/development/stdc++.h"


int main(){
	int N;
	std::cin >> N;
	for(int i = 1 ; i <= N ; i++){

		int x1, y1, x2, y2;
		std::cin >> x1 >> y1 >> x2 >> y2;

		int step = 0;
		step += (((x2 + y2 + 1) + (x1 + y1 + 1)) * ((x2 + y2) - (x1 + y1) + 1)) / 2;
		step -= y2 + 1;
		step -= x1;

		std::cout << "Case " << i << ": " << step << std::endl;
	}
}





int main2()
{
	
	int n,x1,y1,x2,y2,i;
	
	cin>>n;//輸入測資數量 
    for(i=1;i<=n;i++)
    {
		cin>>x1>>y1>>x2>>y2;//輸入測資
    	int count=0;
    	
		count+=(y1+x1+1+y2+x2)*(y2+x2-y1-x1)/2;//計算從起始的線到最後的線的步數 
		count+=(x2-x1);//調整誤差

		// 等於 (x2-x1 ,y2-y1)
		// 有 (0,0) -> (0,1) (1,0) -> (0,2) (1,1) (2,0) ->(0,3) (1,2) (2,1) (3,0) 這個規律
		// 那從 (1,2) 到(0,0) 的距離就等於 (0,0) ->(0,3) 的距離 + (0,3)->(1,2) 的距離
		// (0,0) 到(0,3) 的步數 等於 (0,0)->(0,1)+ (0,1)->(0,2) + (0,2)->(0,3)
		// 然後 6+ (0.3)->(1,2) 的距離 就等於 (0,0) ->(1.2) 的距離
		// 那這段就會等於  (底+高) *高 /2  + (誤差)
		// (1+3)*3/2 + x1
		// (1+(x1+y1)) *(x1+y1)/2 +x1
		// (x1,y1) - (x2,y2) 的距離
		
		 
		cout<<"Case "<<i<<": "<<count<<endl;//輸出 
	}
    return 0;
}
