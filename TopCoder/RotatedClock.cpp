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
#include <limits.h>

using namespace std;
#define Forp( i,l ) for ( int i=0 ; i<l ; i++ )

class RotatedClock {
public:
	pair< int, int > Time( int hr, int mn )
	{
		int H,M;
		M = mn / 6;

		if ( mn % 6 )
			return make_pair( INT_MAX, INT_MAX );

		H = hr / 30;

		int rem = ( hr %30 ) * 2;

		if ( rem != M )
			return make_pair( INT_MAX, INT_MAX );

		return make_pair( H, M );
	}
	int getAngle( int cur, int mark )
	{
		cur -= mark * 30;
		return (( cur + 360 ) % 360);
	}
	string Output( int hr, int mn )
	{
		string line = "00:00";
		line[ 0 ] = (char)( hr/10 ) + '0';
		line[ 1 ] = (char)( hr%10 ) + '0';
		line[ 3 ] = (char)( mn/10 ) + '0';
		line[ 4 ] = (char)( mn%10 ) + '0';
		return line;
	}
	string getEarliest(int hr, int mn) {
		pair< int,int > ans( INT_MAX, INT_MAX );
		Forp( i,12 )
			ans = min ( ans, Time( getAngle( hr, i ), getAngle( mn,i ) ) );
		if ( ans.first == INT_MAX )
			return "";
		return Output( ans.first, ans.second );
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, int p1, bool hasAnswer, string p2) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1;
	cout << "]" << endl;
	RotatedClock *obj;
	string answer;
	obj = new RotatedClock();
	clock_t startTime = clock();
	answer = obj->getEarliest(p0, p1);
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
	
	int p0;
	int p1;
	string p2;
	
	{
	// ----- test 0 -----
	p0 = 70;
	p1 = 300;
	p2 = "08:20";
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 90;
	p1 = 120;
	p2 = "11:00";
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 240;
	p1 = 36;
	p2 = "";
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 19;
	p1 = 19;
	p2 = "";
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 1;
	p1 = 12;
	p2 = "00:02";
	all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
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
