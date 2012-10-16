#include <iostream>

using namespace std;
template <class KeyType, class ElementType>

class TreeNode
{
	KeyType key;
	ElementType info;
	TreeNode *left, *right;
	
	public:
	
	TreeNode(KeyType newKey, ElementType newInfo,TreeNode *newLeft, TreeNode *newRight)
		:key(newKey), info(newInfo), left(newLeft), right(newRight) {}
	
	TreeNode *make(KeyType k, ElementType e, TreeNode *l, TreeNode *r)
	{
		return new TreeNode(k,e,l,r);
	}
	TreeNode *insert(KeyType key, ElementType info, TreeNode *RootT)
	{
		if(!RootT) RootT= make(key,info, NULL,NULL);
		TreeNode *t=RootT;
		while(t->key !=key)
		{
			if(key < t->key)
			{
				if(!t->left)
				t->left=make(key,info,NULL,NULL);
				t=t->left;
			}
			else if(key > t->key)
			{
				if(!t->left)
				t->right=make(key,info,NULL,NULL);
				t=t->right;
			}
			t->info = info;
			return RootT;
		}
	}
	TreeNode *find(KeyType key, TreeNode *t)
	{
		while(t)
		{
			if(key < t->key) t= t->left;
			else if(key > t->key) t= t->right;
			else return t->info;
		}
		error (key, "not found");
	}
	TreeNode *remove(KeyType key, TreeNode *t)
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
	void print(ostream &out, TreeNode *t)
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
	static void freeNode(TreeNode *t)
	{
		delete t;
	}
	static void freeTree(TreeNode *t)
	{
		if(t)
		{
			freeTree(t->left);
			freeTree(t->right);
			freeNode(t);
		}
	}
	
};
