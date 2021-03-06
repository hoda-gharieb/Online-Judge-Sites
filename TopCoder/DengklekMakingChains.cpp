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


class DengklekMakingChains {
public:
	int maxBeauty(vector <string> chain) {
		int ans = 0, ans1 = 0, middle = 0;
		vector< string > v;
		for( int i =0 ; i<chain.size() ; i++ )
		{
			if( chain[i][ 0 ] != '.' && chain[ i ][ 1 ] != '.' && chain[ i ][ 2 ] != '.' )
			{
				for( int j=0 ; j<3 ; j++ )
					ans += chain[ i ][j ] -'0';
			}
			else if ( chain[ i ][ 0 ] == '.' && chain[ i ][ 2 ] == '.'  && chain[ i ][ 1 ] != '.' )
				middle = max( middle, chain[ i ][ 1 ] - '0' );
			else
				v.push_back( chain[ i] );

		}
		for ( int i =0 ; i<v.size() ; i++ )
		{
			if ( v[ i ][ 0 ] != '.' )
			{
				int d = v[ i ][ 0 ] - '0';
				if ( v[ i ][ 1 ] != '.' )
					d += v[ i ][ 1 ] -'0';
				int maxi = 0;
				for ( int j = 0 ; j<v.size() ; j++ )
				{
					if ( j!=i && v[j][2] !='.' )
					{
						int t = v[ j ][ 2 ] - '0';
						if ( v[ j ][ 1 ] != '.' )
							t += v[ j ][ 1 ] -'0';
						maxi = max( t,maxi );
					}
				}
				ans1 = max( ans1, maxi+d );
			}
			if ( v[ i ][ 2 ] != '.' )
			{
				int d = v[ i ][ 2 ] - '0';
				if ( v[ i ][ 1 ] != '.' )
					d += v[ i ][ 1 ] -'0';
				int maxi = 0;
				for ( int j = 0 ; j<v.size() ; j++ )
				{
					if ( j!=i && v[j][0] !='.' )
					{
						int t = v[ j ][ 0 ] - '0';
						if ( v[ j ][ 1 ] != '.' )
							t += v[ j ][ 1 ] -'0';
						maxi = max( t,maxi );
					}
				}
				ans1 = max( ans1, maxi+d );
			}
		}
		ans += ans1;
		return max( ans, middle );
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <string> p0, bool hasAnswer, int p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	DengklekMakingChains *obj;
	int answer;
	obj = new DengklekMakingChains();
	clock_t startTime = clock();
	answer = obj->maxBeauty(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p1 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p1;
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
	
	vector <string> p0;
	int p1;
	
	{
	// ----- test 0 -----
	string t0[] = {".15","7..","402","..3"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 19;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"..1","7..","567","24.","8..","234"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 36;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"...","..."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 0;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"16.","9.8",".24","52.","3.1","532","4.4","111"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 28;
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	string t0[] = {"..1","3..","2..",".7."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 7;
	all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	string t0[] = {"412","..7",".58","7.8","32.","6..","351","3.9","985","...",".46"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 58;
	all_right = KawigiEdit_RunTest(5, p0, true, p1) && all_right;
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
