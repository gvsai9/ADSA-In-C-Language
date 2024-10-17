//include needed libraries
#include <stdio.h>
#include <stdlib.h>
// create a structure 
struct node
{
	int data;		//it consists of value
	int height;		//it is used to store height of the particular node
	struct node *left;		//pointer that points right child of data type struct node
	struct node *right;		//pointer that points right child of data type struct node
};
//function that is used to fin maxiumum of given two values
int max(int a,int b)
{
	return (a>b)?a:b;
}
//function that creates a fresh node whwn needed to be added into tree
struct node *create(int data)
{
	struct node *newnode = (struct node*)malloc(sizeof(struct node));	//create a variable of data type struct node to set all data members
	newnode->data = data;	//to set data
	newnode->height =1;		//height is 1 as it is leaf node
	newnode->left = NULL;	//left and right pointers 
	newnode->right= NULL;	//now points NULL as there  will no child to newly created node
	return (newnode); 	//return this node	
}
//function that returns height for a given node
int getHeight(struct node *current)	//height points out struct node address
{
	if(current == NULL)	//if that node dosent exist
	{
		return 0;
		}
	else{
		return current->height;	
	}	
}
//right rotate function
struct node *rightRotate(struct node *unbalanced_node)	//unbalanced_node is the one that violated balancefactor
{
	struct node *x = unbalanced_node->left;
	struct node *y = x->right;
	x->right = unbalanced_node;
	unbalanced_node->left=y;
	unbalanced_node->height = 1 + max(getHeight(unbalanced_node->left),getHeight(unbalanced_node->right));
	x->height = 1 + max(getHeight(x->left),getHeight(x->right));
	return x;
}
//left rotate function
struct node *leftRotate(struct node *unbalanced_node)
{
	struct node *x = unbalanced_node->right;
	struct node *y = x->left;
	x->left = unbalanced_node;
	unbalanced_node->right=y;
	unbalanced_node->height = 1 + max(getHeight(unbalanced_node->left),getHeight(unbalanced_node->right));
	x->height = 1 + max(getHeight(x->left),getHeight(x->right));
	return x;

}
//function that returns balance factor for a given node
int getBalanceFactor(struct node *current_node)
{
	if(current_node == NULL)
	{
		return 0;
	}
	else{
		return (getHeight(current_node->left)-getHeight(current_node->right));
	}
}
//function returns given value inta a given node in parameters
struct node *insert(struct node *current_node,int data)
{
	if(current_node==NULL){
		return(create(data));
	}
	if(data<current_node->data){
		current_node->left=insert(current_node->left,data);
	}
	else if(data>current_node->data){
		current_node->right=insert(current_node->right,data);
	}
	else{
		return current_node;
	}
	
	//updates height of curent node after making changes to its successors
	current_node->height= 1 + max(getHeight(current_node->left),getHeight(current_node->right));
	
	//after updating height check for balance factor
	int balance_factor = getBalanceFactor(current_node);
	
	//if they are unbalanced , balance them 
	if(balance_factor>1 && data<current_node->left->data) //right rotate
	{
		return rightRotate(current_node);	//after rotataion return new parent of balanced sub tree to current node
	}
	if(balance_factor<-1 && data>current_node->right->data){
		return leftRotate(current_node);
	}
	if(balance_factor>1 && data>current_node->left->data ){
		current_node->left = leftRotate(current_node->left);
		return rightRotate(current_node);
	}
	if(balance_factor<-1 && data<current_node->right->data ){
		current_node->right = leftRotate(current_node->right);
		return leftRotate(current_node);
	}
	else{
		return current_node;
	}
	
}
//function to display
void display(struct node *root)
{ 
	if(root!=NULL){
	display(root->left);
	printf("%d	",root->data);
	display(root->right);
}
}

int main(){
	struct node *root = NULL;
	int x,i;
	for(i=0;i<6;i++){
		scanf("%d",&x);
	root = insert(root,x);
}
	display(root);
	return 0;
}
