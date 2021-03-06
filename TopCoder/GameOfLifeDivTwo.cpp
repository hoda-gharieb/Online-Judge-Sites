#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;
#define Forp( i,l ) for ( int i=0 ; i<l ; i++ )

class GameOfLifeDivTwo {
public:
	string theSimulation(string init, int T) {
		string line = init;
		int ones = 0, l=init.length();
		Forp(i,T)
		{
			Forp( i, init.length() )
			{
				ones = 0;
				if ( !i )
				{
					ones += ( line[i]=='1' ? 1 : 0 );
					ones += ( line[i+1]=='1' ? 1 : 0 );
					ones += ( line[l-1]=='1' ? 1 : 0 );
				}
				else if ( i == l-1 )
				{
					ones += ( line[i]=='1' ? 1 : 0 );
					ones += ( line[0]=='1' ? 1 : 0 );
					ones += ( line[i-1]=='1' ? 1 : 0 );
				}
				else
				{
					ones += ( line[i]=='1' ? 1 : 0 );
					ones += ( line[i+1]=='1' ? 1 : 0 );
					ones += ( line[i-1]=='1' ? 1 : 0 );
				}
				if ( ones > 1 )
					init[ i ] = '1';
				else
					init[ i ] = '0';
			}
			line = init;
		}
		return init;
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, string p0, int p1, bool hasAnswer, string p2) {
	cout << "Test " << testNum << ": [" << "\"" << p0 << "\"" << "," << p1;
	cout << "]" << endl;
	GameOfLifeDivTwo *obj;
	string answer;
	obj = new GameOfLifeDivTwo();
	clock_t startTime = clock();
	answer = obj->theSimulation(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p2 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
	if (hasAnswer) {
		res = answer == p2;
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;
	
	string p0;
	int p1;
	string p2;
	
	{
	// ----- test 0 -----
	p0 = "01010";
	p1 = 2;
	p2 = "00000";
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = "010101";
	p1 = 5;
	p2 = "101010";
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = "111010";
	p1 = 58;
	p2 = "111111";
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = "111111111";
	p1 = 511;
	p2 = "111111111";
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = "110010000010111110010100001001";
	p1 = 1000;
	p2 = "110000000001111110000000000001";
	all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	p0 = "00101110011";
	p1 = 0;
	p2 = "00101110011";
	all_right = KawigiEdit_RunTest(5, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
