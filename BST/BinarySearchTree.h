// Course: CS 14 Winter 2012
//
// First Name: Sam
// Last Name: Lee
// Course username: slee103
// email address: slee103@ucr.edu
//
// Lecture Section: 001
// Lab Section: 021
// TA: Lumasag
//
// Assignment: HW5
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//
// =================================================================
#include <iostream>
#include <string>

using namespace std;

template <class KeyType, class ElementType>

typedef string KeyType;
typedef int ElementType;

class BinarySearchTree
{
	struct TreeNode
	{
		KeyType key;
		ElementType info;
		TreeNode *left, *right;
		
		public:
		
		TreeNode(KeyType newKey, ElementType newInfo,TreeNode *newLeft, TreeNode *newRight) //O(1)
			:key(newKey), info(newInfo), left(newLeft), right(newRight) {}
			
		static TreeNode* findPred(KeyType key, TreeNode *l)	//O(1)
		{
			TreeNode *left=l->left;
			while(left->right!=NULL)
			left=left->right;
		}
		
		static void swapKeyAndInfo(TreeNode *f, TreeNode *s)	//O(1)
		{
			TreeNode *temp=f;
			f->info=s->info;
			f->key=s->key;
			s->info=temp->info;
			s->key=temp->key;
		}
		
		static TreeNode *make(KeyType k, ElementType e, TreeNode *l, TreeNode *r)	//O(1)
		{
			return new TreeNode(k,e,l,r);
		}
		static TreeNode *insert(KeyType key, ElementType info, TreeNode *RootT)	//O(logn)
		{

			if(!RootT) RootT= make(key,info, NULL,NULL);
			TreeNode *t=RootT;
			while(t->key !=key)
			{
				if(key < t->key)
				{
					if(!t->left)
					t->left=make(key,info,NULL,NULL);
					cout<<t->key<<endl;
					t=t->left;
				}
				else if(key > t->key)
				{
					if(!t->left)
					t->right=make(key,info,NULL,NULL);
					cout<<t->key<<endl;
					t=t->right;
				}
				t->info = info;
				return RootT;
			}
			return RootT;
		}
		static TreeNode *find(KeyType key, TreeNode *t)	//O(logn)
		{
			cout<<1;
			while(t)
			{
				if(key < t->key) 
				t= t->left;
				else if(key > t->key) 
				t= t->right;
				else 
				return t;
			}
			//TreeNode *ret=NULL;
			//return ret;
		}
		static TreeNode *remove(KeyType key, TreeNode *t)	//O(logn)
		{
			TreeNode *toRemove = find(key,t);
			if(toRemove ->left == NULL)
			if(toRemove ->right == NULL)
			return NULL;
			
			else 
			return toRemove ->right;
			else if (toRemove ->right == NULL)
			return toRemove ->left;
			else 
			{
				TreeNode * predecessorNode = findPred(key, toRemove);
				swapKeyAndInfo(predecessorNode, toRemove);
				toRemove = remove(key, toRemove);
				return toRemove;
			}
		}
		static void print(ostream &out, TreeNode *t)	//O(N)
		{
			if(t)
			{
				print(out, t->left);
				out<< '(' <<t->key<< ','<<t->info<< ')';
				print(out, t->right);
			}
			else 
				out<<"NULL";
		}
		
		
		static void freeNode(TreeNode *t)	//O(1)
		{
			delete t;
		}
		static void freeTree(TreeNode *t)	//O(N)
		{
			if(t)
			{
				freeTree(t->left);
				freeTree(t->right);
				freeNode(t);
			}
		}
		
	};
	
	TreeNode *root;
	
	public:
	BinarySearchTree()
	{
		root=NULL;
	}
	
	void insert(KeyType key, ElementType info)	//O(logn)
	{

		root=TreeNode::insert(key,info,root);
	}
	
	KeyType find(KeyType key)	//O(logn)
	{
		TreeNode *t=TreeNode::find(key,root);
		if(!t)
		{
			insert(key, ElementType());
			t=TreeNode::find(key,root);
		}
		return t->key;
	}
	
	void remove (KeyType key)	//O(logn)
	{
		root = TreeNode::remove(key,root);
	}
	
	void print(ostream &out)	//O(N)
	{
		TreeNode::print(out,root);
	}
	
		
	
};
