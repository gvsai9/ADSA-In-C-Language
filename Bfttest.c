#include<stdio.h>
#include <stdlib.h>
#define max 100
int adjMatrix[max][max];
int queue[max];
int front =0;
int rear =-1;
int visted[max]={ 0 };
int numberOfVertices =5;
void addEdge(int node1,int node2)
{
	adjMatrix[node1][node2]=1;
	adjMatrix[node2][node1]=1;
}
void enqueue(int data)
{
	queue[++rear]=data;
}
int dequeue()
{
	return queue[front++];
}
void bfs(int node)
{
	enqueue(node);
	while(front<=rear){
		visted[node]=1;
		int i;
		for(i =0;i<numberOfVertices;i++){
			if(adjMatrix[node][i]==1 && visted[i]==0){
				enqueue(i);
				visted[i]=1;
			}
		}
		printf("-%d-",dequeue());
		node = queue[front];
		
	}
}
int main()
{	
	addEdge(0,1);
	addEdge(0,2);
	addEdge(1,2);
	addEdge(1,3);
	addEdge(2,4);
	addEdge(3,4);
	bfs(0);
	return 0;
		
}
