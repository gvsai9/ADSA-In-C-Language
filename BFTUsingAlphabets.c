// include needed packages
#include<stdio.h>
#include <stdlib.h>
#define max 100 	//decale max using preprocessing directive
int adjMatrix[max][max];	//it adjacent matrix which represent connections between nodes using 0 and 1
int queue[max];	//to add unvisited neighbours
int front =0;	//for
int rear =-1;	//queue
//visited[i] = 0 means ith node is unvisited visited[i]=1 means ith node is visted
int visted[max]={ 0 };	//initally all are unvisited(0)	
int numberOfVertices;	//to keep track of number of nodes/vertices mainly usefull in display of traversals
char elements[max];	//optianal -- element[i] gives th node name
//function to create edge between node1 and node2
void addEdge(int node1,int node2)	
{
	adjMatrix[node1][node2]=1;
	adjMatrix[node2][node1]=1;
}
//to add element into queue
void enqueue(int data)
{
	queue[++rear]=data;
}
//to remove elements from queue
int dequeue()
{
	return queue[front++];
}
//main function
void bfs(int node)
{
	enqueue(node);	//always add your starting node
	while(front<=rear){
		visted[node]=1;	//mark starting node as visted
		int i;
		for(i =0;i<numberOfVertices;i++){		//search nodes from 0th index to lst index(numberOfVertices) that have edge with current node
			if(adjMatrix[node][i]==1 && visted[i]==0){	//check even if the ith node have edge with current name is unvisited too
				enqueue(i);		//add ith node having edge and unvisited to queue
				visted[i]=1;	//mark it as visited so it will node be enqueued again
			}
		}
		printf("-%c-",elements[dequeue()]);	//after adding neighbours of current node dequeue current node and display
		node = queue[front];	//after dequeue update current node 
		
	}
}
int main()
{   printf("\nenter number of vertices you needed in your graph\n----");
	scanf("%d",&numberOfVertices);
	int i;
	for(i=0;i<numberOfVertices;i++){
		printf("\nenter character for node representing %d number\n---",i);
		scanf(" %c",&elements[i]);	
	}
	addEdge(0,1);
	addEdge(0,2);
	addEdge(1,2);
	addEdge(1,3);
	addEdge(2,4);
	addEdge(3,4);
	bfs(0);
	return 0;
		
}
