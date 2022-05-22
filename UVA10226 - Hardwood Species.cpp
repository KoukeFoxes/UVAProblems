/*
UVA10226 - Hardwood Species
題目大意：
美國國家資源局使用衛星影像技術來調查森林中的樹種，你的任務就是根據輸入的樹木名稱，計算各樹種所佔的百分比。
輸入說明：
輸入的第1列有一個正整數n，代表以下有多少組測試資料。空一列之後才是測試資料。
每組測試資料含有一或多列（不會超過1000000列），每列有一樹木的名稱（最多30個字元）。測試資料間有一空白列。請參考Sample input
輸出說明：
對每一組測試資料，輸出各樹種名稱（樹種不會超過10000種，按數種名稱字典順序排列）及所佔的比例（到小數點後4位）。測試資料間亦請空一列。參考Sample Output
原文：
Hardwoods are the botanical group of trees that have broad leaves, produce a fruit or nut, and generally go dormant in the winter.
America’s temperate climates produce forests with hundreds of hardwood species —trees that share certain biological characteris- tics.
Although oak, maple and cherry all are types of hardwood trees, for example, they are different species. Together, all the hard- wood species represent 40 percent of the trees in the United States.
On the other hand, softwoods, or conifers, from the Latin word meaning “cone-bearing”, have needles. Widely available US soft- woods include cedar, fir, hemlock, pine, redwood, spruce and cy- press. In a home, the softwoods are used primarily as structural lumber such as 2×4s and 2×6s, with some limited decorative appli- cations.
Using satellite imaging technology, the Department of Natural Resources has compiled an inventory of every tree standing on a particular day. You are to compute the total fraction of the tree population represented by each species.
Input
The first line is the number of test cases, followed by a blank line.
Each test case of your program consists of a list of the species of every tree observed by the satellite;
one tree per line. No species name exceeds 30 characters. There are no more than 10,000 species and no more than 1,000,000 trees.
There is a blank line between each consecutive test cases.
Output
For each test case print the name of each species represented in the population, in alphabetical order, followed by the percentage of the population it represents, to 4 decimal places.
Print a blank line between 2 consecutive test cases.
相關參考：
https://zerojudge.tw
*/

#include "bits/stdc++.h"
using namespace std;

int main() {

	string str;
	int N;
	cin >> N;
	cin.ignore();
	cin.ignore();
	

	while(N--){
		
		map<string, double> m;
		map<string, double>::iterator iter;

		int total = 0;
		while(getline(cin, str) && str != ""){
				
			m[str]++;
			total++;
		}
		
		for(iter = m.begin(); iter != m.end(); iter++)
			cout << fixed << setprecision(4) << iter->first << " " << ((iter->second)/total) * 100 << endl;

		cout << endl;
	
	}
	
}
