// BinaryTreeAdt.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
using namespace std;
class Node
{
public:
	int data;
	Node* right;
	Node* left;
	Node()
	{
	 data = 0;
	 left = right = NULL;
	}
};
class BinaryTree
{
public:
	Node* root;
	
	BinaryTree()
	{
	  root = NULL;
		
	}
	
	Node* Insert(Node* ro, int item)
	{
		if (ro == NULL)
		{
			Node* newnode = new Node();
			newnode->data = item;
			ro = newnode;
		}
		else if(item > ro->data)
		{
		 ro->right = Insert(ro->right ,item);
		 
		}
		else 
		{
			ro->left = Insert(ro->left ,item);
		}

		return ro;
	}

	void Insert(int item)
	{
		root = Insert(root, item);
	}

	void preOrder(Node* ro)
	{
	 if(ro == NULL)
		 return;
	     cout << ro->data << "\t";
		 preOrder(ro->left);
		 preOrder(ro->right);
	 
	}
	void inOrder(Node* ro)
	{
		if (ro == NULL)
		 return;
		 inOrder(ro->left);
		 cout << ro->data << "\t";
		 inOrder(ro->right);
	}
	void postOrder(Node* ro)
	{
		if (ro == NULL)
		 return;
		postOrder(ro->left);
		postOrder(ro->right);
		cout << ro->data << "\t";
		
	}
	Node* Search(Node* ro, int key)
	{
		if (ro == NULL)
		{
			return NULL;
		}
		else if (ro->data == key)
		{
			return ro;
		}
		else if (ro->data > key)
		{
			return Search(ro->left, key);
		}
		else
		{
			return Search(ro->right, key);
		}
		return ro;
	}
	bool Search(int num)
	{
		Node* result = Search(root , num);
		if (result == NULL)
		{
			return false;
		}
		else
		{
		 return true;
		}
	}
	Node* FindMinimum(Node* ro)
	{
		if (ro == NULL)
			return NULL;
		else if (ro->left == NULL)
			return ro;
		else
		{
			return FindMinimum(ro->left);
		}
	}
	Node* FindMaximum(Node* ro)
	{
		if (ro == NULL)
			return NULL;
		else if (ro->right == NULL)
			return ro;
		else
		{
			return FindMinimum(ro->right);
		}
	}
	Node* Delete(Node* ro , int key)
	{
		if (ro == NULL)
			return NULL;
	 if(ro->data < key)
	 {
			ro->left = Delete(ro->left, key);
     }
	 else if(ro->data > key)
	{
		ro->right =Delete(ro->right, key);
	}
	 else
	 {
	   if (ro->left == NULL && ro->right == NULL)
	   {
		   ro = NULL;
	   }
	   else if (ro->left != NULL && ro->right == NULL)
	   {
		   ro->data = ro->left->data;
		   delete ro->left;
		   ro->left = NULL;
	   }
	   else if (ro->left == NULL && ro->right != NULL)
	   {
		   ro->data = ro->right->data;
		   delete ro->right;
		   ro->right = NULL;
	   }
	   else
	   {
		   Node * Min  = FindMinimum(ro->right);
		   ro->data = Min->data;   
		   ro->right = Delete(ro->right, Min->data);
		   return ro;
	   }
	 }


	}
};
int main()
{
    
	BinaryTree bt;
	bt.Insert(59);
	bt.Insert(29);
	bt.Insert(45);
	bt.Insert(67);
	bt.Insert(69);
	bt.Insert(56);
	bt.Insert(45);

  cout << "Displaying Tree Items\n";
  bt.preOrder(bt.root);
  cout << endl;
  //cout << "###############################################################\n";
  //bt.inOrder(bt.root);
  //cout << endl;
  //cout << "###############################################################\n";
  //bt.postOrder(bt.root);
  //cout << endl;
  //cout << "################################################################\n";
  int number;
  cout << "enter a number to search for \n";
  cin >> number;

 if (bt.Search(number))
 {
	 cout << "The Item Is Found \n";
 }
 else
 {
   cout << "The Item Is Not Found \n";
 }

 Node* Max = bt.FindMaximum(bt.root);
 Node * Min = bt.FindMinimum(bt.root);

cout << "Max Number Is " << Max->data << endl;
cout << "Minimum Number Is " << Min->data << endl; 
cout << "Displaying After deleting 29 \n";
Node* result = bt.Delete(bt.root, 29);
bt.preOrder(result);
cout << endl;
cout << "Displaying After deleting 56 \n";
result = bt.Delete(bt.root, 56);
bt.preOrder(result);
cout << endl;
 return 0;
}
