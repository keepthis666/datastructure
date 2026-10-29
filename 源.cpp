#include<stdio.h>
#include<stdlib.h>
typedef struct tree
{
	char val;
	struct tree* left;
	struct tree* right;
}tree;
typedef struct BST
{
	int data;
	struct BST* leftc;
	struct BST* rightc;
}BST;
int index = 0;
void createTree(tree** root,char arr[])
{
	char key = arr[index++];
	if (key == '#')
	{
		*root = NULL;//读到空记得赋值成空的
		return;
	}
	else {
		*root = (tree*)malloc(sizeof(tree));
		(*root)->val = key;
		createTree(&(*root)->left,arr);
		createTree(&(*root)->right,arr);
	}
}
void preOrder(tree* root)
{
	if (root == NULL)
	{
		return;
	}
	else {
		printf("%c", root->val);
		preOrder(root->left);
		preOrder(root->right);
	}

}
void midOrder(BST* root)
{
	if (root == NULL)
	{
		return;
	}
	else {
		midOrder(root->leftc);
		printf("%d ", root->data);
		midOrder(root->rightc);
	}

}
void insert(BST** root, int x)
{
	if (*root == NULL)
	{
		BST* temp = (BST*)malloc(sizeof(BST));
		temp->data = x;
		temp->leftc = NULL;
		temp->rightc = NULL;
		*root = temp;
	}
	else {
		if(x<(*root)->data) insert(&((*root)->leftc), x);
		if(x>(*root)->data) insert(&((*root)->rightc), x);
	}

}
int search(BST* root, int x)
{
	if (root == NULL)
	{
		return 0;
	}
	else {
		while (root) {
			if (root->data == x)
			{
				return 1;
			}
			else
			{
				if (x > root->data) root = root->rightc;
				if (x < root->data) root = root->leftc;
			}
		}
	}
	return 0;

}
BST* deletenode(BST* root, int x)
{
	if (root == NULL)
	{
		return NULL;
	}
	else {
		if (x > root->data) root->rightc = deletenode(root->rightc, x);
		if (x < root->data) root->leftc = deletenode(root->leftc, x);
		if (x == root->data)
		{
			if (root->leftc == NULL && root->rightc == NULL)
			{
				BST* temp = root;
				free(root);
				temp = NULL;
				return temp;
			}
			if (root->leftc != NULL && root->rightc == NULL)
			{
				BST* temp = root->leftc;
				free(root);
				return temp;
			}
			if (root->leftc == NULL && root->rightc != NULL)
			{
				BST* temp = root->rightc;
				free(root);
				return temp;
			}
			if (root->leftc != NULL && root->rightc != NULL)
			{
				BST* cur = root->leftc;
				while (cur->rightc) cur = cur->rightc;//这里格外小心，直接写cur，cur会到null，直接无了，必须停留在上一个节点
				cur->rightc = root->rightc;
				BST* temp = root->leftc;
				free(root);
				return temp;
			}
		}
		

	}
    return root;//最后没找到节点，就返回头就行了
}

int main()
{
	char arr[] = "ABD###CE##F##";
	tree* root=NULL;
	createTree(&root, arr);
	BST* t = NULL;
	insert(&t, 1);
	insert(&t, 2);
	insert(&t, 3);
	insert(&t, 4);
	insert(&t, 45);
	insert(&t, 56);
	insert(&t, 89);
	//int result = search(t,2);
	t = deletenode(t, 2);

	midOrder(t);
}