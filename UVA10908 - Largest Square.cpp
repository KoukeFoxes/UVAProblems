/*
UVA10908 - Largest Square

給定一個字元矩形，您必須找出最大正方形的邊的長度。
在其中正方形內的所有字元皆相同，並且正方形的中心(兩個對角線的交點)位於位置(r, c)。
矩形的高度和寬度分別為M和N。矩形的左上角座標為(0, 0)，右下角座標為(M-1, N-1)。

比方說下面給出的字元矩形。給定中心位置(1, 2)，此最大正方形邊長為3。

abbbaaaaaa
abbbaaaaaa
abbbaaaaaa
aaaaaaaaaa
aaaaaaaaaa
aaccaaaaaa
aaccaaaaaa

Input
輸入第一行為一個整數T (T < 21)，T代表有幾組測資。
每組測資的第一行包含三個整數M，N (1 <= M, N <= 100)，Q (Q < 21)。
其中M，N表示矩形的高度和寬度，Q代表詢問的數量。
接下來M行每行N個字元，代表輸入的字元矩形。
接下來Q行，每行包含兩個整數r和c。

Output
對於每組測資。
第一行輸出M，N，Q值，以空格分開。
接下來Q行，輸出以(r, c)當中心所對應的最大正方形邊長。

原文：
Given a rectangular grid of characters you have to find out the length of a side of the largest square such that all the characters 
of the square are same and the center [intersecting point of the two diagonals] of the square is at location (r,c). 
The height and width of the grid is M and N respectively. Upper left corner and lower right corner of the grid will be denoted by 
(0, 0) and (M − 1, N − 1) respectively. Consider the grid of characters given below. Given the location (1, 2) the length of a side of the 
largest square is 3.

abbbaaaaaa
abbbaaaaaa
abbbaaaaaa
aaaaaaaaaa
aaaaaaaaaa
aaccaaaaaa
aaccaaaaaa

Input
The input starts with a line containing a single integer T (< 21). This is followed by T test cases. The first line of 
each of them will contain three integers M, N and Q (< 21) separated by a space where M, N denotes the dimension of the grid. 
Next follows M lines each containing N characters. Finally, there will be Q lines each containing two integers r and c. 
The value of M and N will be at most 100.

Output
For each test case in the input produce Q+1 lines of output. In the first line print the value of M, N and Q in that order separated 
by single space. In the next Q lines, output the length of a side of the largest square in the corresponding grid for each (r, c) pair 
in the input.

Sample Input
1
7 10 4 
abbbaaaaaa 
abbbaaaaaa 
abbbaaaaaa 
aaaaaaaaaa 
aaaaaaaaaa 
aaccaaaaaa 
aaccaaaaaa 
1 2
2 4
4 6
5 2

Sample Output
7 10 4 
3
1
5
1

相關參考：
https://zerojudge.tw/ShowProblem?problemid=e575

*/

#include "/Users/doeshing/development/stdc++.h"
// #include "bits/stdc++.h"
#define AND &&
#define OR ||

using namespace std;

int isOutOfRange(int r, int c, int M, int N) {
    return r < 0 || r >= M || c < 0 || c >= N;
}

int main()
{
    int T;
    cin >> T;
    while(T--){

        int M, N, Q;
        cin >> M >> N >> Q;
        cout << M << " " << N << " " << Q << endl;

        char _map[M][N];
        for(int i = 0; i < M; i++)
            for(int j = 0; j < N; j++)
                cin >> _map[i][j];
        
        int point[Q][2];
        for(int i = 0; i < Q; i++)
            cin >> point[i][0] >> point[i][1]; // r, c (y,x)

        for(int i = 0; i < Q; i++){
            int r = point[i][0]; //r row 
            int c = point[i][1]; //c column 
            int max = 0;

            char symbol = _map[r][c];
            int x = r, y = c;

            for(int index = 1; index < M ; index++){
                bool isSame = true;
                int x_first = x - index;
                int y_first = y - index;
                int x_last = x + index;
                int y_last = y + index;

                for(int j = x_first; j <= x_last; j++){ //from left to right 
                    if(isOutOfRange(j, y_first, M, N) OR
                        isOutOfRange(j, y_last, M, N) OR
                        _map[j][y_first] != symbol OR
                        _map[j][y_last] != symbol){
                        isSame = false;
                    }
                }

                for(int i = y_first; i < y_last; i++){ //from top to bottom 
                    if( isOutOfRange(x_first, i, M, N) OR
                        isOutOfRange(x_last, i, M, N) OR
                        _map[x_first][i] != symbol OR
                        _map[x_last][i] != symbol){
                        isSame = false;
                    }
                }
                max+= isSame ? 1 : 0;
                
            }
            

            //max is the distance between the center and the edge of the square, so we neet to multiply it by 2 and plus 1 to get the length of the side of the square
            cout << (max*2)+1 << endl;
        }

    }

}
