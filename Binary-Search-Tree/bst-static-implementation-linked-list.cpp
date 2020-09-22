#include<vector> 
#include<cstdlib>
#include<climits>
#include<iostream>
using namespace std;


const int INF = 1e9; // need a constant that mark as empty node

struct node
{
	int val;
	int left;
	int right;
};

struct bst
{
	int actual_size = 0;
	vector < node > arr;

	void insert(int value)
	{
		int it = 0;
		if(arr.empty())
			arr.push_back({value, -INF, -INF});
		else
			while(true)
			{
				if( arr[it].val < value)
				{
					if( arr[it].right == -INF)
					{
						arr[it].right = (int)arr.size();
						arr.push_back({value, -INF, -INF});
						break;
					}
					else it = arr[it].right;
				}
				else
				{
					if( arr[it].left == -INF)
					{
						arr[it].left = (int)arr.size();
						arr.push_back({value, -INF, -INF});
						break;
					}
					else it = arr[it].left;
				}
			}
	}

	void in_order(int it)
	{
		if(arr.empty())
			return;
		if( arr[it].left != -INF)
			in_order( arr[it].left);

		cout<<arr[it].val<<" ";

		if( arr[it].right != -INF)
			in_order( arr[it].right);

		return;
	}



};

bst tree;
int main() /// fixed GNU GCC 9.3 
{
	int arr[] = {5,2,1,7,9,3};
	int size = sizeof(arr) / sizeof(arr[0]);
	/// Create the list of tree

	// insertion
	for(int c = 0; c < size; c++)
		tree.insert(arr[c]);

	/*
	this block is only for  watch the algorithm running
	for(int c = 0; c<tree.actual_size; c++)
		cout<<tree.arr[c].val<<" "<<tree.arr[c].left<<" "<<tree.arr[c].right<<"\n";*/

	tree.in_order(0); /// this function print the tree in order, always start in the 0 position
}
