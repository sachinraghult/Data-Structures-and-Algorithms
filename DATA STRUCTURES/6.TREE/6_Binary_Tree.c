#include <stdio.h>
#include <stdlib.h>

//These two variable and pointer declaration is for the use of Deletion operation
struct node *ROOT = NULL, *temp = NULL, *par = NULL, *child = NULL, *search = NULL;

struct node{
	int key;
	struct node *left, *right;
};

struct node* getNode(int key)
{
	struct node *newNode = (struct node*)malloc(sizeof(struct node));
	newNode->key = key;
	newNode->left = newNode->right = NULL;
	return newNode;
}

struct node* create()
{
	int key;
	printf("\nEnter data (-1 for no data) : ");
	scanf("%d",&key);
	
	if(key == -1)
		return 0;
		
	struct node *newNode = getNode(key);
	
	printf("\nEnter the key for the left of %d : \n",newNode->key);
	newNode->left = create();
	
	printf("\nEnter the key for the right of %d : \n",newNode->key);
	newNode->right = create();
	
	return newNode;
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
}

void DeleteSearch(struct node *root, int key)
{
	if(root == NULL) return;
	if(root->left->key == key || root->right->key == key)
	{
		if(root->left->key == key)
		{
		printf("\nxxxxxx\n");
		par = root;
		child = root->left;
		printf("\nyyyyyyy\n");
		}
		else if(root->right->key == key)
		{
		printf("\nxxxxxxx\n");
		par = root;
		child = root->right;
		printf("\nyyyyyyyy\n");
		}
	}
	DeleteSearch(root->left, key);
	DeleteSearch(root->right, key);
	printf("\nzzzzzzzz\n");
}

struct node* deleteNode(struct node *root, int key)
{
	printf("\naaaaaaa\n");
	if(root == NULL) return NULL;
	if(root->key == key)
	{
		if(root->left == NULL && root->right == NULL)
		{
			free(root);
			root = NULL;
		}
		else if(root->right == NULL)
		{
			temp = root;
			root = root->left;
			free(temp);
			temp = NULL;
		}
		else if(root->left == NULL)
		{
			temp = root;
			root = root->right;
			free(temp);
			temp = NULL;
		}
		else if(root->left != NULL && root->right != NULL)
		{
			temp = root;
			while(temp->left)
				temp = temp->left;
			root->key = temp->key;
			
			DeleteSearch(ROOT, temp->key);
			
			par->left = NULL;
			free(temp);temp = NULL;
		}
		return root;
	}
	printf("\nbbbbbbbb\n");
	DeleteSearch(ROOT, key);	
	printf("\ncccccccc\n");
	if(child->left == NULL && child->right == NULL)
	{
		if(par->left == child)
			par->left = NULL;
		else
			par->right = NULL;
			
		free(child);child = NULL;
	}
	
	else if(child->right == NULL)
	{
		if(par->left == child)
			par->left = par->left->left;
		else
			par->right = par->right->left;
			
		free(child);child = NULL;
	}
	
	else if(child->left == NULL)
	{
		if(par->left == child)
			par->left = par->left->right;
		else
			par->right = par->right->right;
			
		free(child);child = NULL;
	}
	
	else if(child->left != NULL && child->right != NULL)
	{
		printf("\nddddddddd\n");
		temp = child;
		while(temp->left)
			temp = temp->left;
		child->key = temp->key;
		printf("\nHiiiiii\n");
		DeleteSearch(ROOT, temp->key);
		printf("\nHelloooooo\n");
		par->left = NULL;
		printf("\nHeeeeeeeee\n");
		free(temp);temp = NULL;
		printf("\nHaaaaaaaa\n");
	}

	return ROOT;
}

void searchNode(struct node *root, int key)
{
	if(root == NULL) return;
	if(root->key == key)
		search = root;
	searchNode(root->left, key);
	searchNode(root->right, key);
}

void printPreOrder(struct node *root)
{
	if(root == NULL) return;
	printf("%d ",root->key);
	printPreOrder(root->left);
	printPreOrder(root->right);
}

void printInOrder(struct node *root)
{
	if(root == NULL) return;
	printInOrder(root->left);
	printf("%d ",root->key);
	printInOrder(root->right);
}

void printPostOrder(struct node *root)
{
	if(root == NULL) return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	printf("%d ",root->key);
}

void freeTree(struct node *node)
{
	if(node == NULL) return;
	freeTree(node->left);
	freeTree(node->right);
	free(node);
}

int main()
{
	printf("\nBINARY TREE...\n\n");
	
	struct node *root = create();
	
	int choice, key;
	
	do
	{
		printf("\n1. Insert\t2. Delete\t3. Search\t4. Inorder Dispaly\n");
		printf("5. PreOrder Traversal\t6. PostOrder Traversal\t7. FreeTree\n");
		
		printf("Enter the choice (0 to Exit) : ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 0:
				break;
			case 1:
				printf("\nEnter the key to be inserted : ");
				scanf("%d",&key);
				root = insertNode(root, key);
				printf("Node with %d is inserted successfully \n",key);
				break;
				
			case 2:
				printf("\nEnter the key to be deleted : ");
				scanf("%d",&key);
				ROOT = root;
				root = deleteNode(root, key);
				printf("Node with %d is deleted successfully \n",key);
				break;
				
			case 3:
				printf("\nEnter the key to be searched : ");
				scanf("%d",&key);
				
				searchNode(root, key);
				
				if(search)
					printf("Node with %d is found \n",key);
				else
					printf("Node with %d is not found \n",key);
				search = NULL;
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
				freeTree(root);
				root = NULL;
				printf("\nThe Binary Tree is made free and destroyed \n");
				break;
				
			default:
				printf("Invalid choice \n");
		}
	}while(choice != 0);
	
	freeTree(root);
	printf("\nThe BINARY TREE is made free and destroyed ...\nEND OF THE PROGRAM\n");
	
	return 0;
}
