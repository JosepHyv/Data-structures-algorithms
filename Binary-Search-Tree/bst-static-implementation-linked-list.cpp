#include<cstdlib>
#include<climits>
#include<iostream>
using namespace std;


const int INF = ( 1 << 30 ); // need a constant that mark as empty node

struct node
{
	int val = INF;
	int left = INF;
	int right = INF;
};

struct bst
{
	node* arr;
	int actual_size = 0;
	void create(int size)
	{
		arr = new node[size+3];
		return;
	}

	void erasing()
	{
		/// warning, this function only free memory
		/// No erase nodes;
		delete[] arr;
		return;
	}

	void insert(int value)
	{
		int it = 0;
		while( true )
		{
			if( arr[it].val == INF)
			{
				arr[it].val = value;
				actual_size++;
				break;
			}
			else
			{
				if( value < arr[it].val)
				{
					if( arr[it].left == INF)
					{
						arr[actual_size].val = value;
						arr[it].left = actual_size;
						actual_size++;
						break;
					}
					else
						it = arr[it].left;
				}
				else
				{
					if(arr[it].right == INF)
					{
						arr[actual_size].val = value;
						arr[it].right = actual_size;
						actual_size++;
						break;
					}
					else
						it = arr[it].right;
				}
			}
		}

	}

	void in_order(int it)
	{
		if( arr[it].left != INF)
			in_order( arr[it].left);

		cout<<arr[it].val<<" ";

		if( arr[it].right != INF)
			in_order( arr[it].right);

		return;
	}



};

bst tree;
main()
{
	int arr[] = {5,2,1,7,9,3};
	int size = sizeof(arr) / sizeof(arr[0]);
	/// Create the list of tree
	tree.create( size+1 );
	// insertion
	for(int c = 0; c < size; c++)
		tree.insert(arr[c]);

	/*
	this block is only for  watch the algorithm running
	for(int c = 0; c<tree.actual_size; c++)
		cout<<tree.arr[c].val<<" "<<tree.arr[c].left<<" "<<tree.arr[c].right<<"\n";*/

	tree.in_order(0); /// this function print the tree in order, always start in the 0 position
	tree.erasing();
}
