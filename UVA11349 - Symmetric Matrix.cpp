/*
UVA11349 - Symmetric Matrix

現在給你一個正方形矩陣M。
M矩陣的元素為Mij：{0 < i < n，0 < j < n}。
在這個問題中，您必須找出給定的矩陣是否對稱(symmetric)。

定義：對稱矩陣所有元素都是非負的並且相對於該矩陣的中心對稱。
任何其他矩陣都被認為是非對稱的。

你要做的就是判斷這個矩陣是否對稱。
矩陣內的元素範圍為-2^32 <= Mij <= 2^32  且 0 < n <= 100。

Sample Input #1
2
N = 3
5 1 3
2 0 2
3 1 5
N = 3
5 1 3
2 0 2
0 1 5

Sample Output #1
Test #1: Symmetric.
Test #2: Non-symmetric.


原文：
You‘re given a square matrix M. Elements of this matrix are Mij : {0 < i < n,0 < j < n}.
In this problem you’ll have to find out whether the given matrix is symmetric or not.
Definition: Symmetric matrix is such a matrix that all elements of it are non-negative and symmetric with relation to the
center of this matrix. Any other matrix is considered to be non-symmetric. For
example:

    5 1 3
 M= 2 0 2
    3 1 5
issymmetric

    5 1 3
M=  2 0 2 isnotsymmetric, because 3 != 0
    0 1 5

All you have to do is to find whether the matrix is symmetric or not. Elements of a matrix given intheinputare−232 ≤Mij ≤232 and0<n≤100.
Input
First line of input contains number of test cases T ≤ 300. Then T test cases follow each described in the following way. The first line of each test case contains n – the dimension of square matrix. Then n lines follow each of then containing row i. Row contains exactly n elements separated by a space character. j-th number in row i is the element Mij of matrix you have to process.
Output
For each test case output one line ‘Test #t: S’. Where t is the test number starting from 1. Line S is equal to ‘Symmetric’ if matrix is symmetric and ‘Non-symmetric’ in any other case.

Sample Input
2 N=3 513 202 315 N=3 513 202 015

Sample Output
Test #1: Symmetric.
Test #2: Non-symmetric.

相關參考：
https://zerojudge.tw

*/

#include "/Users/doeshing/development/stdc++.h"

#define AND &&
#define OR ||

using namespace std;

int main()
{

    int cases;
    cin >> cases;
    for (int c = 1; c <= cases; c++)
    {

        int N;

        cout << "N= ";
        cin >> N;

        long long int matrix[100][100] = {0};

        // get the matrix from the input
        for (int row = 0; row < N; row++)
        {
            for (int col = 0; col < N; col++)
            {
                cin >> matrix[row][col];
            }
        }

        bool isSymmetric = true;
        int mid = int(N / 2);
        for (int row = 0; row < N; row++)
        {
            for (int col = 0; col < N , row != col; col++)
            {
                int row_ = mid + (row - mid);
                if (matrix[row][col] != matrix[N-row-1][N-col-1])
                {
                    isSymmetric = false;
                    break;
                }
            }
        }
        cout << "Tast #" << c << ": " << ((isSymmetric) ? "Symmetric" : "Non-symmetric") << "." << endl;
    }
}
