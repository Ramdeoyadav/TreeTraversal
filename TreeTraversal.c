#include<stdio.h>
//void create();
void Inorder();
void Preorder();
void Postorder();
void exit();
struct node
{
	int data;
	struct node *left, *right;
};
int x,choice;
struct node *newnode,*root;
struct node *create();
int main() // main function, code will start executing from here
{	
	while (1)
	{
		system("color A");
		printf("\n----------------------------------------------------------------------------------\n\n");
		printf(" *************************  TREE TRAVERSAL OPERATION BY  **************************\n");
		printf("                             R    A    M    D    E   O                            \n");
		printf("----------------------------------------------------------------------------------\n");
		printf("   1.CREATE\n");
		printf("   2.INORDER\n");
		printf("   3.PREORDER\n");
		printf("   4.POSTORDER\n");
		printf("   0.EXIT\n");
		printf("ENTER YOUR CHOICE: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				create();
				break;
			case 2:
				Inorder(root);
				break;
			case 3:
				Preorder(root);
				break;
			case 4:
				Postorder(root);
				break;
			case 0:
				exit(1);
				break;
			default:
				printf("PRESS 0 TO EXIT");
				break;
		}		
	}
	return 0;
}
struct node *create()
{
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("ENTER DATA( ENTER -1 EXIT NODE):\n");
	scanf("%d",&x);
	if(x==-1)
	{
		return 0;
	}
	newnode->data=x;
	printf("ENTER LEFT CHILD OF %d \n",x);
	newnode->left=create();
	printf("ENTER RIGHT CHILD OF %d \n",x);
	newnode->right=create();
	return newnode;
	Inorder();
	Preorder();
	Postorder();
}
void Inorder(struct node *root)
{
	if(root==0)
	{
		return ;
	}
	else
	{
		Inorder(root->left);
		printf("%d",root->data);
		Inorder(root->right);
	}
}
void Preorder(struct node *root)
{
	if(root==0)
	{
		return ;
	}
	else
	{
		printf("%d",root->data);
		Preorder(root->left);
		Preorder(root->right);
	}
}
void Postorder(struct node *root)
{
	if(root==0)
	{
		return ;
	}
	else
	{
		Postorder(root->left);
		Postorder(root->right);
		printf("%d",root->data);
	}
}
