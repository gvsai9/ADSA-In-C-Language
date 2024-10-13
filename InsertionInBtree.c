// import needed packages
#include <stdio.h> 
#include <stdlib.h>

//define max and min
#define max 3
#define min 2

void insert(int);
//create a structure for a node in Btree
struct btree{
	int data[max+1]; //to store elements in a node
	struct btree *linkers[max+1]; //to point other nodes(ie:-childs)
	int counter; //to keep track number of elements in the node 
};
void traversal(struct btree*);
//inserting value
void insert_val(int data,int pos,struct btree *node,struct btree *child)
{
	int j = node->counter;
	while(j>pos){
		node->data[j+1]=node->data[j];
		node->linkers[j+1]=node->linkers[j];
		j--;
	}
	node->data[j+1]=data;
	node->linkers[j+1]=child;
	node->counter++;
	
}
//split node function
void split_node(int data,int *val,int pos,struct btree *node,struct btree *child,struct btree **newnode){
	int median,j;
	if(pos>min){
		median = min+1;
	}
	else{
		median = min;
	}
	*newnode = (struct btree*)malloc(sizeof(struct btree));
	j= median +1;
	while(j<=max){
		(*newnode)->data[j-median]=node->data[j];
		(*newnode)->linkers[j-median]=node->linkers[j];
		j++;
	}
	node->counter=median;
	(*newnode)->counter = max-median;
	if(pos<=min){
		insert_val(data,pos,node,child);
	}
	else{
		insert_val(data,pos-median,*newnode,child);
	}
	*val = node->data[node->counter];
	(*newnode)->linkers[0]=node->linkers[node->counter];
	node->counter--;
}
//create a root node and initalise to NULL
struct btree *root = NULL;

//function to create a new node if root is null or existing node is full
struct btree *create(int data,struct btree *child){
	struct btree *newNode = (struct btree*)malloc(sizeof(struct btree));
	newNode->data[1]=data;
	newNode->linkers[0]=newNode;
	newNode->linkers[1]=child;
	newNode->counter=1;
	return newNode;
}

//main operation for insertion
void insert(int data){ // as it do not return any thing so its return type is void in this program
	int i; //to store data
	int flag; // indicator to tell if there is need to create a new node or add data to existing node
	struct btree *child; // child is pointing a memeory block in RAM that is allocated for user defined btree data type
	flag = nodePosition(data,&i,root,&child);//----------
	if(flag){
		root = create(i,child);
	}
}
 // function that returns flag value and node postion
 int nodePosition(int data,int *val,struct btree *root,struct btree **child){ // val holds the memory of i and child in parameters
                                                                             // is a pointer which points other pointer of data type btree hence there are two **
 
 	int position; // holds the value of where the element should be inserted for a existing node 
 	
 	//if root is empty
 	if(!root){
 		*val = data; // val pointer takes data variable memeory so , i variable gets the value data(ie;i holds data value in insert function
		*child=NULL; // it makes the memory location pointed by it to NULL so outside function the pointer variable "child" becomes null so it removes child in memory		
		return 1;//to create a new node
	 }
	 //if root is not empty fix postion.
	 if(data<root->data[1]){// if data less than 1st index number then its should be 0 
	 	position = 0;
	 }
	 else{					//if data not less than 1st index number then its index should be b/w last and 1st so fin it
	 	for(position = root->counter;(data<root->data[position]&&position>1);position--); // start to check from last postion 
		 if(data == root->data[position]){
		 	printf("Duplicates are prohibited");  // to check if given data already exist or not
		 	return 0; // dosent create new node for given data
		 }
		 //after fixing posittion at current node.check is this leaf node or not
		 if(nodePosition(data,val,root->linkers[position],child)){	//recursively travels to find leaf node and position in leaf
		 	if(root->counter<max){
		 		 insert_val(*val, position, root, *child);         //insertion function to insert value in that node..
			 }	
		 	else{		//if leaf node is to be splitted
		 		split_node(*val, val, position,root, *child, child);
			 }
		 		
	}
	 }
	//disply
	void traversal(struct btree *node) {
    int i;
  	if (node) {
    for (i = 0; i <node->counter ; i++) {
      traversal(node->linkers[i]);
      printf("%d ", node->data[i + 1]);
    }
    traversal(node->linkers[i]);
  }
}
 
 	
 }
 void main(){
 	insert(10);
 	insert(4);
 	insert(23);
 	traversal(root);
 //	return 0;
 }
