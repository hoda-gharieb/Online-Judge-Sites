#include<iostream>
using namespace std;
int main()
{
	int n, i, j, round;
	while ( cin>>n>>i>>j )
	{
		round = 1;
		int a, b;
		while ( round < n )
		{
			a = ( i/2 ) + ( i%2 );
			b = ( j /2 ) + ( j%2);
			i = a; j = b;
			if ( a == b )
				break;
			round++;
		}
		cout<<round<<endl;
	}
}