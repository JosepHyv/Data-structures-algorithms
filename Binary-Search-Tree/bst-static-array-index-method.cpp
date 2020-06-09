#include<climits>
#include<stdlib.h>
#include<iostream>
using namespace std;

const int INF = ( 1 << 30); // need a constant that mark as empty node
struct node
{
	int i = INF, d = INF;
};

struct bst
{
	node* vx;
	void create( int size)
	{
		vx = new node[size+2];
		return;
	}
	void eraser()
	{
		delete[] vx;
		return;
	}
	void insert( int root, int value)
	{
		if( value < root)
		{
			if( vx[root].i == INF)
				vx[root].i = value;
			else
				insert( vx[root].i, value);
		}
		else
		{
			if( vx[root].d == INF)
				vx[root].d = value;
			else
				insert(vx[root].d, value);
		}
		return;
	}

	void in_order(int root)
	{
		if( vx[root].i != INF)
			in_order(vx[root].i);

		cout<<root<<" ";

		if( vx[root].d != INF)
			in_order(vx[root].d);

		return;
	}
};

bst tree;

int main () /// fixed GNU GCC 9.3 
{
	int arr[] = {5,2,1,7,9,3};
	int size = sizeof(arr) / sizeof(arr[0]);
	/// the most higth element that the tree suport is the max in the array
	int max_element = 0;
	for(int c = 0; c<size; c++)
		max_element = max( max_element, arr[c]);
	/// Create the array of tree
	tree.create( max_element+1 );
	// insertion
	for(int c = 1; c < size; c++)
		tree.insert(arr[0],arr[c]);

	tree.in_order(arr[0]);
	tree.eraser();
}
