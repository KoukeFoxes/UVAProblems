/*
UVA 299 — Train Swapping

難度：一顆星
題目大意：
將每筆測資之數列由小到大排序，並計算交換次數。
（相當於 Bubble Sort，一次比較兩兩相鄰元素，若前者較大則交換，一輪結束後，最大元素會落在陣列尾端）
解題過程：
1. 用迴圈比較兩兩相鄰元素，若前者較大則交換，並將交換次數++
2. 最後輸出總交換次數

CPE難度：1/5

原文：
At an old railway station, you may still encounter one of the last remaining “train swappers”.
A train swapper is an employee of the railroad, whose sole job it is to rearrange the carriages of trains.
Once the carriages are arranged in the optimal order, all the train driver has to do, is drop the carriages off,
one by one, at the stations for which the load is meant.
The title “train swapper” stems from the first person who performed this task,
at a station close to a railway bridge. Instead of opening up vertically,
the bridge rotated around a pillar in the center of the river. After rotating the bridge 90 degrees,
boats could pass left or right.
The first train swapper had discovered that the bridge could be operated with at most two carriages on it.
By rotating the bridge 180 degrees, the carriages switched place, allowing him to rearrange the carriages
(as a side effect, the carriages then faced the opposite direction, but train carriages can move either way,
so who cares).
Now that almost all train swappers have died out, the railway company would like to automate their operation.
Part of the program to be developed, is a routine which decides for a given train the least number of
swaps of two adjacent carriages necessary to order the train. Your assignment is to create that routine.

Input
The input contains on the first line the number of test cases (N). Each test case consists of two input
lines. The first line of a test case contains an integer L, determining the length of the train (0 ≤ L ≤ 50).
The second line of a test case contains a permutation of the numbers 1 through L, indicating the current order of the
carriages. The carriages should be ordered such that carriage 1 comes first, then 2, etc. with carriage L coming last.

Output
For each test case output the sentence: ‘Optimal train swapping takes S swaps.’ where S is an integer.

Sample Input
3
3
132
4
4321
2
21

Sample Output
Optimal train swapping takes 1 swaps.
Optimal train swapping takes 6 swaps.
Optimal train swapping takes 1 swaps.

相關參考：
https://zerojudge.tw

*/

#include "/Users/doeshing/development/stdc++.h"

#define AND &&
#define OR ||

using namespace std;
// public variables
int counter;

vector<int> bubbleSort(vector<int> a)
{
    for (int i = 1; i < a.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[j] > a[i])
            {   //swap
                a[j] = a[i] + a[j];
                a[i] = a[j] - a[i];
                a[j] = a[j] - a[i];
                counter++;
            }
        }
    }

    return a;
}

int main()
{
    int N;
    cin >> N;
    while (N--)
    {
        counter = 0;
        int number;
        cin >> number;
        vector<int> test;
        string sentence;
        cin >> sentence;
        for (int i : sentence)
            test.push_back(i - '0');
        test = bubbleSort(test);
        // for (int i : test)
        //     cout << i << " ";
        cout << endl;
        cout << "Optimal train swapping takes " << counter << " swaps." << endl;
    }
}
