#include <stdio.h>
#include <stdlib.h>

struct node{
	int key;
	struct node *left, *right;
	int height;
};

struct node* getNode(int key)
{
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode->key = key;
	newNode->left = newNode->right = NULL;
	newNode->height = 1;
	return newNode;
}

int height(struct node *node)
{
	if(node == NULL)
		return 0;
	return node->height;
}

int getBalance(struct node *node)
{
	if(node == NULL)
		return 0;
	return height(node->left) - height(node->right);
}

int max(int a, int b)
{
	return (a > b) ? a : b;
}

struct node* rightRotate(struct node *y)
{
	struct node *x = y->left;
	struct node *t = x->right;
	
	x->right = y;
	y->left = t;
	
	y->height = 1 + max(height(y->left) , height(y->right));
	x->height = 1 + max(height(x->left) , height(x->right));
	
	return x;
}

struct node* leftRotate(struct node *x)
{
	struct node *y = x->right;
	struct node *t = y->left;
	
	y->left = x;
	x->right = t;
	
	x->height = 1 + max(height(x->left) , height(x->right));
	y->height = 1 + max(height(y->left) , height(y->right));
	
	return y;
}

struct node* insertNode(struct node* node, int key)
{
	if(node == NULL)
		return getNode(key);
		
	if(key < node->key)
		node->left = insertNode(node->left, key);
	else if(key > node->key)
		node->right = insertNode(node->right, key);	
	else
		return node;
	
	node->height = 1 + max(height(node->left),height(node->right));
	
	int balance = getBalance(node);
	
	if(balance > 1 && key < node->left->key)
		return rightRotate(node);
	if(balance < -1 && key > node->right->key)
		return leftRotate(node);
	if(balance > 1 && key > node->left->key)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}
	if(balance < -1 && key < node->right->key)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}
	
	return node;
}

struct node* deleteNode(struct node* root, int key)
{ 
	struct node *succparent = NULL, *succ = NULL;
	
	if(root == NULL) return root;
		
	if(key < root->key)
	{
		root->left = deleteNode(root->left, key);
		return root;
	}
	else if(key > root->key)
	{
		root->right = deleteNode(root->right, key);
		return root;
	}
	
	if(root->left == NULL)
	{
		struct node *temp = root->right;
		free(root);
		return temp;
	}
	else if(root->right == NULL)
	{
		struct node *temp = root->left;
		free(root);
		return temp;
	}
	else
	{
		succparent = root, succ = root->right;
		
		while(succ->left != NULL)
		{
			succparent = succ;
			succ = succ->left;
		}
		
		if(succparent != root)
			succparent->left = succ->right;
		else
			succparent->right = succ->right;
		
		root->key = succ->key;
		
		free(succ);succ = NULL;
		return root;
	}
    
    
    if (root == NULL)
    	return root;
    
	root->height = 1 + max(height(root->left),height(root->right));
	
	int balance = getBalance(root);
	
	if(balance > 1 && getBalance(root->left) >= 0)
		return rightRotate(root);
	if(balance > 1 && getBalance(root->left) < 0)
	{
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}
	if(balance < -1 && getBalance(root->left) <= 0)
		return leftRotate(root);
	if(balance < -1 && getBalance(root->left) > 0)
	{
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}
}

struct node* searchNode(struct node* node, int key)
{
	if(node == NULL || node->key == key)
		return node;
		
	if(key < node->key)
		return searchNode(node->left, key);
	else if(key > node->key)
		return searchNode(node->right, key);	
}

void printPreOrder(struct node *root)
{
	if(root != NULL)
	{
		printf("%d ",root->key);
		printPreOrder(root->left);
		printPreOrder(root->right);
	}
}

void printInOrder(struct node *root)
{
	if(root != NULL)
	{
		printInOrder(root->left);
		printf("%d ",root->key);
		printInOrder(root->right);
	}
}

void printPostOrder(struct node *root)
{
	if(root != NULL)
	{
		printPostOrder(root->left);
		printPostOrder(root->right);
		printf("%d ",root->key);
	}
}

void freeTree(struct node *node)
{
	if(node == NULL) return;
	
	freeTree(node->left);
	freeTree(node->right);
	free(node);
}

void menuCard()
{
	printf("\n\nEnter the choice from the below menu card to perform that operation (Enter 0 to exit) : \n");
	printf("1. insertNode() \n");
	printf("2. deleteNode() \n");
	printf("3. searchNode() \n");
	printf("4. printPreOrder() \n");
	printf("5. printInOrder() \n");
	printf("6. printPostOrder() \n");
	printf("7. print Pre, In, Post Order \n");
	printf("8. freeTree() \n");
}

int main()
{
	int choice, key;
	struct node *root = NULL, *temp = NULL;
	
		printf("\nEnter the key for root node to be created in the BST : ");
		scanf("%d",&key);
		root = insertNode(root, key);
		printf("Root node with %d is created successfully \n",key);
	
	do
	{
		menuCard();
		scanf("%d",&choice);
				
		switch(choice)
		{
			case 1:
				printf("\nEnter the key to be inserted in the BST : ");
				scanf("%d",&key);
				root = insertNode(root, key);
				printf("Node with %d is inserted successfully \n",key);
				break;
			case 2:
				printf("\nEnter the key to be deleted in the BST : ");
				scanf("%d",&key);
				root = deleteNode(root, key);
				printf("Node with %d is deleted successfully \n",key);
				break;
			case 3:
				printf("\nEnter the data to be searched in the BST : ");
				scanf("%d",&key);
				
				temp = searchNode(root, key);
				
				if(temp != NULL)
					printf("Node with %d is found at %d \n", key, temp);
				else
					printf("Node with %d is not found \n");
				break;
			case 4:
				printf("\nPreOrder Display : \n");
				printPreOrder(root);
				break;
			case 5:
				printf("\nInOrder Display : \n");
				printInOrder(root);
				break;
			case 6:
				printf("\nPostOrder Display : \n");
				printPostOrder(root);
				break;
			case 7:
				printf("\nPreOrder Display : \n");
				printPreOrder(root);
				printf("\nInOrder Display : \n");
				printInOrder(root);
				printf("\nPostOrder Display : \n");
				printPostOrder(root);
				break;
			case 8:
				freeTree(root);
				root = NULL;
				printf("\nThe BST is made free and destroyed \n");
				break;
		}
		
	}while(choice != 0);
	
	freeTree(root);
	printf("\nThe BST is made free and destroyed ...\nEND OF THE PROGRAM\n");
	
	return 0;
}
