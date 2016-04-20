#include<stdio.h>
#include<stdlib.h>

struct node{
	struct node *lchild;
	int info;
	struct node *rchild;
};

struct node *root=NULL;
struct node *insert(struct node *root,int);
void inorder(struct node *root);

main()
{
	int choice ,key;
	while(1)
	{
		printf("\nENTER\n1.to insert\n2.to dispaly\n3.to exit\n");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				printf("\nenter the value to be inserted\n");
				scanf("%d",&key);
				root=insert(root,key);
				break;
			case 2:
				inorder(root);
				break;
			case 3:
				exit(1);
			default :
				printf("\n Invalid choice\n");
		}
	}
}

struct node *insert(struct node *root,int k)
{
	if(root==NULL)
	{
		root=(struct node *)malloc(sizeof(struct node));
		root->info=k;
		root->lchild=root->rchild=NULL;
		return root;
	}
	else if(k<root->info)
	   root->lchild=insert(root->lchild,k);
	else if(k>root->info)
	   root->rchild=insert(root->rchild,k);
	  else
	    printf("\n duplicate elements not allowed\n");
	    return root;
}

void inorder(struct node *root)
{
	if(root!=NULL)
	{
		inorder(root->lchild);
		  printf("%d\t",root->info);
		inorder(root->rchild);
	}
}
