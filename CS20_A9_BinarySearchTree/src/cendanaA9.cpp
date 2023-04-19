#include <iostream>
using namespace std;

struct Treenode
{
	int nodeValue;
	int bf;
	Treenode * Lchild;
	Treenode * Rchild;
};

class BST
{
private:
	Treenode * root;

	void traverseInOrderInternal(Treenode *);		// internal functions - all by subtree
	void traversePreOrderInternal(Treenode *);
	void traversePostOrderInternal(Treenode *);
	bool traverseLevelOrderInternal(Treenode* node, int);
	void print2DInternal(Treenode *, int);

	void deleteInternal (Treenode * &);				// internal delete function

	int heightInternal(Treenode *);					// internal BF functions
	void setallBFInternal(Treenode *);
	int getLargestBFInternal(Treenode*);

public:
	BST();
	void insert (int &);				// user functions - all whole tree
	bool search (int &);
	void udelete (int &);

	void setallBF();					// sets BF for whole tree
	int height();						// height of whole tree
	int getLargestBF();					// largest BF in whole tree

	void traverseLevelOrder();			// traversal functions
	void print2D();
	void traverseInOrder();
	void traversePreOrder();
	void traversePostOrder();
};

BST::BST()
{
	root = nullptr;
}
//********************************************************
// user search - search, given a value
//********************************************************
bool BST::search(int & value)
{
	Treenode* current;
	bool found = false;
	if (root == nullptr)
	{
		cout << "search: tree is empty" << endl;
		exit (1);
	}
	else
	{
		current = root;
		while (current != nullptr && !found)
		{
			if (current->nodeValue == value)
			{
				found = true;
			}
			else if (current->nodeValue > value)
			{
				current = current->Lchild;
			}
			else
			{
				current = current->Rchild;
			}
		}
	}
	return found;
}
//********************************************************
// user insert - insert, given a value
//********************************************************

void BST::insert(int & value)
{
	//initialize user created node
	Treenode *target = new Treenode;
	target->nodeValue = value;
	target->bf = 0;
	target->Lchild = nullptr;
	target->Rchild = nullptr;

	//create temp to track position
	Treenode *current = new Treenode;
	current = root;

	//if tree is empty, must make a new tree
	if (root == nullptr)
	{
		cout << "insert: root is null, making new tree " << endl;
		root = target;
	}
	else
	{
		//if value is already in tree
		if (search(value) == true)
		{
			cout << "insert: node with value of " << value << " already exists - terminating program ";
			exit(1);
		}
		while (current != nullptr)
		{
			if (value < current->nodeValue)
			{
				if (current->Lchild == nullptr)
				{
					current->Lchild = target;
					return;
				}
				else
					current = current->Lchild;
			}
			else if (value > current->nodeValue)
			{
				if (current->Rchild == nullptr)
				{
					current->Rchild = target;
					return;
				}
				else
					current = current->Rchild;
			}
		}
	}
}


//********************************************************
// user delete - delete, given a value
//********************************************************
void BST::udelete(int & value)
{
	Treenode * current; 		// pointer to node we're looking at
	Treenode * trailing; 		// trailing pointer to parent

	bool found = false;
	if (root == NULL)
	{
		cout << "udelete:  empty tree" << endl;
		exit (1);
	}
	else
	{
		current = root;
		trailing = root;
		while (current != nullptr && !found)
		{
			if (current->nodeValue == value)
			{
				found = true;
			}
			else
			{
				trailing = current;
				if (current->nodeValue > value)
				{
					current = current->Lchild;
				}
				else
				{
					current = current->Rchild;
				}
			}
		}
		if (current == nullptr)
		{
			cout << "udelete:  not found" << endl;
		}
		else if (found)
		{
			if (current == root)
			{
				deleteInternal(root);
			}
			else if (trailing->nodeValue > value)
			{
				deleteInternal(trailing->Lchild);
			}
			else
			{
				deleteInternal(trailing->Rchild);
			}
		}
	}
}
//********************************************************
// internal delete - delete, given the pointer to node to delete that is physically
// located in the node's parent as Lchild or Rchild
//********************************************************
void BST::deleteInternal (Treenode * &p)
{
	Treenode * current;			// pointer to node we're looking at
	Treenode * trailing;		// trailing pointer to parent
	Treenode * temp;			// temp pointer for delete

	if (p == nullptr)
	{
		cout << "delete: null node" << endl;
		exit(1);
	}
	else if(p->Lchild == nullptr && p->Rchild == nullptr)
	{
		temp = p;
		p = nullptr;
		delete temp;
	}
	else if(p->Lchild == nullptr)
	{
		temp = p;
		p = temp->Rchild;
		delete temp;
	}
	else if(p->Rchild == nullptr)
	{
		temp = p;
		p = temp->Lchild;
		delete temp;
	}
	else
	{
		current = p->Lchild;
		trailing = nullptr;
		while (current->Rchild != nullptr)
		{
			trailing = current;
			current = current->Rchild;
		}
		p->nodeValue = current->nodeValue;
		if (trailing == NULL)
		{
			p->Lchild = current->Lchild;
		}
		else
		{
			trailing->Rchild = current->Lchild;
		}
		delete current;

	}
}
//********************************************************
// user traversal functions
//********************************************************
void BST::traverseInOrder()
{
	traverseInOrderInternal(root);
}
void BST::traversePreOrder()
{
	traversePreOrderInternal(root);
}
void BST::traversePostOrder()
{
	traversePostOrderInternal(root);
}
void BST::print2D()
{
    print2DInternal(root, 0);
}
void BST::traverseLevelOrder()
{
    int level = 1;
    while (traverseLevelOrderInternal(root,level))
    {
    	cout << endl;
        level++;
    }
}
//********************************************************
// internal traversal functions
//********************************************************
void BST::traverseInOrderInternal(Treenode * p)
{
	if (p == nullptr)
	{
//		cout << "enter inorder with null" << endl;
	}
	else
	{
//		cout << "enter inorder " << p ->nodeValue << endl;
	}
	if (p != nullptr)
	{
		traverseInOrderInternal(p->Lchild);
		cout << p->nodeValue << endl;
		traverseInOrderInternal(p->Rchild);
	}
}

void BST::traversePreOrderInternal(Treenode * p)
{
	if (p != nullptr)
	{
		cout << p->nodeValue << endl;
		traversePreOrderInternal(p->Lchild);
		traversePreOrderInternal(p->Rchild);
	}
}

void BST::traversePostOrderInternal(Treenode * p)
{
	if (p != nullptr)
	{
		traversePostOrderInternal(p->Lchild);
		traversePostOrderInternal(p->Rchild);
		cout << p->nodeValue << endl;
	}
}

bool BST::traverseLevelOrderInternal(Treenode * p, int level)
{
    if (p == nullptr)
        return false;
    if (level == 1)
    {
    	cout << p->nodeValue << "   ";
    	return true;
    }
    bool l = traverseLevelOrderInternal(p->Lchild, level-1);
    bool r = traverseLevelOrderInternal(p->Rchild, level-1);
    return l || r;
}
// internal recursive function, called by print2D
// does a reverse inorder traversal to display top to bottom
void BST::print2DInternal(Treenode *root, int space)
{
	int count=8;
    if (root == NULL)
        return;
    space += count;
    print2DInternal(root->Rchild, space);	// process right (top of page)
    cout<<endl;								// display node after spacing
    for (int i = count; i < space; i++)
        cout<<" ";
    cout<<root->nodeValue<<"("<<root->bf<<")"<<"\n";
    print2DInternal(root->Lchild, space);	// process left (bottom of page)
}
//********************************************************
// user BF functions
//********************************************************
// user height - sets the BF for each node

int BST::height()
{
	return heightInternal(root);
}
// user setallBF - sets the BF for all nodes in the tree
void BST::setallBF()
{
	Treenode* node = new Treenode;
	node = root;
	setallBFInternal(node);
}

// user BF - returns the largest balance factor in the tree
int BST::getLargestBF()
{
	return getLargestBFInternal(root);
}

//********************************************************
// internal BF functions
//********************************************************
// heightInternal - recursive function,
// returns height of a subtree given its root

int BST::heightInternal(Treenode* p)
{
	if (p != nullptr)
	{
		int lh, rh;
		lh = heightInternal(p->Lchild);
		rh = heightInternal(p->Rchild);
		if (lh > rh)
		{
			lh++;
			return lh;
		}
		else
		{
			rh++;
			return rh;
		}
	}
	else
	{
		return -1;
	}
}

// setallBFinternal - recursive function,
// calculates the bf of a node and its subtrees
void BST::setallBFInternal(Treenode* node)
{
	//case 1: empty tree
	if (node == nullptr)
	{
		cout << "setallFInternal: tree is empty" << endl;
		return;
	}

	//case 2: reached a leaf - you're done :)
	if (node->Lchild == nullptr and node->Rchild == nullptr)
	{
		node->bf = 0;
		return;
	}

	//case 3a: current has left child
	if (node->Lchild != nullptr)
	{
		node->bf = (heightInternal(node->Rchild) - heightInternal(node->Lchild));
		setallBFInternal(node->Lchild);
	}

	//case 3b: current has right child
	if (node->Rchild != nullptr)
	{
		node->bf = (heightInternal(node->Rchild) - heightInternal(node->Lchild));
		setallBFInternal(node->Rchild);
	}
}
// getlargestBFInternal - recursive function,
// returns largest BF in the given subtree
int BST::getLargestBFInternal(Treenode* node)
{
	if (node != nullptr)
	{
		int l = getLargestBFInternal(node->Lchild);
		int r = getLargestBFInternal(node->Rchild);

		if (abs(node->bf) > abs(l))
		{
			//cout <<" l = " << node-> bf << endl;
			l = node->bf;
		}
		else if (abs(node->bf) > abs(r))
		{
			//cout <<" r = " << node-> bf << endl;
			r = node->bf;
		}

		if (abs(l) > abs(r))
		{
			//cout << "l: " << abs(l) << " is greater than r: " << abs(r) << endl;
			return l;
		}
		else
			//cout << "r: " << abs(l) << " is greater than l: " << abs(r) << endl;
			return r;
	}
	else
		return 0;
}


int main() {
//Paul Hrycewitz's Test Code (Copy Pasted)
	BST mytree;
	int i;
	bool b;

/* start with this small tree and test code
// will be easier to debug
	i=5;
	mytree.insert(i);
	i=8;
	mytree.insert(i);
	i=3;
	mytree.insert(i);
	i=12;
	mytree.insert(i);
	i=9;
	mytree.insert(i);
	mytree.print2D();
	mytree.setallBF();
	cout << "-------------------------------------------" << endl;
	mytree.print2D();
	cout <<" largest BF " << mytree.getLargestBF() << endl;
	i = 9;
	b = mytree.search(i);
	if (b)
		cout << "search for 9 successful" << endl;
	else
		cout << "search for 9 not successful" << endl;
	return 0;
*/

// use this code and tree when the small tree is working
	int array[14] = {60,50,70,30,53,80,35,57,75,32,40,77,48,45};
	for (int i=0;i<14;i++)
	{
		mytree.insert(array[i]);
	}



/*
	cout << "traverse inorder" << endl;
	mytree.traverseInOrder();
	cout << "traverse preorder" << endl;
	mytree.traversePreOrder();
	cout << "traverse postorder" << endl;
	mytree.traversePostOrder();
*/
	mytree.print2D();
	cout << "-------------------------------------------" << endl;
	mytree.setallBF();
	mytree.print2D();
	cout <<" largest BF " << mytree.getLargestBF() << endl;
	cout << "-------------------------------------------" << endl;
	i = 46;
	mytree.insert(i);
	i = 47;
	mytree.insert(i);
	mytree.setallBF();
	mytree.print2D();
	cout <<" largest BF " << mytree.getLargestBF() << endl;
	cout << "-------------------------------------------" << endl;
	i=45;
	mytree.udelete(i);
	mytree.setallBF();
	mytree.print2D();
	cout <<" largest BF " << mytree.getLargestBF() << endl;	//
	i = 53;
	b = mytree.search(i);
	if (b)
		cout << "search for 53 successful" << endl;
	else
		cout << "search for 53 not successful" << endl;
	return 0;

}
