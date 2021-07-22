#include <stdio.h>                      //Error in deletion alone, please try to rectify it
#include <stdlib.h>

//These two variable and pointer declaration is for the use of Deletion operation
static int boolVar = 0;
struct node *ROOT = NULL, *temp = NULL, *par = NULL;

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

struct node* deleteNode(struct node *root, int key)
{
	if(root == NULL)
		return NULL;
	
	if(root->key == key)
	{		
		if(root->left == NULL && root->right == NULL)
		{
			free(root);
			root = NULL;
			return root;
		}
		
		else if(root->right == NULL)
		{
			temp = ROOT;
			while(temp->left)
			{
				if(temp->left->key == key)
				{
					par = temp;
					par->left = root->left;
					free(root);
					root = NULL;
					return ROOT;
				}
				else if(temp->right->key == key)
				{
					par = temp;
					par->right = root->left;
					free(root);
					root = NULL;
					return ROOT;
				}
				temp = temp->left;
			}
		}
		
		else if(root->left == NULL)
		{
			temp = ROOT;
			while(temp->left)
			{
				if(temp->left->key == key)
				{
					par = temp;
					par->left = root->right;
					free(root);
					root = NULL;
					return ROOT;
				}
				else if(temp->right->key == key)
				{
					par = temp;
					par->right = root->right;
					free(root);
					root = NULL;
					return ROOT;
				}
				temp = temp->left;
			}
		}
			
		else if(root->left != NULL && root->right != NULL)
		{
			temp = root;
			
			while(temp->left)
			{
				temp = temp->left;
			}
			root->key = temp->key;
			root->left = NULL;
			free(temp);
			temp = NULL;
			return ROOT;
		}
	}	
	deleteNode(root->left, key);
	deleteNode(root->right, key);
}

void searchNode(struct node *root, int key)
{
	if(root != NULL)
	{
		if(root->key == key)
			boolVar = 1;
		searchNode(root->left, key);
		searchNode(root->right, key);
	}
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
				
				if(boolVar)
					printf("Node with %d is found \n", key);
				else
					printf("Node with %d is not found \n",key);
				boolVar = 0;
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
