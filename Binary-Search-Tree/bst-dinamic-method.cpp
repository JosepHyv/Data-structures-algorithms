#include<cstdlib>
#include<iostream>
using namespace std;

struct bst
{
	int value;
	bst* left;
	bst* right;
};


bst* create( int val)
{
	bst* nuevo = new bst();
	nuevo -> value = val;
	nuevo -> left = NULL;
	nuevo -> right = NULL;
	return nuevo;
}

bst* insert ( bst* root, int val)
{
	if( root == NULL)
		return root = create( val);

	if( val > root -> value )
		 root -> right = insert( root -> right, val);
	else
		 root -> left = insert( root -> left, val);

	return root;
}

void in_orden(bst* root)
{
	if( root != NULL)
	{
		in_orden( root -> left );
		cout<< root -> value<<" ";
		in_orden( root -> right);
	}

}



int main() 
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	int vx[] = {2,1,9,6,7,10,3,27,53,7};
	int size = sizeof(vx) / sizeof(vx[0]);

	bst* tree = NULL; // create your bst in this case is named "tree"
	

	for(int c = 0 ; c<size; c++)
	{
		tree = insert( tree, vx[c]);
	}


	in_orden(tree);

}