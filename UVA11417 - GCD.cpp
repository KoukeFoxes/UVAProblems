#include "/Users/doeshing/development/stdc++.h"
using namespace std;

int GCD(int x, int y)
{
    return x ? GCD(y % x, x) : y;
}

int main()
{

    int N;
    while (cin >> N AND N != 0)
    {   
        int G = 0;
        for(int i = 1 ; i < N ; i++)
            for(int j = i + 1 ; j <= N ; j++)
                G += GCD(i,j);

        cout << G << endl;        
    }
}
