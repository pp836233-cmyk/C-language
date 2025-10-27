#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *left, *right;
};

struct node* createNode(int value) {
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data =value;
	newNode->left =newNode -> right= NULL;
	return newNode;
}

struct node* insert(struct node* root, int value) {
	if(root ==NULL)
	   return createNode(value);
	   
	if(value < root->data )
	   root->left=insert(root->left, value);
	else if (value > root -> data)
	     root->right = insert (root->right, value);
	     
	return root;
}

void inorder(struct node* root) {
	if (root !=NULL){
		inorder(root->left);
		printf("%d", root->data );
		inorder(root->right);
	}
}
void preorder(struct node* root){
	if (root != NULL) {
		printf("%d",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(struct node* root){
	if (root !=NULL){
		postorder(root->left);
		postorder(root->right);
		printf("%d", root->data );
	}
}
int main() {
	struct node* root =NULL;
	int choice, value;
	
	while (1) {
		printf ("\n--- Binary Search Tree Menu ---\n");
		printf("1. Insert\n");
	    printf("2.Inorder Traversal\n");
	    printf("3.preorder Traversal\n");
	    printf("4.Postorder Traversal\n");
	    printf("5. Exit\n");
	    printf("Enter your choice:");
	    scanf("%d", &choice);
	switch (choice) {
		case 1:
			printf("Enter value to insert:");
			scanf("%d", &value);
			root =insert (root, value);
			printf("%d inserted into BST.\n",value );
			break;
		case 2:
			printf("Inorder Traversal:");
			inorder (root);
			printf("\n");
			break;
		case 3:
			printf("Preorder Tranversal:");
			preorder (root);
			printf ("\n");
			break;
		case 4:
			printf("Postorder Traversal");
			postorder(root);
			printf("\n");
			break;
		case 5:
			printf("Exiting program. Goodbye!\n");
			exit(0);
		default:
			printf("Invalid choice! Try again.\n");
	}
 } 
   return 0;
}