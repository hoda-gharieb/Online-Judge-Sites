#include<iostream>
#include<vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <utility>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cstring>

using namespace std;

#define mp make_pair
#define pp push_back
#define Sort(x) sort(x.begin(), x.end())
#define rep(i, x, y) for(int i = x; i < y; i++)
#define Rep(i, x, y) for(int i = x; i <= y; i++)
#define vi vector<int>
#define vvi vector<vector<int> >
#define ll long long
#define all(v) v.begin(),v.end()
#define ii pair<int, int>
#define mem(x, v) memset(x, v, sizeof(x))

int main()
{
	//freopen( "input.in", "r", stdin);
	int arr[30][101];
	int n,m;
	int numA,numB;
	
	vector<vi > query;
	while(cin>>n>>m && n && m )
	{
		mem(arr,0);
		cin>>numA;
		rep(i,0,numA)
		{
			string tmp1,tmp2;
			cin>>tmp1>>tmp2;
			stringstream ss(tmp1.substr(1));
			int nm;
			ss>>nm;
			if(tmp2=="-")
				arr[tmp1[0]-'A'][nm-1]=1;
			else
				arr[tmp1[0]-'A'][nm]=1;
		}
		bool ok = true;
		cin>>numB;
		query.clear();
		query.resize(30);
		string tmp;
		rep(i,0,numB)
		{
			cin>>tmp;
			stringstream ss(tmp.substr(1));
			int nm;
			ss>>nm;
			query[tmp[0]-'A'].pp(nm-1);
		}
		rep(i,0,30)
			sort(all(query[i]));
		rep(i,0,30)
			rep(j,0,query[i].size())
		{
			int start, end;
			start = query[ i ][j ];
			int k = j;
			while ( k+1 < query[i].size() && query[ i ][k+1 ] - query[ i ][k ] == 1 )
				k++;
			j=k;
			end = query[i][k];
			if ( end+1<m && arr[ i ][ start ] && arr[ i ][ end+1 ] )
			{
				ok = false;
				break;
			}
		}
		if(ok)
			cout<<"YES";
		else
			cout<<"NO";
		cout<<endl;
	}
}