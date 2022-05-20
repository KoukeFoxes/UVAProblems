
/*
UVA10050 - Hartals
A social research organization has determined a simple set of parameters to simulate the behavior of
the political parties of our country. One of the parameters is a positive integer h (called the hartal
parameter) that denotes the average number of days between two successive hartals (strikes) called by
the corresponding party. Though the parameter is far too simple to be flawless, it can still be used to
forecast the damages caused by hartals. The following example will give you a clear idea:
Consider three political parties. Assume h1 = 3, h2 = 4 and h3 = 8 where hi
is the hartal parameter
for party i (i = 1, 2, 3). Now, we will simulate the behavior of these three parties for N = 14 days.
One must always start the simulation on a Sunday and assume that there will be no hartals on weekly
holidays (on Fridays and Saturdays).
Days    1    2    3    4    5    6    7    8    9    10    11    12    13    14
        Su    Mo    Tu    We    Th    Fr    Sa    Su    Mo    Tu    We    Th    Fr    Sa
Party 1              x              x              x              x          
Party 2                   x                   x                   x          
Party 3                                       x                              
Hartals              1    2                   3    4              5    
The simulation above shows that there will be exactly 5 hartals (on days 3, 4, 8, 9 and 12) in 14
days. There will be no hartal on day 6 since it is a Friday. Hence we lose 5 working days in 2 weeks.
In this problem, given the hartal parameters for several political parties and the value of N, your
job is to determine the number of working days we lose in those N days.
Input
The first line of the input consists of a single integer T giving the number of test cases to follow.
The first line of each test case contains an integer N (7 ≤ N ≤ 3650) giving the number of days over
which the simulation must be run. The next line contains another integer P (1 ≤ P ≤ 100) representing
the number of political parties in this case. The ith of the next P lines contains a positive integer hi
(which will never be a multiple of 7) giving the hartal parameter for party i (1 ≤ i ≤ P).
Output
For each test case in the input output the number of working days we lose. Each output must be on a
separate line.
Content
一個社會研究組織採用了一組簡單的參數來模擬我們國家政黨運作的行為。
參數之一是一個正整數h，h稱為罷會(hartal)參數，它表示同一個政黨連續兩次連續罷會的間隔天數。
儘管該參數有點過於簡單，但還是能用於預測政黨罷會造成的影響。
以下範例為您說明：
考慮現在有三個政黨。假設h1 = 3，h2 = 4，h3 = 8，其中hi是第i方的罷會參數。
現在，我們將模擬這三個方在N = 14天的罷會行為。
模擬的起始天一定是星期天，並假設在每週的假日(星期五和星期六)不會有任何罷會情形。
// Days    0    1    2    3    4    5    6    7    8    9    10    11    12    13
Days    1    2    3    4    5    6    7    8    9    10    11    12    13    14
        Su    Mo    Tu    We    Th    Fr    Sa    Su    Mo    Tu    We    Th    Fr    Sa
Party 1              x              x              x              x          
Party 2                   x                   x                   x          
Party 3                                       x                              
Hartals              1    2                   3    4              5          
上面的模擬顯示，在14天內將會罷會5天(分別在第3、4、8、9和12天)。
第6天沒有罷會，因為它屬於假日(星期五)。由此可知我們在2週內損失了5個工作天。
在這個問題中，考慮到多個政黨的罷會參數和天數N，您的工作是計算出這N天內我們因為罷會損失多少工作天。
Input
輸入第一行有一個整數T，代表有T組測資。
每組測資第一行包含一個整數N (7 ≤ N ≤ 3650)，N代表模擬的天數。
下一行包含一個整數P (1 ≤ P ≤ 100)，表示有幾個政黨。
接下來的P行，第i行包含一個正整數hi(永遠不會是7的倍數)，代表第i個政黨的罷會參數。
Output
對於每組測資，輸出這N天內因為罷會損失多少工作天。
Sample Input
2
14
3
3
4
8
100
4
12
15
25
40
Sample Output
5
15
*/
#include "bits/stdc++.h"
using namespace std;
int main(){
   int T, N, P;
   cin >> T;
   while(T--){
       
       cin >> N; //days
       
       vector<int> days(N);
       for(int &i : days)
           i = 0;
       
       cin >> P; //parties
       vector<int> parties(P);
       for(int &i : parties)
           cin >> i;
       //calculat
       for(int party: parties){
           for(int i = party-1; i< days.size(); i+=party){
               days[i] = 1;
           }
       }
       //remove Fridays and Saturdays
       for(int i = 0; 6+7*i < days.size(); i++){
           days[5+7*i] = 0;
           days[6+7*i] = 0;
       }
       //sum days
       int result = 0;
       for(int i :days){
           result+=i;
       }
       cout << result << endl;
       
   } 
}
