#include<bits/stdc++.h>
using namespace std;

typedef long long int  ll;

void input()
{
	ofstream inputs;
	inputs.open("input.txt",ios::out );

	if( inputs.fail() ) 
		return;
	ll n = rand();

	inputs << n<<"\n";
	for(int c = 0; c<n; c++ ) 
		inputs << rand() <<" ";
	inputs.close();
	return;

}

main()
{
	srand(time(NULL) );
	input();
	
	// -- this is only a test --- 
}

