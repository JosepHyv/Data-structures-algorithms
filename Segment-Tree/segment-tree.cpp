#include<cstdlib>
#include<climits>
#include<iostream>
using namespace std;

/// simple  sum in range segment tree

typedef long long ll;

ll* st;

void create( int size )
{
	st = new  ll[(4*size)+2]; /// this array can be a static array with 4 times the number of elements
	return;
}

ll build ( int node, int i, int f, auto array[])
{
	if( i == f)
		return st[node] = array[f];
	int mid = ( i+f )/2;
	return st[node] = build(node*2, i, mid, array) + build( (node*2)+1, mid+1, f, array);	
}

ll query( int node, int i, int f, int li, int ld)
{
	// check if they query isn't into the range
	if( i > ld || f < li)
		return 0;
	/// if we query is into the range
	if( i >= li && f <= ld)
		return st[node];

	int mid = ( i+f )/2;
	return query( node*2, i, mid, li, ld) + query( ( node*2)+1, mid+1, f, li, ld);
}

/// only  puntual update, NO update by range ( lazy propagation update )  

void update( int node, int i, int f, int pos, int val, auto array[])
{
	if( i == f)
	{
		st[node] = val;
		array[pos] = val; // the update in the original array is optional
		/// the update in the original array run in O(1) because is only point in the position and update
	}
	else
	{
		int mid = ( i+f )/2;
		if( i <= pos  && pos <= mid)	
			update(node*2, i, mid, pos, val, array);
		else
			update( ( node*2)+1, mid+1, f, pos, val, array);
		// this function should be re-build the tree
		st[node] = st[node*2] + st[(node*2)+1];
	}
	return;
}

main()
{
	///ios_base::sync_with_stdio(false); cin.tie(NULL); optimize standar input
	int vx[] = {1,2,3,4,5,6,7,8,9,0};
	int array_size = sizeof(vx) / sizeof(vx[0]);

	create( array_size);
	build(1, 0, array_size-1, vx);
	/*
		example querys
		0 4
		4 7
		1 3
		0 8
	*/

	cout<<" ---------respuestas antes de las updates ------\n";
	cout<< query( 1, 0, array_size-1, 0, 4)<<"\n";
	cout<< query( 1, 0, array_size-1, 4, 7)<<"\n";
	cout<< query( 1, 0, array_size-1, 1, 3)<<"\n";
	cout<< query( 1, 0, array_size-1, 0, 8)<<"\n";

	/*
		example updates
		3 7
		1 9
		0 12
	*/
	update(1, 0, array_size-1, 3, 7, vx);
	update(1, 0, array_size-1, 1, 9, vx);
	update(1, 0, array_size-1, 0, 12, vx);

	cout<< "---------respuestas despues de las updates-----------\n";
	/// print querys again
	cout<< query( 1, 0, array_size-1, 0, 4)<<"\n";
	cout<< query( 1, 0, array_size-1, 4, 7)<<"\n";
	cout<< query( 1, 0, array_size-1, 1, 3)<<"\n";
	cout<< query( 1, 0, array_size-1, 0, 8)<<"\n";

	delete[] st;

	/// --- now, enjoy (: 



}